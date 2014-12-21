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
    
    void setSampleRate(float newRate)
    {
        sampleRate = newRate;
        convertSecondsToSamples();
    }
    
    // parameters in seconds
    void setAdsr(Seconds newAttack, Seconds newDecay, Amplitude newSustainLevel, Seconds newRelease)
    {
        attack = newAttack;
        decay = newDecay;
        sustainLevel = newSustainLevel;
        release = newRelease;
        convertSecondsToSamples();
    }
    
    // velocity scaled [0,1]
    void trigger(Amplitude newVelocity)
    {
        velocity = newVelocity;
        envelopeState = ATTACK_STATE;
        samplesSinceTrigger = 0;
    }

    void tick(bool keyIsDown) {
        switch (envelopeState)
        {
            case ATTACK_STATE:
                if (samplesSinceTrigger == 0)
                    envIncrement = velocity / attackSamples;
                else if (samplesSinceTrigger > attackSamples)
                {
                    envelopeState = DECAY_STATE;
                    envCoefficient = getSegmentCoefficient(envLevel, sustainLevel * velocity, decaySamples);
                }
                
                if (attackSamples == 0)
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
                    envCoefficient = getSegmentCoefficient(envLevel, 0.0, releaseSamples);
                    jassert(envCoefficient != INFINITY);
                }
                break;
            case DECAY_STATE:
                if (samplesSinceTrigger > attackSamples + decaySamples)
                    envelopeState = SUSTAIN_STATE;
                else if (!keyIsDown)
                {
                    envelopeState = RELEASE_STATE;
                    envCoefficient = getSegmentCoefficient(envLevel, 0.0, releaseSamples);
                    jassert(envCoefficient != INFINITY);
                }
                else
                    envLevel += envCoefficient * envLevel;
                break;
            case SUSTAIN_STATE:
                if (!keyIsDown)
                {
                    envelopeState = RELEASE_STATE;
                    envCoefficient = getSegmentCoefficient(envLevel, 0.0, releaseSamples);
                    jassert(envCoefficient != INFINITY);
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
        if (envLevel > 1.0)
            envLevel = 1.0;
        if (envLevel < 0.0)
            envLevel = 0.0;
        
        samplesSinceTrigger++;
        jassert(envLevel != NAN);
        jassert(envLevel <= 1.0);
        jassert(envLevel >= 0.0);
    }
    
    Amplitude amplitude()
    {
        return envLevel;
    }
    
private:
    
    inline Amplitude getSegmentCoefficient(Amplitude startLevel, Amplitude endLevel, int durationInSamples) const
    {
        // add a tiny fudge factor when calculating because it doesn't work when levels are exactly 0.0
        return (log((endLevel + 0.0001)) - log(startLevel + 0.0001)) / durationInSamples;
    }
    
    void convertSecondsToSamples()
    {
        attackSamples = sampleRate * attack;
        decaySamples = sampleRate * decay;
        releaseSamples = sampleRate * release;
    }
    
    int envelopeState;
    unsigned long samplesSinceTrigger = 0;
    Frequency sampleRate = 0.0;
    Amplitude velocity = 0.0;
    Amplitude envLevel = 0.0;
    float envCoefficient = 0.0;
    float envIncrement = 0.0;

    Seconds attack = 0.0;
    Seconds decay = 0.0;
    Amplitude sustainLevel = 0.0;
    Seconds release = 0.0;

    unsigned long attackSamples = 0;
    unsigned long decaySamples = 0;
    unsigned long releaseSamples = 0;
    
    enum EnvelopeState {
        ATTACK_STATE,
        DECAY_STATE,
        SUSTAIN_STATE,
        RELEASE_STATE
    };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};



#endif  // ENVELOPE_H_INCLUDED
