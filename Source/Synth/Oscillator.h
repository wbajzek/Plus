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
    
    void setFrequency(double newFrequency)
    {
        frequency = newFrequency;
        increment = frqTI * frequency;
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

    float tick()
    {
        jassert(sampleRate > 0);
        jassert(frqTI > 0);
        float value = 0.0;
        switch (waveTableShape)
        {
            case SINE_WAVE_TABLE:
                value += sineWaveTable[index];
                break;
            case TRIANGLE_WAVE_TABLE:
                value += triangleWaveTable[index];
                break;
            case SAW_WAVE_TABLE:
                value += sawWaveTable[index];
                break;
            case RAMP_WAVE_TABLE:
                value += rampWaveTable[index];
                break;
            default:
                break;
        }
        index += increment;
        
        while (index >= waveTableLength)
            index -= waveTableLength;
        
        return value;
    }
    
private:
    float sampleRate = 0.0;
    double frqTI = 0.0;
    double frequency = 0.0;
    double increment = 0.0;
    unsigned int index = 0;
    int waveTableShape = 0;
};


#endif  // OSCILLATOR_H_INCLUDED
