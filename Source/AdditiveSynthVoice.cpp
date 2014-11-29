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

void AdditiveSynthVoice::startNote (const int midiNoteNumber, const float midiVelocity, SynthesiserSound* /*sound*/, const int currentPitchWheelPosition)
{
    noteNumber = midiNoteNumber;
    freq = calculateFrequency(currentPitchWheelPosition);
    velocity = midiVelocity;
    envLevel = 0.001;
    samplesSinceTrigger = 0;
    
}

void AdditiveSynthVoice::stopNote (float velocity, const bool allowTailOff)
{
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
                    currentSample += (float) (sin (currentAngles[i]) *
                                               (localParameters[PartialToParamMapping[i]] * amplitude));
                    currentAngles[i] += angleDelta;
                }
            }
            
            float calculatedSample = (currentSample * amplitude / numPartials);
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
