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
    level = 0.8;
    envLevel = 0.0;
    samplesSinceTrigger = 0;
}

void AdditiveSynthVoice::stopNote (float velocity, const bool allowTailOff)
{
    envLevel = 0;
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
    const float sampleRate = (float)getSampleRate();
    const float attack = getParameter(0) * sampleRate;
    const float decay = attack + (getParameter(1) * sampleRate);
    const float sustainLevel = getParameter(2);
    const float release = getParameter(3) * sampleRate;
    
    if (isKeyDown())
    {
        if (samplesSinceTrigger < attack)
            envLevel = envLevel + (1.0 / attack);
        else if (samplesSinceTrigger < attack + decay) {
            if (envLevel > sustainLevel)
                envLevel = envLevel - (1.0/decay);
        }
        else
        {
            envLevel = sustainLevel;
        }
    }
    else if (envLevel > 0.0)
        envLevel = sustainLevel - level / release;
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
