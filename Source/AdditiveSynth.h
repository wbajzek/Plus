//
//  AdditiveSynth.h
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#ifndef Plus_AdditiveSynth_h
#define Plus_AdditiveSynth_h

const int numVoices = 8;
const int numPartials = 16;

enum Parameters
{
    // envelope
    ATTACK,
    DECAY,
    SUSTAIN,
    RELEASE,
    STRETCH,
    STRETCH_ENV_AMT,
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
    PARTIAL_LEVEL_ENV_AMT,
    NUMBER_OF_PARAMETERS
};

#include "../JuceLibraryCode/JuceHeader.h"
#include "AdditiveSynthSound.h"
#include "AdditiveSynthVoice.h"

#endif
