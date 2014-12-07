/*
  ==============================================================================

    WaveTables.h
    Created: 6 Dec 2014 3:02:24pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef WAVETABLES_H_INCLUDED
#define WAVETABLES_H_INCLUDED

const unsigned int waveTableLength = 32768;
const unsigned long i32waveTableLength = waveTableLength << 16;

#include "SineWaveTable.h"
#include "SawWaveTable.h"
#include "RampWaveTable.h"

#endif  // WAVETABLES_H_INCLUDED
