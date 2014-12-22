/*
  ==============================================================================

    SynthVoice.h
    Created: 20 Dec 2014 10:06:47am
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef SYNTHVOICE_H_INCLUDED
#define SYNTHVOICE_H_INCLUDED

class SynthVoice
{
public:
    SynthVoice() {
        
    }
    ~SynthVoice() {
    }

    
    void setSampleRate(Frequency newRate)
    {
        sampleRate = newRate;
        oscillator.setSampleRate(newRate);
        envelope.setSampleRate(newRate);
    }
    
    void setWaveTable(int newWaveTableShape)
    {
        oscillator.setWaveTable(newWaveTableShape);
    }
    
    void setAdsr(Seconds newAttack, Seconds newDecay, Amplitude newSustainLevel, Seconds newRelease)
    {
        envelope.setAdsr(newAttack, newDecay, newSustainLevel, newRelease);
    }

    void trigger(Amplitude newVelocity) {
        velocity = newVelocity;
        envelope.trigger();
    }

    void setFrequency(Frequency newFrequency)
    {
        oscillator.setFrequency(newFrequency);
    }
    
    void tick(bool keyIsDown)
    {
        currentAmplitude = envelope.tick(keyIsDown);
        if (currentAmplitude > 0.0)
            if ((currentAmplitude *= velocity) > 0.0)
                currentSample = oscillator.tick() * currentAmplitude;
    }
        
    bool isActive()
    {
        return envelope.isActive();
    }

    Amplitude currentSample = 0.0;
    Amplitude currentAmplitude = 0.0;

private:
    Oscillator oscillator;
    Envelope envelope;
    Frequency sampleRate;
    Amplitude velocity;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthVoice)
};



#endif  // SYNTHVOICE_H_INCLUDED
