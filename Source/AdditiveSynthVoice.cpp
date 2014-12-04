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
    double phaseIncrement = 2.0 * double_Pi / (float)waveTableLength;
    double phase = 0.0;
    for (int i = 0; i < waveTableLength; i++) {
        waveTable[i] = sin(phase);
        phase += phaseIncrement;
    }
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

    // precompute normalization of partials
    minPartialLevel = maxPartialLevel = 0.0;
    float stretch = localParameters[STRETCH] + localParameters[STRETCH_FINE];
    for (int i = 0; i < numPartials; i++)
    {
        if (localParameters[PartialToParamMapping[i]] < minPartialLevel)
            minPartialLevel = localParameters[PartialToParamMapping[i]];
        if (localParameters[PartialToParamMapping[i]] > maxPartialLevel)
            maxPartialLevel = localParameters[PartialToParamMapping[i]];
        
        partialLevels[i] = scaleRange(localParameters[PartialToParamMapping[i]], minPartialLevel, maxPartialLevel, 0.0, 1.0);
        partialFrequencies[i] = freq * ((float)i + 1.0);
        partialFrequencies[i] += partialFrequencies[i] * stretch;
        stretch += stretch;
        stretchedIndices[i] = 0.0;
    }
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
            const float masterAmplitude = amplitude / numPartials;
            float stretchEnvAmt = 0.0;

            for (int i = 0; i < numPartials; i++)
            {
                if (localParameters[PartialToParamMapping[i]] != 0.0)
                {
                    const float stretchedFreq = (partialFrequencies[i] + (partialFrequencies[i] * stretchEnvAmt));
                    const float stretchedIncrement = frqTI * stretchedFreq;
                    
                    if (stretchedFreq < nyquist)
                    {

                        currentSample += waveTable[stretchedIndices[i]] * partialLevels[i];
                        stretchedIndices[i] = (int)(stretchedIndices[i] + stretchedIncrement) % waveTableLength;
                    }
                }
                stretchEnvAmt += stretchEnvAmtInc * amplitude;
            }
            
            float calculatedSample = currentSample * masterAmplitude;
            for (int channelNum = outputBuffer.getNumChannels(); --channelNum >= 0;)
                outputBuffer.addSample(channelNum, startSample, calculatedSample);

            ++startSample;
        }
    }
}


float AdditiveSynthVoice::getAmplitude()
{
    const float sampleRate = (float)getSampleRate();
    const float attack = localParameters[ATTACK] * sampleRate;
    const float decay = localParameters[DECAY] * sampleRate;
    const float sustainLevel = localParameters[SUSTAIN];
    const float release = localParameters[RELEASE] * sampleRate;

    if (isKeyDown())
    {
        if (samplesSinceTrigger < attack)
        {
            envLevel = samplesSinceTrigger * velocity / attack;
        }
        else if (samplesSinceTrigger < attack + decay)
        {
            const float amp = ((sustainLevel * velocity) - velocity) / decay;
            envLevel = ((samplesSinceTrigger - attack) * amp) + velocity;
        }
    }
    else if (envLevel > 0.0 && samplesSinceTrigger <= release)
    {
        // something wrong with this calculation! It is producing a negative level.
        const float amp = 0 - releaseEnvLevel / release;
        envLevel = (samplesSinceTrigger * amp) + releaseEnvLevel;
    }
    else
    {
        clearCurrentNote();
        envLevel = 0.0;
        releaseEnvLevel = 0.0;
    }
    ++samplesSinceTrigger;
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

