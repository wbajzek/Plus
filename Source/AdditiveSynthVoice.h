//
//  AdditiveSynthVoice.h
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#ifndef __Plus__AdditiveSynthVoice__
#define __Plus__AdditiveSynthVoice__

enum EnvelopeState {
    ATTACK_STATE,
    DECAY_STATE,
    SUSTAIN_STATE,
    RELEASE_STATE
};

const int PartialLevelToParamMapping[numPartials] =
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
    PARTIAL_16,
    PARTIAL_17,
    PARTIAL_18,
    PARTIAL_19,
    PARTIAL_20,
    PARTIAL_21,
    PARTIAL_22,
    PARTIAL_23,
    PARTIAL_24,
    PARTIAL_25,
    PARTIAL_26,
    PARTIAL_27,
    PARTIAL_28,
    PARTIAL_29,
    PARTIAL_30,
    PARTIAL_31,
    PARTIAL_32,
};

const int PartialTuneToParamMapping[numPartials] =
{
    PARTIAL_TUNE_1,
    PARTIAL_TUNE_2,
    PARTIAL_TUNE_3,
    PARTIAL_TUNE_4,
    PARTIAL_TUNE_5,
    PARTIAL_TUNE_6,
    PARTIAL_TUNE_7,
    PARTIAL_TUNE_8,
    PARTIAL_TUNE_9,
    PARTIAL_TUNE_10,
    PARTIAL_TUNE_11,
    PARTIAL_TUNE_12,
    PARTIAL_TUNE_13,
    PARTIAL_TUNE_14,
    PARTIAL_TUNE_15,
    PARTIAL_TUNE_16,
    PARTIAL_TUNE_17,
    PARTIAL_TUNE_18,
    PARTIAL_TUNE_19,
    PARTIAL_TUNE_20,
    PARTIAL_TUNE_21,
    PARTIAL_TUNE_22,
    PARTIAL_TUNE_23,
    PARTIAL_TUNE_24,
    PARTIAL_TUNE_25,
    PARTIAL_TUNE_26,
    PARTIAL_TUNE_27,
    PARTIAL_TUNE_28,
    PARTIAL_TUNE_29,
    PARTIAL_TUNE_30,
    PARTIAL_TUNE_31,
    PARTIAL_TUNE_32,
};

const int PartialPanToParamMapping[numPartials] =
{
    PARTIAL_PAN_1,
    PARTIAL_PAN_2,
    PARTIAL_PAN_3,
    PARTIAL_PAN_4,
    PARTIAL_PAN_5,
    PARTIAL_PAN_6,
    PARTIAL_PAN_7,
    PARTIAL_PAN_8,
    PARTIAL_PAN_9,
    PARTIAL_PAN_10,
    PARTIAL_PAN_11,
    PARTIAL_PAN_12,
    PARTIAL_PAN_13,
    PARTIAL_PAN_14,
    PARTIAL_PAN_15,
    PARTIAL_PAN_16,
    PARTIAL_PAN_17,
    PARTIAL_PAN_18,
    PARTIAL_PAN_19,
    PARTIAL_PAN_20,
    PARTIAL_PAN_21,
    PARTIAL_PAN_22,
    PARTIAL_PAN_23,
    PARTIAL_PAN_24,
    PARTIAL_PAN_25,
    PARTIAL_PAN_26,
    PARTIAL_PAN_27,
    PARTIAL_PAN_28,
    PARTIAL_PAN_29,
    PARTIAL_PAN_30,
    PARTIAL_PAN_31,
    PARTIAL_PAN_32,
};

const int PartialLfoAmtToParamMapping[numPartials] =
{
    PARTIAL_LFO_AMT_1,
    PARTIAL_LFO_AMT_2,
    PARTIAL_LFO_AMT_3,
    PARTIAL_LFO_AMT_4,
    PARTIAL_LFO_AMT_5,
    PARTIAL_LFO_AMT_6,
    PARTIAL_LFO_AMT_7,
    PARTIAL_LFO_AMT_8,
    PARTIAL_LFO_AMT_9,
    PARTIAL_LFO_AMT_10,
    PARTIAL_LFO_AMT_11,
    PARTIAL_LFO_AMT_12,
    PARTIAL_LFO_AMT_13,
    PARTIAL_LFO_AMT_14,
    PARTIAL_LFO_AMT_15,
    PARTIAL_LFO_AMT_16,
    PARTIAL_LFO_AMT_17,
    PARTIAL_LFO_AMT_18,
    PARTIAL_LFO_AMT_19,
    PARTIAL_LFO_AMT_20,
    PARTIAL_LFO_AMT_21,
    PARTIAL_LFO_AMT_22,
    PARTIAL_LFO_AMT_23,
    PARTIAL_LFO_AMT_24,
    PARTIAL_LFO_AMT_25,
    PARTIAL_LFO_AMT_26,
    PARTIAL_LFO_AMT_27,
    PARTIAL_LFO_AMT_28,
    PARTIAL_LFO_AMT_29,
    PARTIAL_LFO_AMT_30,
    PARTIAL_LFO_AMT_31,
    PARTIAL_LFO_AMT_32,
};


class AdditiveSynthVoice : public SynthesiserVoice
{
public:
    AdditiveSynthVoice(float* parameters, int* lfoShape, int* scale, int* scaleRoot);
    ~AdditiveSynthVoice();
    float getParameter(int index);

    bool canPlaySound (SynthesiserSound* sound);

    void startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int currentPitchWheelPosition);

    void stopNote (float velocity, const bool allowTailOff);

    void pitchWheelMoved (const int newValue);

    void controllerMoved (const int /*controllerNumber*/, const int /*newValue*/);

    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);

    void aftertouchChanged (int newAftertouchValue);
    
    void setCurrentPlaybackSampleRate (double newRate);
    
    bool isPlayingChannel (int midiChannel) const;

    bool isVoiceActive() const;

private:
    
    Envelope envelope;
    Oscillator lfo;
    
    float* localParameters;
    int* localLfoShape;
    int* localScale;
    int* localScaleRoot;
    double freq = 110.0;
    int noteNumber;
    double velocity = 0.0;
    double envLevel = 0.0;
    double lfoLevel = 0.0;
    double nyquist;
    double sampleRate;
    double frqTI;
    float modWheel = 0.0;

    unsigned long samplesSinceTrigger = 0;
    
    long stretchedIndices[numPartials] = { 0 };
    unsigned int lfoIndex = 0;

    float calculateFrequency(int currentPitchWheelPosition);
    void tick();

    double scaleRange(double in, double oldMin, double oldMax, double newMin, double newMax)
    {
        if (oldMax == oldMin)
            return 0.0;
        return (in / ((oldMax - oldMin) / (newMax - newMin))) + newMin;
    }

    Scale getScale() {
        return scales[*localScale - 1];
    }
    
    int getScaleRoot() {
        return *localScaleRoot - 1;
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AdditiveSynthVoice);
};

#endif /* defined(__Plus__AdditiveSynthVoice__) */
