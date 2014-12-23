/*
  ==============================================================================

    Additive32Voice.h
    Created: 22 Dec 2014 7:38:54pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef ADDITIVE32VOICE_H_INCLUDED
#define ADDITIVE32VOICE_H_INCLUDED

#include "Synth.h"

class Additive32Voice : public SynthVoice
{
public:

    void setAdsrs(Adsr newAdsr[32])
    {
        for (int i = 0; i < 32; ++i)
            envelopes[i].setAdsr(newAdsr[i]);
    }

    void setSampleRate(float newSampleRate)
    {
        sampleRate = newSampleRate;
        frqTI = waveTableLength/sampleRate;
        for (int i = 0; i < 32; ++i)
            envelopes[i].setSampleRate(newSampleRate);
    }
    
    void setFrequencies(Frequency newFrequencies[32])
    {
        for (int i = 0; i < 32; ++i)
        {
            frequencies[i] = newFrequencies[i];
            increments[i] = (long)(frqTI * frequencies[i]) << 16;
        }
    }
    
    void trigger(Amplitude newVelocity) {
        velocity = newVelocity;
        for (int i = 0; i < 32; ++i)
            envelopes[i].trigger();
    }
    
    void tick(bool keyIsDown)
    {
        for (int i = 0; i < 32; ++i)
        {
            amplitudes[i] = envelopes[i].tick(keyIsDown);
            samples[i] = Oscillator::ValueFromTable(indices[i], SINE_WAVE_TABLE) * amplitudes[i] * velocity;
            indices[i] = indices[i] + increments[i] & ((waveTableLength << 16) - 1);
        }
    }
    
    bool isActive()
    {
        for (int i = 0; i < 32; ++i)
            if (amplitudes[i] > 0.0)
                return true;
        return false;
    }

    Frequency frequencies[32];
    Amplitude amplitudes[32];
    Amplitude samples[32];
    
private:
    Frequency sampleRate = 0.0;
    Amplitude velocity;
    double frqTI = 0.0;
    Envelope envelopes[32];
    int indices[32];
    int increments[32];
};

class Additive32Oscillator
{
public:
private:
};

class Additive32Envelope
{
public:
private:
};

#endif  // ADDITIVE32VOICE_H_INCLUDED
