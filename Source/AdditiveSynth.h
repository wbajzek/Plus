//
//  AdditiveSynth.h
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#ifndef Plus_AdditiveSynth_h
#define Plus_AdditiveSynth_h

const int numVoices = 16;
const int numPartials = 32;

enum Params
{
    ATTACK = 0,
    DECAY,
    SUSTAIN,
    RELEASE,
    STRETCH,
    STRETCH_FINE,
    STRETCH_ENV_AMT,
    STRETCH_ENV_AMT_FINE,
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
    NUMBER_OF_PARAMETERS
};

#define AU_LOGGING
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginParameters.h"
#include "AdditiveSynthSound.h"
#include "AdditiveSynthesiser.h"
#include "SineWavetable.h"
#include "AdditiveSynthVoice.h"

#endif
