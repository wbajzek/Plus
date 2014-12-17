#include "AdditiveSynth.h"
#include "PlusAudioProcessor.h"
#include "PlusAudioProcessorEditor.h"

//==============================================================================
PlusAudioProcessor::PlusAudioProcessor()
{
    parameters[ATTACK] = 0.01;
    parameters[DECAY] = 1.0;
    parameters[SUSTAIN] = 0.8;
    parameters[RELEASE] = 1.0;
    parameters[STRETCH] = 0.0;
    parameters[STRETCH_FINE] = 0.0;
    parameters[STRETCH_ENV_AMT] = 0.0;
    parameters[STRETCH_ENV_AMT_FINE] = 0.0;
    parameters[PARTIAL_1] = 1.0;
    parameters[PARTIAL_2] = 0.0;
    parameters[PARTIAL_3] = 0.0;
    parameters[PARTIAL_4] = 0.0;
    parameters[PARTIAL_5] = 0.0;
    parameters[PARTIAL_6] = 0.0;
    parameters[PARTIAL_7] = 0.0;
    parameters[PARTIAL_8] = 0.0;
    parameters[PARTIAL_9] = 0.0;
    parameters[PARTIAL_10] = 0.0;
    parameters[PARTIAL_11] = 0.0;
    parameters[PARTIAL_12] = 0.0;
    parameters[PARTIAL_13] = 0.0;
    parameters[PARTIAL_14] = 0.0;
    parameters[PARTIAL_15] = 0.0;
    parameters[PARTIAL_16] = 0.0;
    parameters[PARTIAL_17] = 0.0;
    parameters[PARTIAL_18] = 0.0;
    parameters[PARTIAL_19] = 0.0;
    parameters[PARTIAL_20] = 0.0;
    parameters[PARTIAL_21] = 0.0;
    parameters[PARTIAL_22] = 0.0;
    parameters[PARTIAL_23] = 0.0;
    parameters[PARTIAL_24] = 0.0;
    parameters[PARTIAL_25] = 0.0;
    parameters[PARTIAL_26] = 0.0;
    parameters[PARTIAL_27] = 0.0;
    parameters[PARTIAL_28] = 0.0;
    parameters[PARTIAL_29] = 0.0;
    parameters[PARTIAL_30] = 0.0;
    parameters[PARTIAL_31] = 0.0;
    parameters[PARTIAL_32] = 0.0;
    parameters[PARTIAL_TUNE_1] = 0.0;
    parameters[PARTIAL_TUNE_2] = 0.0;
    parameters[PARTIAL_TUNE_3] = 0.0;
    parameters[PARTIAL_TUNE_4] = 0.0;
    parameters[PARTIAL_TUNE_5] = 0.0;
    parameters[PARTIAL_TUNE_6] = 0.0;
    parameters[PARTIAL_TUNE_7] = 0.0;
    parameters[PARTIAL_TUNE_8] = 0.0;
    parameters[PARTIAL_TUNE_9] = 0.0;
    parameters[PARTIAL_TUNE_10] = 0.0;
    parameters[PARTIAL_TUNE_11] = 0.0;
    parameters[PARTIAL_TUNE_12] = 0.0;
    parameters[PARTIAL_TUNE_13] = 0.0;
    parameters[PARTIAL_TUNE_14] = 0.0;
    parameters[PARTIAL_TUNE_15] = 0.0;
    parameters[PARTIAL_TUNE_16] = 0.0;
    parameters[PARTIAL_TUNE_17] = 0.0;
    parameters[PARTIAL_TUNE_18] = 0.0;
    parameters[PARTIAL_TUNE_19] = 0.0;
    parameters[PARTIAL_TUNE_20] = 0.0;
    parameters[PARTIAL_TUNE_21] = 0.0;
    parameters[PARTIAL_TUNE_22] = 0.0;
    parameters[PARTIAL_TUNE_23] = 0.0;
    parameters[PARTIAL_TUNE_24] = 0.0;
    parameters[PARTIAL_TUNE_25] = 0.0;
    parameters[PARTIAL_TUNE_26] = 0.0;
    parameters[PARTIAL_TUNE_27] = 0.0;
    parameters[PARTIAL_TUNE_28] = 0.0;
    parameters[PARTIAL_TUNE_29] = 0.0;
    parameters[PARTIAL_TUNE_30] = 0.0;
    parameters[PARTIAL_TUNE_31] = 0.0;
    parameters[PARTIAL_TUNE_32] = 0.0;
    parameters[PARTIAL_PAN_1] = 0.0;
    parameters[PARTIAL_PAN_2] = 0.0;
    parameters[PARTIAL_PAN_3] = 0.0;
    parameters[PARTIAL_PAN_4] = 0.0;
    parameters[PARTIAL_PAN_5] = 0.0;
    parameters[PARTIAL_PAN_6] = 0.0;
    parameters[PARTIAL_PAN_7] = 0.0;
    parameters[PARTIAL_PAN_8] = 0.0;
    parameters[PARTIAL_PAN_9] = 0.0;
    parameters[PARTIAL_PAN_10] = 0.0;
    parameters[PARTIAL_PAN_11] = 0.0;
    parameters[PARTIAL_PAN_12] = 0.0;
    parameters[PARTIAL_PAN_13] = 0.0;
    parameters[PARTIAL_PAN_14] = 0.0;
    parameters[PARTIAL_PAN_15] = 0.0;
    parameters[PARTIAL_PAN_16] = 0.0;
    parameters[PARTIAL_PAN_17] = 0.0;
    parameters[PARTIAL_PAN_18] = 0.0;
    parameters[PARTIAL_PAN_19] = 0.0;
    parameters[PARTIAL_PAN_20] = 0.0;
    parameters[PARTIAL_PAN_21] = 0.0;
    parameters[PARTIAL_PAN_22] = 0.0;
    parameters[PARTIAL_PAN_23] = 0.0;
    parameters[PARTIAL_PAN_24] = 0.0;
    parameters[PARTIAL_PAN_25] = 0.0;
    parameters[PARTIAL_PAN_26] = 0.0;
    parameters[PARTIAL_PAN_27] = 0.0;
    parameters[PARTIAL_PAN_28] = 0.0;
    parameters[PARTIAL_PAN_29] = 0.0;
    parameters[PARTIAL_PAN_30] = 0.0;
    parameters[PARTIAL_PAN_31] = 0.0;
    parameters[PARTIAL_PAN_32] = 0.0;
    parameters[PARTIAL_LFO_AMT_1] = 0.0;
    parameters[PARTIAL_LFO_AMT_2] = 0.0;
    parameters[PARTIAL_LFO_AMT_3] = 0.0;
    parameters[PARTIAL_LFO_AMT_4] = 0.0;
    parameters[PARTIAL_LFO_AMT_5] = 0.0;
    parameters[PARTIAL_LFO_AMT_6] = 0.0;
    parameters[PARTIAL_LFO_AMT_7] = 0.0;
    parameters[PARTIAL_LFO_AMT_8] = 0.0;
    parameters[PARTIAL_LFO_AMT_9] = 0.0;
    parameters[PARTIAL_LFO_AMT_10] = 0.0;
    parameters[PARTIAL_LFO_AMT_11] = 0.0;
    parameters[PARTIAL_LFO_AMT_12] = 0.0;
    parameters[PARTIAL_LFO_AMT_13] = 0.0;
    parameters[PARTIAL_LFO_AMT_14] = 0.0;
    parameters[PARTIAL_LFO_AMT_15] = 0.0;
    parameters[PARTIAL_LFO_AMT_16] = 0.0;
    parameters[PARTIAL_LFO_AMT_17] = 0.0;
    parameters[PARTIAL_LFO_AMT_18] = 0.0;
    parameters[PARTIAL_LFO_AMT_19] = 0.0;
    parameters[PARTIAL_LFO_AMT_20] = 0.0;
    parameters[PARTIAL_LFO_AMT_21] = 0.0;
    parameters[PARTIAL_LFO_AMT_22] = 0.0;
    parameters[PARTIAL_LFO_AMT_23] = 0.0;
    parameters[PARTIAL_LFO_AMT_24] = 0.0;
    parameters[PARTIAL_LFO_AMT_25] = 0.0;
    parameters[PARTIAL_LFO_AMT_26] = 0.0;
    parameters[PARTIAL_LFO_AMT_27] = 0.0;
    parameters[PARTIAL_LFO_AMT_28] = 0.0;
    parameters[PARTIAL_LFO_AMT_29] = 0.0;
    parameters[PARTIAL_LFO_AMT_30] = 0.0;
    parameters[PARTIAL_LFO_AMT_31] = 0.0;
    parameters[PARTIAL_LFO_AMT_32] = 0.0;
    parameters[PARTIAL_ATTACK_1] = 0.001;
    parameters[PARTIAL_ATTACK_2] = 0.001;
    parameters[PARTIAL_ATTACK_3] = 0.001;
    parameters[PARTIAL_ATTACK_4] = 0.001;
    parameters[PARTIAL_ATTACK_5] = 0.001;
    parameters[PARTIAL_ATTACK_6] = 0.001;
    parameters[PARTIAL_ATTACK_7] = 0.001;
    parameters[PARTIAL_ATTACK_8] = 0.001;
    parameters[PARTIAL_ATTACK_9] = 0.001;
    parameters[PARTIAL_ATTACK_10] = 0.001;
    parameters[PARTIAL_ATTACK_11] = 0.001;
    parameters[PARTIAL_ATTACK_12] = 0.001;
    parameters[PARTIAL_ATTACK_13] = 0.001;
    parameters[PARTIAL_ATTACK_14] = 0.001;
    parameters[PARTIAL_ATTACK_15] = 0.001;
    parameters[PARTIAL_ATTACK_16] = 0.001;
    parameters[PARTIAL_ATTACK_17] = 0.001;
    parameters[PARTIAL_ATTACK_18] = 0.001;
    parameters[PARTIAL_ATTACK_19] = 0.001;
    parameters[PARTIAL_ATTACK_20] = 0.001;
    parameters[PARTIAL_ATTACK_21] = 0.001;
    parameters[PARTIAL_ATTACK_22] = 0.001;
    parameters[PARTIAL_ATTACK_23] = 0.001;
    parameters[PARTIAL_ATTACK_24] = 0.001;
    parameters[PARTIAL_ATTACK_25] = 0.001;
    parameters[PARTIAL_ATTACK_26] = 0.001;
    parameters[PARTIAL_ATTACK_27] = 0.001;
    parameters[PARTIAL_ATTACK_28] = 0.001;
    parameters[PARTIAL_ATTACK_29] = 0.001;
    parameters[PARTIAL_ATTACK_30] = 0.001;
    parameters[PARTIAL_ATTACK_31] = 0.001;
    parameters[PARTIAL_ATTACK_32] = 0.001;
    parameters[PARTIAL_DECAY_1] = 0.001;
    parameters[PARTIAL_DECAY_2] = 0.001;
    parameters[PARTIAL_DECAY_3] = 0.001;
    parameters[PARTIAL_DECAY_4] = 0.001;
    parameters[PARTIAL_DECAY_5] = 0.001;
    parameters[PARTIAL_DECAY_6] = 0.001;
    parameters[PARTIAL_DECAY_7] = 0.001;
    parameters[PARTIAL_DECAY_8] = 0.001;
    parameters[PARTIAL_DECAY_9] = 0.001;
    parameters[PARTIAL_DECAY_10] = 0.001;
    parameters[PARTIAL_DECAY_11] = 0.001;
    parameters[PARTIAL_DECAY_12] = 0.001;
    parameters[PARTIAL_DECAY_13] = 0.001;
    parameters[PARTIAL_DECAY_14] = 0.001;
    parameters[PARTIAL_DECAY_15] = 0.001;
    parameters[PARTIAL_DECAY_16] = 0.001;
    parameters[PARTIAL_DECAY_17] = 0.001;
    parameters[PARTIAL_DECAY_18] = 0.001;
    parameters[PARTIAL_DECAY_19] = 0.001;
    parameters[PARTIAL_DECAY_20] = 0.001;
    parameters[PARTIAL_DECAY_21] = 0.001;
    parameters[PARTIAL_DECAY_22] = 0.001;
    parameters[PARTIAL_DECAY_23] = 0.001;
    parameters[PARTIAL_DECAY_24] = 0.001;
    parameters[PARTIAL_DECAY_25] = 0.001;
    parameters[PARTIAL_DECAY_26] = 0.001;
    parameters[PARTIAL_DECAY_27] = 0.001;
    parameters[PARTIAL_DECAY_28] = 0.001;
    parameters[PARTIAL_DECAY_29] = 0.001;
    parameters[PARTIAL_DECAY_30] = 0.001;
    parameters[PARTIAL_DECAY_31] = 0.001;
    parameters[PARTIAL_DECAY_32] = 0.001;
    parameters[PARTIAL_SUSTAIN_1] = 1.0;
    parameters[PARTIAL_SUSTAIN_2] = 1.0;
    parameters[PARTIAL_SUSTAIN_3] = 1.0;
    parameters[PARTIAL_SUSTAIN_4] = 1.0;
    parameters[PARTIAL_SUSTAIN_5] = 1.0;
    parameters[PARTIAL_SUSTAIN_6] = 1.0;
    parameters[PARTIAL_SUSTAIN_7] = 1.0;
    parameters[PARTIAL_SUSTAIN_8] = 1.0;
    parameters[PARTIAL_SUSTAIN_9] = 1.0;
    parameters[PARTIAL_SUSTAIN_10] = 1.0;
    parameters[PARTIAL_SUSTAIN_11] = 1.0;
    parameters[PARTIAL_SUSTAIN_12] = 1.0;
    parameters[PARTIAL_SUSTAIN_13] = 1.0;
    parameters[PARTIAL_SUSTAIN_14] = 1.0;
    parameters[PARTIAL_SUSTAIN_15] = 1.0;
    parameters[PARTIAL_SUSTAIN_16] = 1.0;
    parameters[PARTIAL_SUSTAIN_17] = 1.0;
    parameters[PARTIAL_SUSTAIN_18] = 1.0;
    parameters[PARTIAL_SUSTAIN_19] = 1.0;
    parameters[PARTIAL_SUSTAIN_20] = 1.0;
    parameters[PARTIAL_SUSTAIN_21] = 1.0;
    parameters[PARTIAL_SUSTAIN_22] = 1.0;
    parameters[PARTIAL_SUSTAIN_23] = 1.0;
    parameters[PARTIAL_SUSTAIN_24] = 1.0;
    parameters[PARTIAL_SUSTAIN_25] = 1.0;
    parameters[PARTIAL_SUSTAIN_26] = 1.0;
    parameters[PARTIAL_SUSTAIN_27] = 1.0;
    parameters[PARTIAL_SUSTAIN_28] = 1.0;
    parameters[PARTIAL_SUSTAIN_29] = 1.0;
    parameters[PARTIAL_SUSTAIN_30] = 1.0;
    parameters[PARTIAL_SUSTAIN_31] = 1.0;
    parameters[PARTIAL_SUSTAIN_32] = 1.0;
    parameters[PARTIAL_RELEASE_1] = 0.01;
    parameters[PARTIAL_RELEASE_2] = 0.01;
    parameters[PARTIAL_RELEASE_3] = 0.01;
    parameters[PARTIAL_RELEASE_4] = 0.01;
    parameters[PARTIAL_RELEASE_5] = 0.01;
    parameters[PARTIAL_RELEASE_6] = 0.01;
    parameters[PARTIAL_RELEASE_7] = 0.01;
    parameters[PARTIAL_RELEASE_8] = 0.01;
    parameters[PARTIAL_RELEASE_9] = 0.01;
    parameters[PARTIAL_RELEASE_10] = 0.01;
    parameters[PARTIAL_RELEASE_11] = 0.01;
    parameters[PARTIAL_RELEASE_12] = 0.01;
    parameters[PARTIAL_RELEASE_13] = 0.01;
    parameters[PARTIAL_RELEASE_14] = 0.01;
    parameters[PARTIAL_RELEASE_15] = 0.01;
    parameters[PARTIAL_RELEASE_16] = 0.01;
    parameters[PARTIAL_RELEASE_17] = 0.01;
    parameters[PARTIAL_RELEASE_18] = 0.01;
    parameters[PARTIAL_RELEASE_19] = 0.01;
    parameters[PARTIAL_RELEASE_20] = 0.01;
    parameters[PARTIAL_RELEASE_21] = 0.01;
    parameters[PARTIAL_RELEASE_22] = 0.01;
    parameters[PARTIAL_RELEASE_23] = 0.01;
    parameters[PARTIAL_RELEASE_24] = 0.01;
    parameters[PARTIAL_RELEASE_25] = 0.01;
    parameters[PARTIAL_RELEASE_26] = 0.01;
    parameters[PARTIAL_RELEASE_27] = 0.01;
    parameters[PARTIAL_RELEASE_28] = 0.01;
    parameters[PARTIAL_RELEASE_29] = 0.01;
    parameters[PARTIAL_RELEASE_30] = 0.01;
    parameters[PARTIAL_RELEASE_31] = 0.01;
    parameters[PARTIAL_RELEASE_32] = 0.01;
    parameters[NOISE_LEVEL] = 0.0;
    parameters[NOISE_LFO_AMT] = 0.0;
    parameters[NOISE_PAN] = 0.0;
    parameters[NOISE_ATTACK] = 0.01;
    parameters[NOISE_DECAY] = 0.01;
    parameters[NOISE_SUSTAIN] = 1.0;
    parameters[NOISE_RELEASE] = 0.01;
    parameters[LFO_FREQ] = 7.0;
    lfoShape = SINE_WAVE_TABLE;
    numberOfVoices = 8;
    scale = 1;
    scaleRoot = 1;

    initAllParameters();
    initVoices();

    synth.addSound(new AdditiveSynthSound());
    synth.setNoteStealingEnabled(true);
}

PlusAudioProcessor::~PlusAudioProcessor()
{
    synth.clearVoices();
    synth.clearSounds();
}

void PlusAudioProcessor::initVoices()
{
    synth.clearVoices();
    removeAllActionListeners();

    for (int i = 0; i < numberOfVoices; i++)
    {
        AdditiveSynthVoice *voice = new AdditiveSynthVoice(parameters, &lfoShape, &scale, &scaleRoot);
        addActionListener(voice);
        synth.addVoice(voice);
    }

    // make sure all the voices know the current sample rate
    synth.refreshCurrentPlaybackSampleRate ();
}

void PlusAudioProcessor::initParameters()
{
    addFloatParam(ATTACK, "Attack", true, SAVE, &parameters[ATTACK], 0.01, 10.0);
    addFloatParam(DECAY, "Decay", true, SAVE, &parameters[DECAY], 0.01, 20.0);
    addFloatParam(SUSTAIN, "Sustain", true, SAVE, &parameters[SUSTAIN], 0.0, 1.0);
    addFloatParam(RELEASE, "Release", true, SAVE, &parameters[RELEASE], 0.01, 20.0);
    addFloatParam(STRETCH, "Stretch", true, SAVE, &parameters[STRETCH], -1.0, 1.0);
    addFloatParam(STRETCH_FINE, "Stretch_Fine", true, SAVE, &parameters[STRETCH_FINE], -0.01, 0.01);
    addFloatParam(STRETCH_ENV_AMT, "Stretch_Env_Amt", true, SAVE, &parameters[STRETCH_ENV_AMT], 0.0, 2.0);
    addFloatParam(STRETCH_ENV_AMT_FINE, "Stretch_Env_Amt_Fine", true, SAVE, &parameters[STRETCH_ENV_AMT_FINE], 0.0, 0.1);
    addFloatParam(PARTIAL_1, "Partial_1", true, SAVE, &parameters[PARTIAL_1], 0.0, 1.0);
    addFloatParam(PARTIAL_2, "Partial_2", true, SAVE, &parameters[PARTIAL_2], 0.0, 1.0);
    addFloatParam(PARTIAL_3, "Partial_3", true, SAVE, &parameters[PARTIAL_3], 0.0, 1.0);
    addFloatParam(PARTIAL_4, "Partial_4", true, SAVE, &parameters[PARTIAL_4], 0.0, 1.0);
    addFloatParam(PARTIAL_5, "Partial_5", true, SAVE, &parameters[PARTIAL_5], 0.0, 1.0);
    addFloatParam(PARTIAL_6, "Partial_6", true, SAVE, &parameters[PARTIAL_6], 0.0, 1.0);
    addFloatParam(PARTIAL_7, "Partial_7", true, SAVE, &parameters[PARTIAL_7], 0.0, 1.0);
    addFloatParam(PARTIAL_8, "Partial_8", true, SAVE, &parameters[PARTIAL_8], 0.0, 1.0);
    addFloatParam(PARTIAL_9, "Partial_9", true, SAVE, &parameters[PARTIAL_9], 0.0, 1.0);
    addFloatParam(PARTIAL_10, "Partial_10", true, SAVE, &parameters[PARTIAL_10], 0.0, 1.0);
    addFloatParam(PARTIAL_11, "Partial_11", true, SAVE, &parameters[PARTIAL_11], 0.0, 1.0);
    addFloatParam(PARTIAL_12, "Partial_12", true, SAVE, &parameters[PARTIAL_12], 0.0, 1.0);
    addFloatParam(PARTIAL_13, "Partial_13", true, SAVE, &parameters[PARTIAL_13], 0.0, 1.0);
    addFloatParam(PARTIAL_14, "Partial_14", true, SAVE, &parameters[PARTIAL_14], 0.0, 1.0);
    addFloatParam(PARTIAL_15, "Partial_15", true, SAVE, &parameters[PARTIAL_15], 0.0, 1.0);
    addFloatParam(PARTIAL_16, "Partial_16", true, SAVE, &parameters[PARTIAL_16], 0.0, 1.0);
    addFloatParam(PARTIAL_17, "Partial_17", true, SAVE, &parameters[PARTIAL_17], 0.0, 1.0);
    addFloatParam(PARTIAL_18, "Partial_18", true, SAVE, &parameters[PARTIAL_18], 0.0, 1.0);
    addFloatParam(PARTIAL_19, "Partial_19", true, SAVE, &parameters[PARTIAL_19], 0.0, 1.0);
    addFloatParam(PARTIAL_20, "Partial_20", true, SAVE, &parameters[PARTIAL_20], 0.0, 1.0);
    addFloatParam(PARTIAL_21, "Partial_21", true, SAVE, &parameters[PARTIAL_21], 0.0, 1.0);
    addFloatParam(PARTIAL_22, "Partial_22", true, SAVE, &parameters[PARTIAL_22], 0.0, 1.0);
    addFloatParam(PARTIAL_23, "Partial_23", true, SAVE, &parameters[PARTIAL_23], 0.0, 1.0);
    addFloatParam(PARTIAL_24, "Partial_24", true, SAVE, &parameters[PARTIAL_24], 0.0, 1.0);
    addFloatParam(PARTIAL_25, "Partial_25", true, SAVE, &parameters[PARTIAL_25], 0.0, 1.0);
    addFloatParam(PARTIAL_26, "Partial_26", true, SAVE, &parameters[PARTIAL_26], 0.0, 1.0);
    addFloatParam(PARTIAL_27, "Partial_27", true, SAVE, &parameters[PARTIAL_27], 0.0, 1.0);
    addFloatParam(PARTIAL_28, "Partial_28", true, SAVE, &parameters[PARTIAL_28], 0.0, 1.0);
    addFloatParam(PARTIAL_29, "Partial_29", true, SAVE, &parameters[PARTIAL_29], 0.0, 1.0);
    addFloatParam(PARTIAL_30, "Partial_30", true, SAVE, &parameters[PARTIAL_30], 0.0, 1.0);
    addFloatParam(PARTIAL_31, "Partial_31", true, SAVE, &parameters[PARTIAL_31], 0.0, 1.0);
    addFloatParam(PARTIAL_32, "Partial_32", true, SAVE, &parameters[PARTIAL_32], 0.0, 1.0);
    addFloatParam(PARTIAL_TUNE_1, "Partial_Tune1", true, SAVE, &parameters[PARTIAL_TUNE_1], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_2, "Partial_Tune2", true, SAVE, &parameters[PARTIAL_TUNE_2], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_3, "Partial_Tune3", true, SAVE, &parameters[PARTIAL_TUNE_3], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_4, "Partial_Tune4", true, SAVE, &parameters[PARTIAL_TUNE_4], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_5, "Partial_Tune5", true, SAVE, &parameters[PARTIAL_TUNE_5], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_6, "Partial_Tune6", true, SAVE, &parameters[PARTIAL_TUNE_6], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_7, "Partial_Tune7", true, SAVE, &parameters[PARTIAL_TUNE_7], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_8, "Partial_Tune8", true, SAVE, &parameters[PARTIAL_TUNE_8], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_9, "Partial_Tune9", true, SAVE, &parameters[PARTIAL_TUNE_9], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_10, "Partial_Tune10", true, SAVE, &parameters[PARTIAL_TUNE_10], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_11, "Partial_Tune11", true, SAVE, &parameters[PARTIAL_TUNE_11], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_12, "Partial_Tune12", true, SAVE, &parameters[PARTIAL_TUNE_12], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_13, "Partial_Tune13", true, SAVE, &parameters[PARTIAL_TUNE_13], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_14, "Partial_Tune14", true, SAVE, &parameters[PARTIAL_TUNE_14], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_15, "Partial_Tune15", true, SAVE, &parameters[PARTIAL_TUNE_15], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_16, "Partial_Tune16", true, SAVE, &parameters[PARTIAL_TUNE_16], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_17, "Partial_Tune17", true, SAVE, &parameters[PARTIAL_TUNE_17], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_18, "Partial_Tune18", true, SAVE, &parameters[PARTIAL_TUNE_18], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_19, "Partial_Tune19", true, SAVE, &parameters[PARTIAL_TUNE_19], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_20, "Partial_Tune20", true, SAVE, &parameters[PARTIAL_TUNE_20], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_21, "Partial_Tune21", true, SAVE, &parameters[PARTIAL_TUNE_21], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_22, "Partial_Tune22", true, SAVE, &parameters[PARTIAL_TUNE_22], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_23, "Partial_Tune23", true, SAVE, &parameters[PARTIAL_TUNE_23], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_24, "Partial_Tune24", true, SAVE, &parameters[PARTIAL_TUNE_24], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_25, "Partial_Tune25", true, SAVE, &parameters[PARTIAL_TUNE_25], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_26, "Partial_Tune26", true, SAVE, &parameters[PARTIAL_TUNE_26], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_27, "Partial_Tune27", true, SAVE, &parameters[PARTIAL_TUNE_27], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_28, "Partial_Tune28", true, SAVE, &parameters[PARTIAL_TUNE_28], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_29, "Partial_Tune29", true, SAVE, &parameters[PARTIAL_TUNE_29], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_30, "Partial_Tune30", true, SAVE, &parameters[PARTIAL_TUNE_30], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_31, "Partial_Tune31", true, SAVE, &parameters[PARTIAL_TUNE_31], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_32, "Partial_Tune32", true, SAVE, &parameters[PARTIAL_TUNE_32], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_1, "Partial_Pan1", true, SAVE, &parameters[PARTIAL_PAN_1], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_2, "Partial_Pan2", true, SAVE, &parameters[PARTIAL_PAN_2], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_3, "Partial_Pan3", true, SAVE, &parameters[PARTIAL_PAN_3], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_4, "Partial_Pan4", true, SAVE, &parameters[PARTIAL_PAN_4], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_5, "Partial_Pan5", true, SAVE, &parameters[PARTIAL_PAN_5], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_6, "Partial_Pan6", true, SAVE, &parameters[PARTIAL_PAN_6], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_7, "Partial_Pan7", true, SAVE, &parameters[PARTIAL_PAN_7], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_8, "Partial_Pan8", true, SAVE, &parameters[PARTIAL_PAN_8], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_9, "Partial_Pan9", true, SAVE, &parameters[PARTIAL_PAN_9], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_10, "Partial_Pan10", true, SAVE, &parameters[PARTIAL_PAN_10], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_11, "Partial_Pan11", true, SAVE, &parameters[PARTIAL_PAN_11], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_12, "Partial_Pan12", true, SAVE, &parameters[PARTIAL_PAN_12], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_13, "Partial_Pan13", true, SAVE, &parameters[PARTIAL_PAN_13], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_14, "Partial_Pan14", true, SAVE, &parameters[PARTIAL_PAN_14], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_15, "Partial_Pan15", true, SAVE, &parameters[PARTIAL_PAN_15], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_16, "Partial_Pan16", true, SAVE, &parameters[PARTIAL_PAN_16], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_17, "Partial_Pan17", true, SAVE, &parameters[PARTIAL_PAN_17], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_18, "Partial_Pan18", true, SAVE, &parameters[PARTIAL_PAN_18], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_19, "Partial_Pan19", true, SAVE, &parameters[PARTIAL_PAN_19], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_20, "Partial_Pan20", true, SAVE, &parameters[PARTIAL_PAN_20], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_21, "Partial_Pan21", true, SAVE, &parameters[PARTIAL_PAN_21], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_22, "Partial_Pan22", true, SAVE, &parameters[PARTIAL_PAN_22], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_23, "Partial_Pan23", true, SAVE, &parameters[PARTIAL_PAN_23], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_24, "Partial_Pan24", true, SAVE, &parameters[PARTIAL_PAN_24], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_25, "Partial_Pan25", true, SAVE, &parameters[PARTIAL_PAN_25], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_26, "Partial_Pan26", true, SAVE, &parameters[PARTIAL_PAN_26], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_27, "Partial_Pan27", true, SAVE, &parameters[PARTIAL_PAN_27], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_28, "Partial_Pan28", true, SAVE, &parameters[PARTIAL_PAN_28], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_29, "Partial_Pan29", true, SAVE, &parameters[PARTIAL_PAN_29], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_30, "Partial_Pan30", true, SAVE, &parameters[PARTIAL_PAN_30], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_31, "Partial_Pan31", true, SAVE, &parameters[PARTIAL_PAN_31], -1.0, 1.0);
    addFloatParam(PARTIAL_PAN_32, "Partial_Pan32", true, SAVE, &parameters[PARTIAL_PAN_32], -1.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_1, "Partial_LfoAmt1", true, SAVE, &parameters[PARTIAL_LFO_AMT_1], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_2, "Partial_LfoAmt2", true, SAVE, &parameters[PARTIAL_LFO_AMT_2], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_3, "Partial_LfoAmt3", true, SAVE, &parameters[PARTIAL_LFO_AMT_3], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_4, "Partial_LfoAmt4", true, SAVE, &parameters[PARTIAL_LFO_AMT_4], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_5, "Partial_LfoAmt5", true, SAVE, &parameters[PARTIAL_LFO_AMT_5], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_6, "Partial_LfoAmt6", true, SAVE, &parameters[PARTIAL_LFO_AMT_6], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_7, "Partial_LfoAmt7", true, SAVE, &parameters[PARTIAL_LFO_AMT_7], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_8, "Partial_LfoAmt8", true, SAVE, &parameters[PARTIAL_LFO_AMT_8], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_9, "Partial_LfoAmt9", true, SAVE, &parameters[PARTIAL_LFO_AMT_9], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_10, "Partial_LfoAmt10", true, SAVE, &parameters[PARTIAL_LFO_AMT_10], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_11, "Partial_LfoAmt11", true, SAVE, &parameters[PARTIAL_LFO_AMT_11], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_12, "Partial_LfoAmt12", true, SAVE, &parameters[PARTIAL_LFO_AMT_12], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_13, "Partial_LfoAmt13", true, SAVE, &parameters[PARTIAL_LFO_AMT_13], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_14, "Partial_LfoAmt14", true, SAVE, &parameters[PARTIAL_LFO_AMT_14], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_15, "Partial_LfoAmt15", true, SAVE, &parameters[PARTIAL_LFO_AMT_15], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_16, "Partial_LfoAmt16", true, SAVE, &parameters[PARTIAL_LFO_AMT_16], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_17, "Partial_LfoAmt17", true, SAVE, &parameters[PARTIAL_LFO_AMT_17], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_18, "Partial_LfoAmt18", true, SAVE, &parameters[PARTIAL_LFO_AMT_18], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_19, "Partial_LfoAmt19", true, SAVE, &parameters[PARTIAL_LFO_AMT_19], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_20, "Partial_LfoAmt20", true, SAVE, &parameters[PARTIAL_LFO_AMT_20], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_21, "Partial_LfoAmt21", true, SAVE, &parameters[PARTIAL_LFO_AMT_21], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_22, "Partial_LfoAmt22", true, SAVE, &parameters[PARTIAL_LFO_AMT_22], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_23, "Partial_LfoAmt23", true, SAVE, &parameters[PARTIAL_LFO_AMT_23], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_24, "Partial_LfoAmt24", true, SAVE, &parameters[PARTIAL_LFO_AMT_24], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_25, "Partial_LfoAmt25", true, SAVE, &parameters[PARTIAL_LFO_AMT_25], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_26, "Partial_LfoAmt26", true, SAVE, &parameters[PARTIAL_LFO_AMT_26], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_27, "Partial_LfoAmt27", true, SAVE, &parameters[PARTIAL_LFO_AMT_27], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_28, "Partial_LfoAmt28", true, SAVE, &parameters[PARTIAL_LFO_AMT_28], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_29, "Partial_LfoAmt29", true, SAVE, &parameters[PARTIAL_LFO_AMT_29], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_30, "Partial_LfoAmt30", true, SAVE, &parameters[PARTIAL_LFO_AMT_30], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_31, "Partial_LfoAmt31", true, SAVE, &parameters[PARTIAL_LFO_AMT_31], 0.0, 1.0);
    addFloatParam(PARTIAL_LFO_AMT_32, "Partial_LfoAmt32", true, SAVE, &parameters[PARTIAL_LFO_AMT_32], 0.0, 1.0);
    addFloatParam(PARTIAL_ATTACK_1, "Partial_Attack1", true, SAVE, &parameters[PARTIAL_ATTACK_1], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_2, "Partial_Attack2", true, SAVE, &parameters[PARTIAL_ATTACK_2], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_3, "Partial_Attack3", true, SAVE, &parameters[PARTIAL_ATTACK_3], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_4, "Partial_Attack4", true, SAVE, &parameters[PARTIAL_ATTACK_4], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_5, "Partial_Attack5", true, SAVE, &parameters[PARTIAL_ATTACK_5], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_6, "Partial_Attack6", true, SAVE, &parameters[PARTIAL_ATTACK_6], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_7, "Partial_Attack7", true, SAVE, &parameters[PARTIAL_ATTACK_7], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_8, "Partial_Attack8", true, SAVE, &parameters[PARTIAL_ATTACK_8], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_9, "Partial_Attack9", true, SAVE, &parameters[PARTIAL_ATTACK_9], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_10, "Partial_Attack10", true, SAVE, &parameters[PARTIAL_ATTACK_10], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_11, "Partial_Attack11", true, SAVE, &parameters[PARTIAL_ATTACK_11], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_12, "Partial_Attack12", true, SAVE, &parameters[PARTIAL_ATTACK_12], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_13, "Partial_Attack13", true, SAVE, &parameters[PARTIAL_ATTACK_13], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_14, "Partial_Attack14", true, SAVE, &parameters[PARTIAL_ATTACK_14], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_15, "Partial_Attack15", true, SAVE, &parameters[PARTIAL_ATTACK_15], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_16, "Partial_Attack16", true, SAVE, &parameters[PARTIAL_ATTACK_16], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_17, "Partial_Attack17", true, SAVE, &parameters[PARTIAL_ATTACK_17], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_18, "Partial_Attack18", true, SAVE, &parameters[PARTIAL_ATTACK_18], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_19, "Partial_Attack19", true, SAVE, &parameters[PARTIAL_ATTACK_19], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_20, "Partial_Attack20", true, SAVE, &parameters[PARTIAL_ATTACK_20], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_21, "Partial_Attack21", true, SAVE, &parameters[PARTIAL_ATTACK_21], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_22, "Partial_Attack22", true, SAVE, &parameters[PARTIAL_ATTACK_22], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_23, "Partial_Attack23", true, SAVE, &parameters[PARTIAL_ATTACK_23], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_24, "Partial_Attack24", true, SAVE, &parameters[PARTIAL_ATTACK_24], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_25, "Partial_Attack25", true, SAVE, &parameters[PARTIAL_ATTACK_25], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_26, "Partial_Attack26", true, SAVE, &parameters[PARTIAL_ATTACK_26], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_27, "Partial_Attack27", true, SAVE, &parameters[PARTIAL_ATTACK_27], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_28, "Partial_Attack28", true, SAVE, &parameters[PARTIAL_ATTACK_28], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_29, "Partial_Attack29", true, SAVE, &parameters[PARTIAL_ATTACK_29], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_30, "Partial_Attack30", true, SAVE, &parameters[PARTIAL_ATTACK_30], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_31, "Partial_Attack31", true, SAVE, &parameters[PARTIAL_ATTACK_31], 0.001, 10.0);
    addFloatParam(PARTIAL_ATTACK_32, "Partial_Attack32", true, SAVE, &parameters[PARTIAL_ATTACK_32], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_1, "Partial_Decay1", true, SAVE, &parameters[PARTIAL_DECAY_1], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_2, "Partial_Decay2", true, SAVE, &parameters[PARTIAL_DECAY_2], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_3, "Partial_Decay3", true, SAVE, &parameters[PARTIAL_DECAY_3], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_4, "Partial_Decay4", true, SAVE, &parameters[PARTIAL_DECAY_4], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_5, "Partial_Decay5", true, SAVE, &parameters[PARTIAL_DECAY_5], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_6, "Partial_Decay6", true, SAVE, &parameters[PARTIAL_DECAY_6], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_7, "Partial_Decay7", true, SAVE, &parameters[PARTIAL_DECAY_7], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_8, "Partial_Decay8", true, SAVE, &parameters[PARTIAL_DECAY_8], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_9, "Partial_Decay9", true, SAVE, &parameters[PARTIAL_DECAY_9], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_10, "Partial_Decay10", true, SAVE, &parameters[PARTIAL_DECAY_10], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_11, "Partial_Decay11", true, SAVE, &parameters[PARTIAL_DECAY_11], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_12, "Partial_Decay12", true, SAVE, &parameters[PARTIAL_DECAY_12], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_13, "Partial_Decay13", true, SAVE, &parameters[PARTIAL_DECAY_13], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_14, "Partial_Decay14", true, SAVE, &parameters[PARTIAL_DECAY_14], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_15, "Partial_Decay15", true, SAVE, &parameters[PARTIAL_DECAY_15], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_16, "Partial_Decay16", true, SAVE, &parameters[PARTIAL_DECAY_16], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_17, "Partial_Decay17", true, SAVE, &parameters[PARTIAL_DECAY_17], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_18, "Partial_Decay18", true, SAVE, &parameters[PARTIAL_DECAY_18], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_19, "Partial_Decay19", true, SAVE, &parameters[PARTIAL_DECAY_19], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_20, "Partial_Decay20", true, SAVE, &parameters[PARTIAL_DECAY_20], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_21, "Partial_Decay21", true, SAVE, &parameters[PARTIAL_DECAY_21], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_22, "Partial_Decay22", true, SAVE, &parameters[PARTIAL_DECAY_22], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_23, "Partial_Decay23", true, SAVE, &parameters[PARTIAL_DECAY_23], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_24, "Partial_Decay24", true, SAVE, &parameters[PARTIAL_DECAY_24], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_25, "Partial_Decay25", true, SAVE, &parameters[PARTIAL_DECAY_25], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_26, "Partial_Decay26", true, SAVE, &parameters[PARTIAL_DECAY_26], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_27, "Partial_Decay27", true, SAVE, &parameters[PARTIAL_DECAY_27], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_28, "Partial_Decay28", true, SAVE, &parameters[PARTIAL_DECAY_28], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_29, "Partial_Decay29", true, SAVE, &parameters[PARTIAL_DECAY_29], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_30, "Partial_Decay30", true, SAVE, &parameters[PARTIAL_DECAY_30], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_31, "Partial_Decay31", true, SAVE, &parameters[PARTIAL_DECAY_31], 0.001, 10.0);
    addFloatParam(PARTIAL_DECAY_32, "Partial_Decay32", true, SAVE, &parameters[PARTIAL_DECAY_32], 0.001, 10.0);
    addFloatParam(PARTIAL_SUSTAIN_1, "Partial_Sustain1", true, SAVE, &parameters[PARTIAL_SUSTAIN_1], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_2, "Partial_Sustain2", true, SAVE, &parameters[PARTIAL_SUSTAIN_2], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_3, "Partial_Sustain3", true, SAVE, &parameters[PARTIAL_SUSTAIN_3], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_4, "Partial_Sustain4", true, SAVE, &parameters[PARTIAL_SUSTAIN_4], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_5, "Partial_Sustain5", true, SAVE, &parameters[PARTIAL_SUSTAIN_5], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_6, "Partial_Sustain6", true, SAVE, &parameters[PARTIAL_SUSTAIN_6], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_7, "Partial_Sustain7", true, SAVE, &parameters[PARTIAL_SUSTAIN_7], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_8, "Partial_Sustain8", true, SAVE, &parameters[PARTIAL_SUSTAIN_8], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_9, "Partial_Sustain9", true, SAVE, &parameters[PARTIAL_SUSTAIN_9], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_10, "Partial_Sustain10", true, SAVE, &parameters[PARTIAL_SUSTAIN_10], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_11, "Partial_Sustain11", true, SAVE, &parameters[PARTIAL_SUSTAIN_11], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_12, "Partial_Sustain12", true, SAVE, &parameters[PARTIAL_SUSTAIN_12], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_13, "Partial_Sustain13", true, SAVE, &parameters[PARTIAL_SUSTAIN_13], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_14, "Partial_Sustain14", true, SAVE, &parameters[PARTIAL_SUSTAIN_14], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_15, "Partial_Sustain15", true, SAVE, &parameters[PARTIAL_SUSTAIN_15], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_16, "Partial_Sustain16", true, SAVE, &parameters[PARTIAL_SUSTAIN_16], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_17, "Partial_Sustain17", true, SAVE, &parameters[PARTIAL_SUSTAIN_17], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_18, "Partial_Sustain18", true, SAVE, &parameters[PARTIAL_SUSTAIN_18], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_19, "Partial_Sustain19", true, SAVE, &parameters[PARTIAL_SUSTAIN_19], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_20, "Partial_Sustain20", true, SAVE, &parameters[PARTIAL_SUSTAIN_20], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_21, "Partial_Sustain21", true, SAVE, &parameters[PARTIAL_SUSTAIN_21], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_22, "Partial_Sustain22", true, SAVE, &parameters[PARTIAL_SUSTAIN_22], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_23, "Partial_Sustain23", true, SAVE, &parameters[PARTIAL_SUSTAIN_23], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_24, "Partial_Sustain24", true, SAVE, &parameters[PARTIAL_SUSTAIN_24], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_25, "Partial_Sustain25", true, SAVE, &parameters[PARTIAL_SUSTAIN_25], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_26, "Partial_Sustain26", true, SAVE, &parameters[PARTIAL_SUSTAIN_26], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_27, "Partial_Sustain27", true, SAVE, &parameters[PARTIAL_SUSTAIN_27], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_28, "Partial_Sustain28", true, SAVE, &parameters[PARTIAL_SUSTAIN_28], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_29, "Partial_Sustain29", true, SAVE, &parameters[PARTIAL_SUSTAIN_29], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_30, "Partial_Sustain30", true, SAVE, &parameters[PARTIAL_SUSTAIN_30], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_31, "Partial_Sustain31", true, SAVE, &parameters[PARTIAL_SUSTAIN_31], 0.0, 1.0);
    addFloatParam(PARTIAL_SUSTAIN_32, "Partial_Sustain32", true, SAVE, &parameters[PARTIAL_SUSTAIN_32], 0.0, 1.0);
    addFloatParam(PARTIAL_RELEASE_1, "Partial_Release1", true, SAVE, &parameters[PARTIAL_RELEASE_1], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_2, "Partial_Release2", true, SAVE, &parameters[PARTIAL_RELEASE_2], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_3, "Partial_Release3", true, SAVE, &parameters[PARTIAL_RELEASE_3], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_4, "Partial_Release4", true, SAVE, &parameters[PARTIAL_RELEASE_4], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_5, "Partial_Release5", true, SAVE, &parameters[PARTIAL_RELEASE_5], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_6, "Partial_Release6", true, SAVE, &parameters[PARTIAL_RELEASE_6], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_7, "Partial_Release7", true, SAVE, &parameters[PARTIAL_RELEASE_7], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_8, "Partial_Release8", true, SAVE, &parameters[PARTIAL_RELEASE_8], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_9, "Partial_Release9", true, SAVE, &parameters[PARTIAL_RELEASE_9], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_10, "Partial_Release10", true, SAVE, &parameters[PARTIAL_RELEASE_10], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_11, "Partial_Release11", true, SAVE, &parameters[PARTIAL_RELEASE_11], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_12, "Partial_Release12", true, SAVE, &parameters[PARTIAL_RELEASE_12], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_13, "Partial_Release13", true, SAVE, &parameters[PARTIAL_RELEASE_13], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_14, "Partial_Release14", true, SAVE, &parameters[PARTIAL_RELEASE_14], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_15, "Partial_Release15", true, SAVE, &parameters[PARTIAL_RELEASE_15], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_16, "Partial_Release16", true, SAVE, &parameters[PARTIAL_RELEASE_16], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_17, "Partial_Release17", true, SAVE, &parameters[PARTIAL_RELEASE_17], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_18, "Partial_Release18", true, SAVE, &parameters[PARTIAL_RELEASE_18], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_19, "Partial_Release19", true, SAVE, &parameters[PARTIAL_RELEASE_19], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_20, "Partial_Release20", true, SAVE, &parameters[PARTIAL_RELEASE_20], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_21, "Partial_Release21", true, SAVE, &parameters[PARTIAL_RELEASE_21], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_22, "Partial_Release22", true, SAVE, &parameters[PARTIAL_RELEASE_22], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_23, "Partial_Release23", true, SAVE, &parameters[PARTIAL_RELEASE_23], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_24, "Partial_Release24", true, SAVE, &parameters[PARTIAL_RELEASE_24], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_25, "Partial_Release25", true, SAVE, &parameters[PARTIAL_RELEASE_25], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_26, "Partial_Release26", true, SAVE, &parameters[PARTIAL_RELEASE_26], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_27, "Partial_Release27", true, SAVE, &parameters[PARTIAL_RELEASE_27], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_28, "Partial_Release28", true, SAVE, &parameters[PARTIAL_RELEASE_28], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_29, "Partial_Release29", true, SAVE, &parameters[PARTIAL_RELEASE_29], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_30, "Partial_Release30", true, SAVE, &parameters[PARTIAL_RELEASE_30], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_31, "Partial_Release31", true, SAVE, &parameters[PARTIAL_RELEASE_31], 0.001, 10.0);
    addFloatParam(PARTIAL_RELEASE_32, "Partial_Release32", true, SAVE, &parameters[PARTIAL_RELEASE_32], 0.001, 10.0);
    addFloatParam(NOISE_LEVEL, "Noise_Level", true, SAVE, &parameters[NOISE_LEVEL], 0.0, 1.0);
    addFloatParam(NOISE_LFO_AMT, "Noise_LfoAmt", true, SAVE, &parameters[NOISE_LFO_AMT], 0.0, 1.0);
    addFloatParam(NOISE_PAN, "Noise_Pan", true, SAVE, &parameters[NOISE_PAN], -1.0, 1.0);
    addFloatParam(NOISE_ATTACK, "Noise_Attack", true, SAVE, &parameters[NOISE_ATTACK], 0.001, 10.0);
    addFloatParam(NOISE_DECAY, "Noise_Decay", true, SAVE, &parameters[NOISE_DECAY], 0.001, 10.0);
    addFloatParam(NOISE_SUSTAIN, "Noise_Sustain", true, SAVE, &parameters[NOISE_SUSTAIN], 0.0, 1.0);
    addFloatParam(NOISE_RELEASE, "Noise_Release", true, SAVE, &parameters[NOISE_RELEASE], 0.001, 10.0);
    addFloatParam(LFO_FREQ, "Lfo_Frequency", true, SAVE, &parameters[LFO_FREQ], 0.0, 100.0);
    addIntParam(LFO_SHAPE, "Lfo_Shape", true, SAVE, &lfoShape, SINE_WAVE_TABLE, NUMBER_OF_WAVE_TABLES);
    addIntParam(NUMBER_OF_VOICES, "Number_Of_Voices", true, SAVE, &numberOfVoices, 1, 16);
    addIntParam(SCALE, "Scale", true, SAVE, &scale, 1, numberOfScales+1);
    addIntParam(SCALE_ROOT, "Scale_Root", true, SAVE, &scaleRoot, 1, 12);
}


const String PlusAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String PlusAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool PlusAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool PlusAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

double PlusAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PlusAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int PlusAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PlusAudioProcessor::setCurrentProgram (int index)
{
}

const String PlusAudioProcessor::getProgramName (int index)
{
    return String();
}

void PlusAudioProcessor::changeProgramName (int index, const String& newName)
{
}


void PlusAudioProcessor::runAfterParamChange(int paramIndex,UpdateFromFlags updateFromFlag)
{
    getParam(paramIndex)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    switch (paramIndex) {
        case LFO_FREQ:
            sendActionMessage("LFO Frequency");
            break;
        case LFO_SHAPE:
            sendActionMessage("LFO Shape");
            break;
        case ATTACK:
        case DECAY:
        case SUSTAIN:
        case RELEASE:
            sendActionMessage("Envelope");
            break;
        default:
            break;
    }
}

void PlusAudioProcessor::runAfterParamGroupUpdate()
{
    getParam(ATTACK)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(DECAY)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(SUSTAIN)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(RELEASE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(STRETCH)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(STRETCH_FINE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(STRETCH_ENV_AMT)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(STRETCH_ENV_AMT_FINE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_1)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_2)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_3)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_4)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_5)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_6)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_7)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_8)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_9)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_10)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_11)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_12)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_13)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_14)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_15)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_16)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_17)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_18)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_19)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_20)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_21)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_22)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_23)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_24)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_25)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_26)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_27)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_28)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_29)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_30)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_31)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_32)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_1)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_2)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_3)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_4)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_5)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_6)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_7)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_8)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_9)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_10)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_11)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_12)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_13)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_14)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_15)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_16)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_17)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_18)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_19)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_20)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_21)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_22)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_23)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_24)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_25)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_26)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_27)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_28)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_29)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_30)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_31)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_32)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_1)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_2)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_3)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_4)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_5)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_6)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_7)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_8)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_9)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_10)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_11)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_12)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_13)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_14)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_15)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_16)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_17)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_18)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_19)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_20)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_21)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_22)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_23)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_24)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_25)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_26)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_27)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_28)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_29)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_30)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_31)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_PAN_32)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_1)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_2)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_3)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_4)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_5)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_6)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_7)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_8)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_9)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_10)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_11)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_12)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_13)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_14)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_15)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_16)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_17)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_18)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_19)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_20)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_21)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_22)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_23)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_24)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_25)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_26)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_27)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_28)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_29)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_30)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_31)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_LFO_AMT_32)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(NOISE_LEVEL)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(NOISE_LFO_AMT)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(NOISE_PAN)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(NOISE_ATTACK)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(NOISE_DECAY)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(NOISE_SUSTAIN)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(NOISE_RELEASE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(LFO_FREQ)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(LFO_SHAPE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(NUMBER_OF_VOICES)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(SCALE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(SCALE_ROOT)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
}

const String PlusAudioProcessor::getParameterText (int index)
{
    return String (getParameter(index), 1024);
}

//==============================================================================
void PlusAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    synth.setCurrentPlaybackSampleRate (sampleRate);
}

void PlusAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void PlusAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    buffer.clear();
    int numSamples = buffer.getNumSamples();
    keyboardState.processNextMidiBuffer(midiMessages, 0, numSamples, true);
    synth.renderNextBlock(buffer, midiMessages, 0, numSamples);
}

//==============================================================================
bool PlusAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PlusAudioProcessor::createEditor()
{
    return new PlusAudioProcessorEditor (*this);
}

//==============================================================================
void PlusAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    //Save all the parameter values into an XML tag with name JucePlugin_Name.
    XmlElement xml(JucePlugin_Name);
    saveXml(&xml,false,true);
    //Save it as binary data
    copyXmlToBinary (xml, destData);
}

void PlusAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    //Convert the binary data saved in getStateInformation(...) back into XML.
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    // Check that it is valid XML and that the tag has name JucePlugin_Name.
    if (xmlState != 0 && xmlState->getTagName()==JucePlugin_Name){
        //Preload XML values into memory
        readXml(xmlState, true);
        //Update the parameter values from the preloaded XML values
        updateProcessorHostAndUiFromXml(true,true,true);
        initVoices();
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PlusAudioProcessor();
}

