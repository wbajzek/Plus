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
    }
    
    void setFrequency(Frequency newFrequency)
    {
        frequency = newFrequency;
        increment = (long)(frqTI * frequency) << 16;
    }
    
    void setSampleRate(float newSampleRate)
    {
        sampleRate = newSampleRate;
        frqTI = waveTableLength/sampleRate;
    }
    
    void setWaveTable(int newWaveTableShape)
    {
        waveTableShape = newWaveTableShape;
    }

    Amplitude tick()
    {
        jassert(sampleRate > 0);
        jassert(frqTI > 0);
        Amplitude value = 0.0;
        int scaledIndex = ((index+0x8000) >> 16);
        switch (waveTableShape)
        {
            case SINE_WAVE_TABLE:
                value += sineWaveTable[scaledIndex];
                break;
            case TRIANGLE_WAVE_TABLE:
                value += triangleWaveTable[scaledIndex];
                break;
            case SAW_WAVE_TABLE:
                value += sawWaveTable[scaledIndex];
                break;
            case RAMP_WAVE_TABLE:
                value += rampWaveTable[scaledIndex];
                break;
            case WHITE_NOISE_WAVE_TABLE:
                value += whiteNoiseWaveTable[scaledIndex];
                break;
            default:
                break;
        }
        index += increment;
        
        index = index + increment & ((waveTableLength << 16) - 1);
        
        return value;
    }
    
private:
    float sampleRate = 0.0;
    double frqTI = 0.0;
    Frequency frequency = 0.0;
    long increment = 0.0;
    unsigned long index = 0;
    int waveTableShape = 0;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};


#endif  // OSCILLATOR_H_INCLUDED
