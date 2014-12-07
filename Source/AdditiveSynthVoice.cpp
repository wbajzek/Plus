//
//  AdditiveSynthVoice.cpp
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#include "AdditiveSynth.h"

AdditiveSynthVoice::AdditiveSynthVoice(float* parameters)
{
    localParameters = parameters;
}

AdditiveSynthVoice::~AdditiveSynthVoice()
{
}

bool AdditiveSynthVoice::canPlaySound (SynthesiserSound* sound)
{
    return true;
}

void AdditiveSynthVoice::startNote (const int midiNoteNumber, const float midiVelocity, SynthesiserSound* /*sound*/, const int currentPitchWheelPosition)
{
    noteNumber = midiNoteNumber;
    freq = calculateFrequency(currentPitchWheelPosition);
    velocity = midiVelocity;
    envLevel = 0.001;
    releaseEnvLevel = envLevel;
    samplesSinceTrigger = 0;

    attack = localParameters[ATTACK] * sampleRate;
    decay = localParameters[DECAY] * sampleRate;
    sustainLevel = localParameters[SUSTAIN] * velocity;
    release = localParameters[RELEASE] * sampleRate;
    
    // precompute normalization of partials
    minPartialLevel = maxPartialLevel = 0.0;
    for (int i = 0; i < numPartials; i++)
    {
        if (localParameters[PartialLevelToParamMapping[i]] < minPartialLevel)
            minPartialLevel = localParameters[PartialLevelToParamMapping[i]];
        if (localParameters[PartialLevelToParamMapping[i]] > maxPartialLevel)
            maxPartialLevel = localParameters[PartialLevelToParamMapping[i]];
        
        partialLevels[i] = scaleRange(localParameters[PartialLevelToParamMapping[i]], minPartialLevel, maxPartialLevel, 0.0, 1.0);

        stretchedIndices[i] = 0.0;
    }
    
    envelopeState = ATTACK_STATE;
}

void AdditiveSynthVoice::stopNote (float velocity, const bool allowTailOff)
{
    samplesSinceTrigger = 0;
    releaseEnvLevel = envLevel;
    clearCurrentNote();
}

float AdditiveSynthVoice::calculateFrequency(int currentPitchWheelPosition)
{
    float pbCents = ( (float)currentPitchWheelPosition / 16383.0) * (400.0) + -200.0;
    return MidiMessage::getMidiNoteInHertz(noteNumber) * pow(2, pbCents/1200);
}

void AdditiveSynthVoice::pitchWheelMoved (const int currentPitchWheelPosition)
{
    freq = calculateFrequency(currentPitchWheelPosition);
}

void AdditiveSynthVoice::controllerMoved (const int /*controllerNumber*/, const int /*newValue*/)
{

}

void AdditiveSynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (envLevel > 0.000)
    {
        const float stretchEnvAmtInc = localParameters[STRETCH_ENV_AMT] + localParameters[STRETCH_ENV_AMT_FINE];
        
        while (--numSamples >= 0)
        {
            float currentSample = 0.0;
            const float amplitude = getAmplitude();
            const float masterAmplitude = amplitude / numPartials * 4; // * 4 fudge factor to make the synth reasonably louder
            float stretchEnvAmt = stretchEnvAmtInc * amplitude;
            float stretch = localParameters[STRETCH] + localParameters[STRETCH_FINE];

            for (int i = 0; i < numPartials; i++)
            {
                if (localParameters[PartialLevelToParamMapping[i]] > 0.0)
                {
                    float partialFreq = freq;
                    if (i > 0)
                    {
                        partialFreq += ((freq + (freq * localParameters[PartialTuneToParamMapping[i]])) * ((float)i + stretch));
                        if (i > 0)
                            partialFreq += partialFreq * stretch * stretchEnvAmt;
                    }
                    if (20 < partialFreq && partialFreq < nyquist)
                    {
                        // this '16' business is converting floating point to fixed for the sake of performance.
                        // and oh boy, does it improve performance.
                        const long increment = (long)(frqTI * partialFreq) << 16;

                        currentSample += waveTable[(stretchedIndices[i]+0x8000) >> 16] * localParameters[PartialLevelToParamMapping[i]];

                        stretchedIndices[i] = stretchedIndices[i] + increment & ((waveTableLength << 16) - 1);
                    }
                }
                stretch += stretch;
            }
            
            float calculatedSample = currentSample * masterAmplitude;
            
            for (int channelNum = outputBuffer.getNumChannels(); --channelNum >= 0;)
                outputBuffer.addSample(channelNum, startSample, calculatedSample);

            ++startSample;
            ++samplesSinceTrigger;
        }
    }
}

float getSegmentCoefficient(float startLevel, float endLevel, int durationInSamples) {
    // add a tiny fudge factor when calculating the end level because it doesn't work
    // when it's exactly 0.0
    return (log((endLevel) + 0.0001) - log(startLevel)) / durationInSamples;
}

float AdditiveSynthVoice::getAmplitude()
{
    bool keyIsDown = isKeyDown();
    switch (envelopeState) {
        case ATTACK_STATE:
            if (samplesSinceTrigger == 0)
                envIncrement = velocity / attack;
            else if (samplesSinceTrigger > attack)
            {
                envelopeState = DECAY_STATE;
                coefficient = getSegmentCoefficient(envLevel, sustainLevel * velocity, decay);
            }

            if (attack == 0.0)
            {
                envLevel = velocity;
                envIncrement = 0.0;
                envelopeState = DECAY_STATE;
            }
            else
                envLevel += envIncrement;

            if (!keyIsDown)
            {
                envelopeState = RELEASE_STATE;
                coefficient = getSegmentCoefficient(envLevel, 0.0, release);
            }
            break;
        case DECAY_STATE:
            if (samplesSinceTrigger > attack + decay)
                envelopeState = SUSTAIN_STATE;
            else if (!keyIsDown)
            {
                envelopeState = RELEASE_STATE;
                coefficient = getSegmentCoefficient(envLevel, 0.0, release);
            }
            else
                envLevel += coefficient * envLevel;
            break;
        case SUSTAIN_STATE:
            envLevel = sustainLevel * velocity;
            if (!keyIsDown)
            {
                envelopeState = RELEASE_STATE;
                coefficient = getSegmentCoefficient(envLevel, 0.0, release);
            }
            break;
        case RELEASE_STATE:
            envLevel += coefficient * envLevel;
            if (envLevel < 0.001)
            {
                envLevel = 0.0;
            }
            break;
    }
    return envLevel;
}

void AdditiveSynthVoice::aftertouchChanged (int newAftertouchValue)
{

}

void AdditiveSynthVoice::setCurrentPlaybackSampleRate (double newRate)
{
    sampleRate = newRate;
    nyquist = sampleRate/2.0;
    frqTI = waveTableLength/sampleRate;
}

bool AdditiveSynthVoice::isPlayingChannel (int midiChannel) const
{
    return true;
}

bool AdditiveSynthVoice::isVoiceActive() const
{
    return envLevel > 0.0;
}

