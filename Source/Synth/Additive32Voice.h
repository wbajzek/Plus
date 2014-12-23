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
    struct PartialEnvelope {
        Envelope::EnvelopeState state;
        Amplitude amplitude;
        float coefficient;
        float increment;
        unsigned int attackSamples;
        unsigned int decaySamples;
        unsigned int releaseSamples;
        Amplitude sustainLevel;
    };

    void setAdsrs(Adsr newAdsr[32])
    {
        for (int i = 0; i < 32; ++i)
        {
            envelopes[i].attackSamples = newAdsr[i].attack * sampleRate;
            envelopes[i].decaySamples = newAdsr[i].decay * sampleRate;
            envelopes[i].releaseSamples = newAdsr[i].release * sampleRate;
            envelopes[i].sustainLevel = newAdsr[i].sustainLevel;
            envelopes[i].releaseSamples = newAdsr[i].release * sampleRate;
        }
    }

    void setSampleRate(float newSampleRate)
    {
        sampleRate = newSampleRate;
        nyquist = sampleRate * 0.5;
        frqTI = waveTableLength/sampleRate;
    }
    
    void setFrequencies(Frequency newFrequencies[32])
    {
        for (int i = 0; i < 32; ++i)
        {
            frequencies[i] = newFrequencies[i];
            increments[i] = (long)(frqTI * frequencies[i]) << 16;
        }
    }
    
    void trigger(Amplitude newVelocity)
    {
        velocity = newVelocity;
        for (int i = 0; i < 32; ++i)
        {
            envelopes[i].state = Envelope::ATTACK_STATE;
            envelopes[i].amplitude = 0.0;
        }
        samplesSinceTrigger = 0;
    }
    
    void tick(bool keyIsDown)
    {
        for (int i = 0; i < 32; ++i)
            if (amplitudes[i] > 0.0 && envelopes[i].state != Envelope::DEAD_STATE && frequencies[i] < nyquist)
                envelopeTick(i, keyIsDown);
                
        for (int i = 0; i < 32; ++i)
            if (amplitudes[i] > 0.0 && envelopes[i].state != Envelope::DEAD_STATE && frequencies[i] < nyquist)
                samples[i] = sineWaveTable[((indices[i]+0x8000) >> 16)] * envelopes[i].amplitude * velocity;
            else
                samples[i] = 0.0;
        
        for (int i = 0; i < 32; ++i)
            if (amplitudes[i] > 0.0 && envelopes[i].state != Envelope::DEAD_STATE && frequencies[i] < nyquist)
                indices[i] = indices[i] + increments[i] & ((waveTableLength << 16) - 1);

        ++samplesSinceTrigger;
    }
    
    void envelopeTick(int partial, bool keyIsDown)
    {
        switch (envelopes[partial].state)
        {
            case Envelope::ATTACK_STATE:
                if (envelopes[partial].attackSamples == 0)
                {
                    envelopes[partial].amplitude = 1.0;
                    envelopes[partial].increment = 0.0;
                    envelopes[partial].state = Envelope::DECAY_STATE;
                }
                else
                {
                    if (samplesSinceTrigger == 0)
                        envelopes[partial].increment = 1.0 / envelopes[partial].attackSamples;
                    else if (samplesSinceTrigger > envelopes[partial].attackSamples)
                    {
                        envelopes[partial].state = Envelope::DECAY_STATE;
                        envelopes[partial].coefficient = getSegmentCoefficient(envelopes[partial].amplitude, envelopes[partial].sustainLevel, envelopes[partial].decaySamples);
                    }
                    
                    if (!keyIsDown)
                    {
                        envelopes[partial].state = Envelope::RELEASE_STATE;
                        envelopes[partial].coefficient = getSegmentCoefficient(envelopes[partial].amplitude, 0.0, envelopes[partial].releaseSamples);
                    }
                    envelopes[partial].amplitude += envelopes[partial].increment;
                }
                
                break;
            case Envelope::DECAY_STATE:
                if (samplesSinceTrigger > envelopes[partial].attackSamples + envelopes[partial].decaySamples)
                    envelopes[partial].state = Envelope::SUSTAIN_STATE;
                else if (!keyIsDown)
                {
                    envelopes[partial].state = Envelope::RELEASE_STATE;
                    envelopes[partial].coefficient = getSegmentCoefficient(envelopes[partial].amplitude, 0.0, envelopes[partial].releaseSamples);
                }
                else
                    envelopes[partial].amplitude += envelopes[partial].coefficient * envelopes[partial].amplitude;
                break;
            case Envelope::SUSTAIN_STATE:
                if (!keyIsDown)
                {
                    envelopes[partial].state = Envelope::RELEASE_STATE;
                    envelopes[partial].coefficient = getSegmentCoefficient(envelopes[partial].amplitude, 0.0, envelopes[partial].releaseSamples);
                }
                break;
            case Envelope::RELEASE_STATE:
                envelopes[partial].amplitude += envelopes[partial].coefficient * envelopes[partial].amplitude;
                if (envelopes[partial].amplitude < 0.001)
                {
                    envelopes[partial].state = Envelope::DEAD_STATE;
                    envelopes[partial].amplitude = 0.0;
                    // caller will need to clear current note
                }
                break;
            case Envelope::DEAD_STATE:
                break;
        }
    }
    
    bool isActive()
    {
        for (int i = 0; i < 32; ++i)
            if (envelopes[i].amplitude != 0.0)
                return true;
        return false;
    }

    Frequency frequencies[32];
    Amplitude samples[32];
    PartialEnvelope envelopes[32];
    Amplitude amplitudes[32];

private:
    Frequency sampleRate = 0.0;
    Frequency nyquist;
    Amplitude velocity;
    double frqTI = 0.0;
    unsigned long indices[32];
    unsigned int increments[32];
    inline Amplitude getSegmentCoefficient(Amplitude startLevel, Amplitude endLevel, int durationInSamples) const
    {
        // add a tiny fudge factor when calculating because it doesn't work when levels are exactly 0.0
        return (log((endLevel + 0.0001)) - log(startLevel + 0.0001)) / durationInSamples;
    }
    unsigned long samplesSinceTrigger = 0;
};

#endif  // ADDITIVE32VOICE_H_INCLUDED
