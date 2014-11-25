//
//  AdditiveSynthVoice.cpp
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#include "AdditiveSynth.h"

const double freq = 110.0;
const int numPartials = 16;
double partialLevels[numPartials];
double currentAngles[numPartials] = { 0.0 };


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
    return 0.0f;
}

bool AdditiveSynthVoice::canPlaySound (SynthesiserSound* sound)
{
    return true;
}

void AdditiveSynthVoice::startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int /*currrentPitchWheelPosition*/)
{
    
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
    for (int i = 0; i < numPartials; i++)
    {
        const double cyclesPerSample = (freq * (float)(i+1)) / getSampleRate();
        const double angleDelta = cyclesPerSample * 2.0 * double_Pi;
        
        if (angleDelta != 0.0)
        {
            
            while (--numSamples >= 0)
            {
                const float currentSample = (float) ((sin (currentAngles[i]) * partialLevels[i]) / (float)numPartials);
                
                for (int channelNum = outputBuffer.getNumChannels(); --channelNum >= 0;)
                    outputBuffer.addSample(channelNum, startSample, currentSample);
                
                currentAngles[i] += angleDelta;
                
                ++startSample;
            }
        }
    }
}


bool AdditiveSynthVoice::isVoiceActive() const
{
    return true;
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
