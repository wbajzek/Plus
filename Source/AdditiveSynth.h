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
    STRETCH_ENV_AMT
};

#include "../JuceLibraryCode/JuceHeader.h"
#include "AdditiveSynthSound.h"
#include "AdditiveSynthVoice.h"

#endif
