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
        envelope.tick(keyIsDown);
        oscillator.tick();
    }
    
    Amplitude output()
    {
        return oscillator.output() * amplitude();
    }
    
    Amplitude amplitude()
    {
        return envelope.amplitude() * velocity;
    }
    
    bool isActive()
    {
        return envelope.isActive();
    }
    
private:
    Oscillator oscillator;
    Envelope envelope;
    Frequency sampleRate;
    Amplitude velocity;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthVoice)
};



#endif  // SYNTHVOICE_H_INCLUDED
