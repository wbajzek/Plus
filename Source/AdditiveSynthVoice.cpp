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

float AdditiveSynthVoice::getParameter(int index)
{
    return localParameters[index];
}

bool AdditiveSynthVoice::canPlaySound (SynthesiserSound* sound)
{
    return true;
}

void AdditiveSynthVoice::startNote (const int midiNoteNumber, const float midiVelocity, SynthesiserSound* /*sound*/, const int /*currentPitchWheelPosition*/)
{
    freq = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    velocity = midiVelocity;
    envLevel = 0.001;
    samplesSinceTrigger = 0;
}

void AdditiveSynthVoice::stopNote (float velocity, const bool allowTailOff)
{
}

void AdditiveSynthVoice::pitchWheelMoved (const int /*newValue*/)
{
    
}

void AdditiveSynthVoice::controllerMoved (const int /*controllerNumber*/, const int /*newValue*/)
{
    
}

void AdditiveSynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (envLevel > 0.000)
    {
        while (--numSamples >= 0)
        {
            float currentSample = 0.0;
            const float amplitude = getAmplitude();
            
            for (int i = 0; i < numPartials; i++)
            {
                double cyclesPerSample = (freq * (float)(i+1)) / getSampleRate() +
                ( i * localParameters[STRETCH] / 10 ) +
                ( i * (localParameters[STRETCH_ENV_AMT] * amplitude));
                double angleDelta = cyclesPerSample * 2.0 * double_Pi;
                
                if (angleDelta != 0.0)
                {
                    currentSample += (float) ((sin (currentAngles[i]) *
                                               (localParameters[PartialToParamMapping[i]] * amplitude * localParameters[PARTIAL_LEVEL_ENV_AMT])));
                    currentAngles[i] += angleDelta;
                }
            }
            
            for (int channelNum = outputBuffer.getNumChannels(); --channelNum >= 0;)
                outputBuffer.addSample(channelNum, startSample, (currentSample * amplitude / numPartials));
            
            ++startSample;
        }
    }
}

float AdditiveSynthVoice::getAmplitude()
{
    const float sampleRate = (float)getSampleRate();
    const float attack = localParameters[ATTACK] * sampleRate;
    const float decay = attack + (localParameters[DECAY] * sampleRate);
    const float sustainLevel = localParameters[SUSTAIN];
    const float release = localParameters[RELEASE] * sampleRate;
    
    if (isKeyDown())
    {
        if (samplesSinceTrigger < attack)
            envLevel = envLevel + velocity / attack;
        else if (samplesSinceTrigger < attack + decay) {
            if (envLevel > sustainLevel * velocity)
                envLevel = envLevel - velocity / decay;
        }
        else
        {
            envLevel = sustainLevel * velocity;
        }
    }
    else if (envLevel > 0.0)
        envLevel = envLevel - velocity / release;
    else
        envLevel = 0.0;
    
    ++samplesSinceTrigger;
    return envLevel;
}


bool AdditiveSynthVoice::isVoiceActive() const
{
    if (envLevel > 0.0)
        return true;
    else
        return false;
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
