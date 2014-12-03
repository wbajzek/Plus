//
//  AdditiveSynth.h
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#ifndef Plus_AdditiveSynth_h
#define Plus_AdditiveSynth_h

const int numVoices = 12;
const int numPartials = 32;
const int waveTableLength = 128 * 1024;

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
    NUMBER_OF_PARAMETERS
};

#define AU_LOGGING
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginParameters.h"
#include "AdditiveSynthSound.h"
#include "AdditiveSynthVoice.h"

#endif
