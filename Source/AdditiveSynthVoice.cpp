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
    for (int i = 0; i < numPartials; i++)
    {
        if (localParameters[PartialToParamMapping[i]] < minPartialLevel)
            minPartialLevel = localParameters[PartialToParamMapping[i]];
        if (localParameters[PartialToParamMapping[i]] > maxPartialLevel)
            maxPartialLevel = localParameters[PartialToParamMapping[i]];
        
        partialLevels[i] = scaleRange(localParameters[PartialToParamMapping[i]], minPartialLevel, maxPartialLevel, 0.0, 1.0);
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
        const float sampleRate = getSampleRate();
        const float nyquist = sampleRate/2.0;
        const double frqTI = waveTableLength/sampleRate;

        const double stretchInc = localParameters[STRETCH] + localParameters[STRETCH_FINE];
        const double stretchEnvAmtInc = localParameters[STRETCH_ENV_AMT] + localParameters[STRETCH_ENV_AMT_FINE];
        
        while (--numSamples >= 0)
        {
            float currentSample = 0.0;
            const float amplitude = getAmplitude();
            const float masterAmplitude = amplitude / numPartials;
            double stretch = 0.0;
            double stretchEnvAmt = 0.0;

            for (int i = 0; i < numPartials; i++)
            {
                if (localParameters[PartialToParamMapping[i]] != 0.0)
                {
                    const double partialFreq = (freq * (float)(i+1));
                    const double stretchedFreq = (partialFreq + (partialFreq * stretch) + (partialFreq * stretchEnvAmt * amplitude));
                    const double stretchedIncrement = frqTI * stretchedFreq;
                    
                    double partialSample = 0.0;
                    
                    if (stretchedFreq < nyquist)
                    {
                        while (stretchedIndices[i] < 0)
                            stretchedIndices[i] += waveTableLength;
                        
                        partialSample += waveTable[stretchedIndices[i]];

                        if ((stretchedIndices[i] += stretchedIncrement) >= waveTableLength)
                            stretchedIndices[i] -= waveTableLength;
                    }
                    currentSample += partialSample * partialLevels[i];
                }
                stretch += stretchInc;
                stretchEnvAmt += stretchEnvAmtInc;
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
}

bool AdditiveSynthVoice::isPlayingChannel (int midiChannel) const
{
    return true;
}
