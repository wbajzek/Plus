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

enum WaveTables {
  SINE_WAVE_TABLE = 0,
  TRIANGLE_WAVE_TABLE,
  SAW_WAVE_TABLE,
  RAMP_WAVE_TABLE,
  WHITE_NOISE_WAVE_TABLE,
  NUMBER_OF_WAVE_TABLES
};

#include "SineWaveTable.h"
#include "TriangleWaveTable.h"
#include "SawWaveTable.h"
#include "RampWaveTable.h"
#include "WhiteNoiseWaveTable.h"

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

File.open('../Source/WaveTables/TriangleWaveTable.h','w') do |f|
  f.write <<HEADER
/*
  ==============================================================================

    TriangleWavetable.h
    Created: 6 Dec 2014 3:02:24pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef TRIANGLEWAVETABLE_H_INCLUDED
#define TRIANGLEWAVETABLE_H_INCLUDED
HEADER

  f.write "const double triangleWaveTable[] = {\n"
  phase = 0
  phase_increment = 2.0 * Math::PI / wavetable_length
  wavetable_length.to_i.times do
    value = phase * 2.0 / Math::PI
    if phase < 0
      value = 1.0 + value
    else
      value = 1.0 - value
    end
    f.write "#{value},\n"
    if (phase += phase_increment) >= Math::PI
      phase -= 2.0 * Math::PI
    end
  end
  f.write "};\n"

  f.write "#endif  // TRIANGLEWAVETABLE_H_INCLUDED\n"
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

  rise = 100
  fall = wavetable_length.to_i - rise
  phase = 1.0
  phase_increment = 2.0 / fall
  fall.times do
    f.write "#{phase},\n"
    phase -= phase_increment
  end
  # smooth rise back to top
  phase = -1.0
  phase_increment = 2.0 / rise
  rise.times do
    f.write "#{phase},\n"
    phase += phase_increment
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

  rise = wavetable_length.to_i - 100
  fall = wavetable_length.to_i - rise
  phase = -1.0
  phase_increment = 2.0 / rise
  rise.times do
    f.write "#{phase},\n"
    phase += phase_increment
  end
  # smooth fall to bottom
  phase = 1.0
  phase_increment = 2.0 / fall
  fall.times do
    f.write "#{phase},\n"
    phase -= phase_increment
  end
  f.write "};\n"

  f.write "#endif  // RAMPWAVETABLE_H_INCLUDED\n"
end


File.open('../Source/WaveTables/WhiteNoiseWaveTable.h','w') do |f|
  f.write <<HEADER
/*
  ==============================================================================

    WhiteNoiseWavetable.h
    Created: 6 Dec 2014 3:02:24pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef WHITENOISEWAVETABLE_H_INCLUDED
#define WHITENOISEWAVETABLE_H_INCLUDED
HEADER

  f.write "const double whiteNoiseWaveTable[] = {\n"

  wavetable_length.to_i.times do
    f.write "#{ rand(-1.0..1.0) },\n"
  end
  f.write "};\n"

  f.write "#endif  // WHITENOISEWAVETABLE_H_INCLUDED\n"
end

