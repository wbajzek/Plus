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
    double level = 0.8;
    for (int i=0; i < numPartials; i++)
        partialLevels[i]= level = level * 0.8f;
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

void AdditiveSynthVoice::startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int /*currentPitchWheelPosition*/)
{
    freq = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    level = 1.0;
    envLevel = 0.0;
    samplesSinceTrigger = 0;
}

void AdditiveSynthVoice::stopNote (float velocity, const bool allowTailOff)
{
    level = 0.0;
}

void AdditiveSynthVoice::pitchWheelMoved (const int /*newValue*/)
{
    
}

void AdditiveSynthVoice::controllerMoved (const int /*controllerNumber*/, const int /*newValue*/)
{
    
}

void AdditiveSynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    for (int i = 0; i < numPartials; i++)
    {
        double cyclesPerSample = (freq * (float)(i+1)) / getSampleRate();
        double angleDelta = cyclesPerSample * 2.0 * double_Pi;
        int startSampleForPartial = startSample;
        int numSamplesForPartial = numSamples;
        
        if (angleDelta != 0.0 && level > 0.0)
        {
            
            while (--numSamplesForPartial >= 0)
            {
                const float currentSample = (float) ((sin (currentAngles[i]) * getAmplitude(i)));
                
                for (int channelNum = outputBuffer.getNumChannels(); --channelNum >= 0;)
                    outputBuffer.addSample(channelNum, startSampleForPartial, currentSample);
                
                currentAngles[i] += angleDelta;
                ++startSampleForPartial;
            }
        }
    }
}

float AdditiveSynthVoice::getAmplitude(int partial)
{
    const float secondsSinceTrigger = (float)samplesSinceTrigger/(float)getSampleRate() * 1000;
    const float attackSeconds = getParameter(0) * 1000;
    const float decaySeconds = attackSeconds + getParameter(1) * 1000;
    const float sustainLevel = getParameter(2);
    const float releaseSeconds = decaySeconds + getParameter(3) * 1000;
    
    if (isKeyDown())
    {
        if (attackSeconds > secondsSinceTrigger) // attack
            envLevel = level * secondsSinceTrigger / attackSeconds;
        else if (decaySeconds > secondsSinceTrigger) {
            if (envLevel > sustainLevel)
                envLevel = envLevel - level / decaySeconds;
        }
        else
        {
            envLevel = sustainLevel * level;
        }
    }
    else if (envLevel > 0.0)
        envLevel = sustainLevel - level / releaseSeconds;
    else
        envLevel = 0.0;
    
    ++samplesSinceTrigger;
    return partialLevels[partial] * envLevel / (float)numPartials * level;
}


bool AdditiveSynthVoice::isVoiceActive() const
{
    if (level > 0.0)
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
