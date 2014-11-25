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
    return 0.0f;
}

bool AdditiveSynthVoice::canPlaySound (SynthesiserSound* sound)
{
    return true;
}

void AdditiveSynthVoice::startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int /*currentPitchWheelPosition*/)
{
    freq = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    level = 0.8;
//    level = velocity/127;
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
                const float currentSample = (float) ((sin (currentAngles[i]) * partialLevels[i]) / (float)numPartials) * level;
                
                for (int channelNum = outputBuffer.getNumChannels(); --channelNum >= 0;)
                    outputBuffer.addSample(channelNum, startSampleForPartial, currentSample);
                
                currentAngles[i] += angleDelta;
                ++startSampleForPartial;
            }
        }
    }
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
