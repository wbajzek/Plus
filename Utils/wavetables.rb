wavetable_length = 32.0 * 1024.0

File.open('../Source/WaveTables/WaveTables.h','w') do |f|
  f.write <<HEADER
/*
  ==============================================================================

    WaveTables.h
    Created: 6 Dec 2014 3:02:24pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef WAVETABLES_H_INCLUDED
#define WAVETABLES_H_INCLUDED

const unsigned int waveTableLength = #{wavetable_length.to_i};
const unsigned long i32waveTableLength = waveTableLength << 16;

#include "SineWaveTable.h"
#include "SawWaveTable.h"
#include "RampWaveTable.h"

#endif  // WAVETABLES_H_INCLUDED
HEADER
end


File.open('../Source/WaveTables/SineWaveTable.h','w') do |f|
  f.write <<HEADER
/*
  ==============================================================================

    SineWavetable.h
    Created: 6 Dec 2014 3:02:24pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef SINEWAVETABLE_H_INCLUDED
#define SINEWAVETABLE_H_INCLUDED
HEADER


  f.write "const double sineWaveTable[] = {\n"
  phase = 0.0
  phase_increment = 2.0 * Math::PI / wavetable_length
  wavetable_length.to_i.times do
    f.write "#{Math::sin(phase)},\n"
    phase += phase_increment
  end
  f.write "};\n"

  f.write "#endif  // SINEWAVETABLE_H_INCLUDED\n"
end

File.open('../Source/WaveTables/SawWaveTable.h','w') do |f|
  f.write <<HEADER
/*
  ==============================================================================

    SawWavetable.h
    Created: 6 Dec 2014 3:02:24pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef SAWWAVETABLE_H_INCLUDED
#define SAWWAVETABLE_H_INCLUDED
HEADER

  f.write "const double sawWaveTable[] = {\n"
  phase = 1.0
  phase_increment = 2.0 / wavetable_length
  wavetable_length.to_i.times do
    f.write "#{phase},\n"
    phase -= phase_increment
  end
  f.write "};\n"

  f.write "#endif  // SAWWAVETABLE_H_INCLUDED\n"
end

File.open('../Source/WaveTables/RampWaveTable.h','w') do |f|
  f.write <<HEADER
/*
  ==============================================================================

    RampWavetable.h
    Created: 6 Dec 2014 3:02:24pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef RAMPWAVETABLE_H_INCLUDED
#define RAMPWAVETABLE_H_INCLUDED
HEADER

  f.write "const double rampWaveTable[] = {\n"
  phase = -1.0
  phase_increment = 2.0 / wavetable_length
  wavetable_length.to_i.times do
    f.write "#{phase},\n"
    phase += phase_increment
  end
  f.write "};\n"

  f.write "#endif  // RAMPWAVETABLE_H_INCLUDED\n"
end

