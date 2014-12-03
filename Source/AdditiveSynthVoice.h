//
//  AdditiveSynthVoice.h
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#ifndef __Plus__AdditiveSynthVoice__
#define __Plus__AdditiveSynthVoice__

const int PartialToParamMapping[16] =
{
    PARTIAL_1,
    PARTIAL_2,
    PARTIAL_3,
    PARTIAL_4,
    PARTIAL_5,
    PARTIAL_6,
    PARTIAL_7,
    PARTIAL_8,
    PARTIAL_9,
    PARTIAL_10,
    PARTIAL_11,
    PARTIAL_12,
    PARTIAL_13,
    PARTIAL_14,
    PARTIAL_15,
    PARTIAL_16
};

const int waveTableLength = 128 * 1024;

class AdditiveSynthVoice : public SynthesiserVoice
{
public:
    AdditiveSynthVoice(float* parameters, double* waveTable);
    ~AdditiveSynthVoice();
    float getParameter(int index);
    
    bool canPlaySound (SynthesiserSound* sound);
    
    void startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int currrentPitchWheelPosition);
    
    void stopNote (float velocity, const bool allowTailOff);
    
    void pitchWheelMoved (const int newValue);
    
    void controllerMoved (const int /*controllerNumber*/, const int /*newValue*/);
    
    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
    
    void aftertouchChanged (int newAftertouchValue);
    
    void setCurrentPlaybackSampleRate (double newRate);

    bool isPlayingChannel (int midiChannel) const;
    
    float getAmplitude();

    
private:

    float* localParameters;
    double* localWaveTable;
    double freq = 110.0;
    int noteNumber;
    double velocity = 0;
    double envLevel = 0;
    double releaseEnvLevel = 0;
    int stretchedIndices[numPartials] = { 0 };
    int samplesSinceTrigger = 0;
    double minPartialLevel = 0.0;
    double maxPartialLevel = 0.0;
    double partialLevels[numPartials] = { 0.0 };

    float calculateFrequency(int currentPitchWheelPosition);
    
    
    double scaleRange(double in, double oldMin, double oldMax, double newMin, double newMax)
    {
        if (oldMax == oldMin)
            return 0.0;
        return (in / ((oldMax - oldMin) / (newMax - newMin))) + newMin;
    }

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AdditiveSynthVoice);
};

#endif /* defined(__Plus__AdditiveSynthVoice__) */
