# unpack
files = Dir.glob('scl/*.scl')
BASE_FREQUENCY = 440.0
STEP_LIMIT = 12

def with_parsed(file, &block)
  File.open(file,'r') do |f|
    begin
      lines = f.readlines.map { |l| l.strip }.reject { |l| l.start_with? '!' }
      description, steps, *intervals = lines
      yield description, steps.to_i, intervals
    rescue
      puts "scale failed: #{file}"
    end
  end
end

def if_cents(interval)
  yield interval.to_f if interval.match(/\./)
end

def if_ratio(interval)
  if interval.match(/\//)
    fraction = interval.split('/')
    yield fraction[0].to_f / fraction[1].to_f
  elsif !interval.match(/\./)
    yield interval.to_f / 1.0
  end
end

def interpreted(frequency, input)
  interval, comment = input.split(/ /)
  if_cents(interval) { |cents| return frequency * (2.0 ** (cents / 1200.0)) }
  if_ratio(interval) { |ratio| return frequency * ratio }
end

scales = []

files.each do |file|
  with_parsed(file) do |description, steps, intervals|
    if steps.to_i == STEP_LIMIT && !description.empty?
      scale = {
        file: file,
        description: description,
        steps: steps.to_i,
        offsets: [ 1.0 ]
      }
      note = BASE_FREQUENCY.to_f
      intervals.each do |interval|
        note *= (2.0 ** (100.0 / 1200.0))
        adjusted = interpreted(BASE_FREQUENCY.to_f, interval)
        puts "#{ note } / #{ adjusted }"
        scale[:offsets] << adjusted / note.to_f
      end
      begin
        scale[:description].encode!(Encoding::ISO_8859_1)
        scales << scale
      rescue
        puts "scale failed: #{scale[:file]}"
      end
    end
  end
end

scales.sort! { |a,b| a[:description] <=> b[:description] }

File.open('../Source/Scales.h','w') do |f|
  f.write <<END
/*
  ==============================================================================

    Scales.h
    Created: 8 Dec 2014 3:02:24pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef SCALES_H_INCLUDED
#define SCALES_H_INCLUDED


struct Scale
{
  String scalaFileName;
  String description;
  int steps;
  double offsets[13];
};

const int numberOfScales = #{scales.count + 1};

const Scale scales[numberOfScales] = {
  {
    "",
    "12-Tone Equal Temperament",
    12,
    { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }
  },
END
  scales.each do |scale|
    f.write <<END
  {
    #{ scale[:file].inspect },
    #{ scale[:description].inspect },
    #{ scale[:steps] },
    { #{ scale[:offsets].join(', ') } }
  },
END
  end
  f.write "};\n"
  f.write "#endif  // SCALES_H_INCLUDED\n"
end
