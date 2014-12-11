/*
  ==============================================================================

    Envelope.h
    Created: 11 Dec 2014 12:17:37pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED



class Envelope
{
public:

    Envelope()
    {        
    }
    
    ~Envelope()
    {
    }
    
    void trigger(float newVelocity)
    {
        velocity = newVelocity;
        envelopeState = ATTACK_STATE;
        samplesSinceTrigger = 0;
    }

    float tick(bool keyIsDown) {
        switch (envelopeState)
        {
            case ATTACK_STATE:
                if (samplesSinceTrigger == 0)
                    envIncrement = velocity / attack;
                else if (samplesSinceTrigger > attack)
                {
                    envelopeState = DECAY_STATE;
                    envCoefficient = getSegmentCoefficient(envLevel, sustainLevel * velocity, decay);
                }
                
                if (attack == 0.0)
                {
                    envLevel = velocity;
                    envIncrement = 0.0;
                    envelopeState = DECAY_STATE;
                }
                else
                    envLevel += envIncrement;
                
                if (!keyIsDown)
                {
                    envelopeState = RELEASE_STATE;
                    envCoefficient = getSegmentCoefficient(envLevel, 0.0, release);
                }
                break;
            case DECAY_STATE:
                if (samplesSinceTrigger > attack + decay)
                    envelopeState = SUSTAIN_STATE;
                else if (!keyIsDown)
                {
                    envelopeState = RELEASE_STATE;
                    envCoefficient = getSegmentCoefficient(envLevel, 0.0, release);
                }
                else
                    envLevel += envCoefficient * envLevel;
                break;
            case SUSTAIN_STATE:
                envLevel = sustainLevel * velocity;
                if (!keyIsDown)
                {
                    envelopeState = RELEASE_STATE;
                    envCoefficient = getSegmentCoefficient(envLevel, 0.0, release);
                }
                break;
            case RELEASE_STATE:
                envLevel += envCoefficient * envLevel;
                if (envLevel < 0.001)
                {
                    envLevel = 0.0;
                    // caller will need to clear current note
                }
                break;
        }
        samplesSinceTrigger++;
        return envLevel;
    }
private:
    
    inline float getSegmentCoefficient(float startLevel, float endLevel, int durationInSamples)
    {
        // add a tiny fudge factor when calculating the end level because it doesn't work
        // when it's exactly 0.0
        return (log((endLevel) + 0.0001) - log(startLevel)) / durationInSamples;
    }
    
    int envelopeState;
    unsigned long samplesSinceTrigger = 0;
    float velocity = 0.0;
    float envLevel = 0.0;
    float envCoefficient = 0.0;
    float envIncrement = 0.0;

    float attack = 0.0;
    float decay = 0.0;
    float sustainLevel = 0.0;
    float release = 0.0;
    
    enum EnvelopeState {
        ATTACK_STATE,
        DECAY_STATE,
        SUSTAIN_STATE,
        RELEASE_STATE
    };
};



#endif  // ENVELOPE_H_INCLUDED
