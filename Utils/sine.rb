wavetable_length = 32.0 * 1024.0
phase = 0.0
phase_increment = 2.0 * Math::PI / wavetable_length

File.open('../Source/SineWavetable.h','w') do |f|
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


  f.write "const unsigned int waveTableLength = #{wavetable_length};\n"
  f.write "const unsigned long i32waveTableLength = waveTableLength * 65536;\n"
  f.write "const float waveTable[] = {\n"
  wavetable_length.to_i.times do
    f.write "#{Math::sin(phase)},\n"
    phase += phase_increment
  end
  f.write "};\n"

  f.write "#endif  // SINEWAVETABLE_H_INCLUDED\n"
end

