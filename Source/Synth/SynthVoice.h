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
        envelope.trigger(newVelocity);
    }

    void setFrequency(Frequency newFrequency)
    {
        oscillator.setFrequency(newFrequency);
    }
    
    void tick(bool keyIsDown)
    {
        oscillator.tick();
        envelope.tick(keyIsDown);
    }
    
    Amplitude output()
    {
        return oscillator.output() * envelope.amplitude();
    }
    
    Amplitude amplitude()
    {
        return envelope.amplitude();
    }
    
private:
    Oscillator oscillator;
    Envelope envelope;
    Frequency sampleRate;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthVoice)
};



#endif  // SYNTHVOICE_H_INCLUDED
