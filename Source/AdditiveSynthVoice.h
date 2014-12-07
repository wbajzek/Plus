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


class AdditiveSynthVoice : public SynthesiserVoice
{
public:
    AdditiveSynthVoice(float* parameters);
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

    float getAmplitude();


private:

    float* localParameters;
    double freq = 110.0;
    int noteNumber;
    double velocity = 0;
    double envLevel = 0;
    double releaseEnvLevel = 0;
    float nyquist;
    float sampleRate;
    float frqTI;
    int envelopeState = 0;

    int samplesSinceTrigger = 0;
    float coefficient = 0.0;
    double minPartialLevel = 0.0;
    double maxPartialLevel = 0.0;
    double partialLevels[numPartials] = { 0.0 };
    double partialStretchAmounts[numPartials] = { 0.0 };
    long stretchedIndices[numPartials] = { 0 };

    int attack = 0;
    int decay = 0;
    float sustainLevel = 0.0;
    int release = 0;
    double envIncrement = 0.0;

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
