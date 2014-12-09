files = Dir.glob('scl/*.scl')
BASE_FREQUENCY = 1.0
STEP_LIMIT = 12

def with_parsed(file, &block)
  File.open(file,'r:iso-8859-1') do |f|
    # begin
      lines = f.readlines.map { |l| l.strip }.reject { |l| l.start_with? '!' }
      description, steps, *intervals = lines
      yield description, steps.to_i, intervals
    # rescue
    #   puts "scale failed: #{file}"
    # end
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
    if steps.to_i == STEP_LIMIT
      scale = {
        description: description,
        steps: steps.to_i,
        offsets: [ 0.0 ]
      }
      note = BASE_FREQUENCY.to_f
      intervals.each do |interval|
        note *= 2.0
        scale[:offsets] << interpreted(BASE_FREQUENCY.to_f, interval) / note.to_f
      end
      scales << scale
    end
  end
end

File.open('../Source/Scales.h','w') do |f|
  f.write <<END
struct Scale
{
  char* description[100];
  int steps;
  double offsets;
};

Scale *scales = new Scale[#{ scales.count }];
END
  scales.each_with_index do |scale, index|
    f.write <<END

scales[#{index}] = {
  "#{ scale[:description] }",
  #{ scale[:steps] },
  { #{ scale[:offsets].join(', ') } }
};
END
  end
end
