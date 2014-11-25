//
//  AdditiveSynth.cpp
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#include "AdditiveSynth.h"

AdditiveSynthSound::AdditiveSynthSound()
{
}

bool AdditiveSynthSound::appliesToNote(const int /*midiNoteNumber*/)
{
    return true;
}
bool AdditiveSynthSound::appliesToChannel(const int /*midiChannel*/)
{
    return true;
}
