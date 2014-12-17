//
//  AdditiveSynthVoice.h
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#ifndef __Plus__AdditiveSynthVoice__
#define __Plus__AdditiveSynthVoice__

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

const int PartialAttackToParamMapping[numPartials] =
{
    PARTIAL_ATTACK_1,
    PARTIAL_ATTACK_2,
    PARTIAL_ATTACK_3,
    PARTIAL_ATTACK_4,
    PARTIAL_ATTACK_5,
    PARTIAL_ATTACK_6,
    PARTIAL_ATTACK_7,
    PARTIAL_ATTACK_8,
    PARTIAL_ATTACK_9,
    PARTIAL_ATTACK_10,
    PARTIAL_ATTACK_11,
    PARTIAL_ATTACK_12,
    PARTIAL_ATTACK_13,
    PARTIAL_ATTACK_14,
    PARTIAL_ATTACK_15,
    PARTIAL_ATTACK_16,
    PARTIAL_ATTACK_17,
    PARTIAL_ATTACK_18,
    PARTIAL_ATTACK_19,
    PARTIAL_ATTACK_20,
    PARTIAL_ATTACK_21,
    PARTIAL_ATTACK_22,
    PARTIAL_ATTACK_23,
    PARTIAL_ATTACK_24,
    PARTIAL_ATTACK_25,
    PARTIAL_ATTACK_26,
    PARTIAL_ATTACK_27,
    PARTIAL_ATTACK_28,
    PARTIAL_ATTACK_29,
    PARTIAL_ATTACK_30,
    PARTIAL_ATTACK_31,
    PARTIAL_ATTACK_32,
};

const int PartialDecayToParamMapping[numPartials] =
{
    PARTIAL_DECAY_1,
    PARTIAL_DECAY_2,
    PARTIAL_DECAY_3,
    PARTIAL_DECAY_4,
    PARTIAL_DECAY_5,
    PARTIAL_DECAY_6,
    PARTIAL_DECAY_7,
    PARTIAL_DECAY_8,
    PARTIAL_DECAY_9,
    PARTIAL_DECAY_10,
    PARTIAL_DECAY_11,
    PARTIAL_DECAY_12,
    PARTIAL_DECAY_13,
    PARTIAL_DECAY_14,
    PARTIAL_DECAY_15,
    PARTIAL_DECAY_16,
    PARTIAL_DECAY_17,
    PARTIAL_DECAY_18,
    PARTIAL_DECAY_19,
    PARTIAL_DECAY_20,
    PARTIAL_DECAY_21,
    PARTIAL_DECAY_22,
    PARTIAL_DECAY_23,
    PARTIAL_DECAY_24,
    PARTIAL_DECAY_25,
    PARTIAL_DECAY_26,
    PARTIAL_DECAY_27,
    PARTIAL_DECAY_28,
    PARTIAL_DECAY_29,
    PARTIAL_DECAY_30,
    PARTIAL_DECAY_31,
    PARTIAL_DECAY_32,
};

const int PartialSustainToParamMapping[numPartials] =
{
    PARTIAL_SUSTAIN_1,
    PARTIAL_SUSTAIN_2,
    PARTIAL_SUSTAIN_3,
    PARTIAL_SUSTAIN_4,
    PARTIAL_SUSTAIN_5,
    PARTIAL_SUSTAIN_6,
    PARTIAL_SUSTAIN_7,
    PARTIAL_SUSTAIN_8,
    PARTIAL_SUSTAIN_9,
    PARTIAL_SUSTAIN_10,
    PARTIAL_SUSTAIN_11,
    PARTIAL_SUSTAIN_12,
    PARTIAL_SUSTAIN_13,
    PARTIAL_SUSTAIN_14,
    PARTIAL_SUSTAIN_15,
    PARTIAL_SUSTAIN_16,
    PARTIAL_SUSTAIN_17,
    PARTIAL_SUSTAIN_18,
    PARTIAL_SUSTAIN_19,
    PARTIAL_SUSTAIN_20,
    PARTIAL_SUSTAIN_21,
    PARTIAL_SUSTAIN_22,
    PARTIAL_SUSTAIN_23,
    PARTIAL_SUSTAIN_24,
    PARTIAL_SUSTAIN_25,
    PARTIAL_SUSTAIN_26,
    PARTIAL_SUSTAIN_27,
    PARTIAL_SUSTAIN_28,
    PARTIAL_SUSTAIN_29,
    PARTIAL_SUSTAIN_30,
    PARTIAL_SUSTAIN_31,
    PARTIAL_SUSTAIN_32,
};

const int PartialReleaseToParamMapping[numPartials] =
{
    PARTIAL_RELEASE_1,
    PARTIAL_RELEASE_2,
    PARTIAL_RELEASE_3,
    PARTIAL_RELEASE_4,
    PARTIAL_RELEASE_5,
    PARTIAL_RELEASE_6,
    PARTIAL_RELEASE_7,
    PARTIAL_RELEASE_8,
    PARTIAL_RELEASE_9,
    PARTIAL_RELEASE_10,
    PARTIAL_RELEASE_11,
    PARTIAL_RELEASE_12,
    PARTIAL_RELEASE_13,
    PARTIAL_RELEASE_14,
    PARTIAL_RELEASE_15,
    PARTIAL_RELEASE_16,
    PARTIAL_RELEASE_17,
    PARTIAL_RELEASE_18,
    PARTIAL_RELEASE_19,
    PARTIAL_RELEASE_20,
    PARTIAL_RELEASE_21,
    PARTIAL_RELEASE_22,
    PARTIAL_RELEASE_23,
    PARTIAL_RELEASE_24,
    PARTIAL_RELEASE_25,
    PARTIAL_RELEASE_26,
    PARTIAL_RELEASE_27,
    PARTIAL_RELEASE_28,
    PARTIAL_RELEASE_29,
    PARTIAL_RELEASE_30,
    PARTIAL_RELEASE_31,
    PARTIAL_RELEASE_32,
};


class AdditiveSynthVoice : public SynthesiserVoice, public ActionListener
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

    void actionListenerCallback (const String &message);

private:

    Envelope envelope;
    Oscillator lfo;

    float* localParameters;
    int* localLfoShape;
    int* localScale;
    int* localScaleRoot;
    Frequency freq = 110.0;
    int noteNumber;
    Amplitude velocity = 0.0;
    Amplitude envLevel = 0.0;
    bool voiceIsActive = false;
    Amplitude lfoLevel = 0.0;
    Frequency nyquist;
    double sampleRate;
    double frqTI;
    float modWheel = 0.0;

    unsigned long samplesSinceTrigger = 0;

    long partialIndices[numPartials] = { 0 };
    Envelope partialEnvelopes[numPartials];
    Amplitude partialEnvelopeLevels[numPartials] = { 0.0 };
    Envelope noiseEnvelope;
    Amplitude noiseLevel;

    Frequency calculateFrequency(int currentPitchWheelPosition);
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
