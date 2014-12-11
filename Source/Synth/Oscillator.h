/*
  ==============================================================================

    Oscillator.h
    Created: 11 Dec 2014 8:49:09am
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED


class Oscillator
{
public:
    
    Oscillator()
    {
    }

    ~Oscillator()
    {
        waveTable = nullptr;
    }
    
    void setFrequency(double newFrequency)
    {
        frequency = newFrequency;
    }
    
    void setSampleRate(float newSampleRate)
    {
        frqTI = waveTableLength/sampleRate;
    }
    
    void setWavetable(double *newWaveTable)
    {
        waveTable = newWaveTable;
        waveTableLength = sizeof(waveTable) / sizeof(waveTable[0]);
    }

    float tick()
    {
        double value = waveTable[lfoIndex];
        lfoIndex += frqTI * frequency;
        
        while (lfoIndex >= waveTableLength)
            lfoIndex -= waveTableLength;
        
        return value;
    }
    
private:
    double *waveTable;
    int waveTableLength = 0;
    float sampleRate = 0.0;
    double frqTI = 0.0;
    double frequency = 0.0;
    double increment = 0.0;
    unsigned int lfoIndex = 0;
    int localLfoShape = 0;
};


#endif  // OSCILLATOR_H_INCLUDED
