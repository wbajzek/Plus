//
//  AdditiveSynthVoice.cpp
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#include "AdditiveSynth.h"

AdditiveSynthVoice::AdditiveSynthVoice(float* parameters, int* lfoShape, int* scale, int* scaleRoot)
{
    localParameters = parameters;
    localLfoShape = lfoShape;
    localScale = scale;
    localScaleRoot = scaleRoot;
    noiseVoice.setWaveTable(WHITE_NOISE_WAVE_TABLE);
}

AdditiveSynthVoice::~AdditiveSynthVoice()
{
}

bool AdditiveSynthVoice::canPlaySound (SynthesiserSound* sound)
{
    return true;
}

void AdditiveSynthVoice::startNote (const int midiNoteNumber, const float midiVelocity, SynthesiserSound* /*sound*/, const int currentPitchWheelPosition)
{
    noteNumber = midiNoteNumber;
    freq = calculateFrequency(currentPitchWheelPosition);
    Adsr adsr;
    adsr.attack = localParameters[ATTACK];
    adsr.decay = localParameters[DECAY];
    adsr.sustainLevel = localParameters[SUSTAIN];
    adsr.release = localParameters[RELEASE];
    stretchEnvelope.setAdsr(adsr);
    stretchEnvelope.trigger();
    Adsr partialEnvelopes[numPartials];
    for (int i = 0; i < numPartials; i++)
    {
        Adsr adsr;
        adsr.attack = localParameters[PartialAttackToParamMapping[i]];
        adsr.decay = localParameters[PartialDecayToParamMapping[i]];
        adsr.sustainLevel = localParameters[PartialSustainToParamMapping[i]];
        adsr.release = localParameters[PartialReleaseToParamMapping[i]];
        partialEnvelopes[i] = adsr;
        voice.trigger(midiVelocity);
        voiceIsActive = true;
    }
    voice.setAdsrs(partialEnvelopes);
    Adsr noiseAdsr;
    noiseAdsr.attack = localParameters[NOISE_ATTACK];
    noiseAdsr.decay = localParameters[NOISE_DECAY];
    noiseAdsr.sustainLevel = localParameters[NOISE_SUSTAIN];
    noiseAdsr.release = localParameters[NOISE_RELEASE];
    noiseVoice.setAdsr(adsr);
    noiseVoice.trigger(midiVelocity);
    lfo.setFrequency(localParameters[LFO_FREQ]);
    lfo.setWaveTable(*localLfoShape);
}

void AdditiveSynthVoice::stopNote (float velocity, const bool allowTailOff)
{
}

Frequency AdditiveSynthVoice::calculateFrequency(int currentPitchWheelPosition)
{
    float pbCents = ( (float)currentPitchWheelPosition / 16383.0) * (400.0) + -200.0;
    Frequency baseFreq = MidiMessage::getMidiNoteInHertz(noteNumber) * pow(2, pbCents/1200);
    Scale scale = getScale();
    int octaveNote = (noteNumber - getScaleRoot()) % 12;
    return baseFreq * scale.offsets[octaveNote];
}

void AdditiveSynthVoice::pitchWheelMoved (const int currentPitchWheelPosition)
{
    freq = calculateFrequency(currentPitchWheelPosition);
}

void AdditiveSynthVoice::controllerMoved (const int controllerNumber, const int newValue)
{
    switch (controllerNumber)
    {
        case MOD_WHEEL_CONTROL:
            modWheel = (float)newValue / 3.0 / 127.0;
            break;
        default:
            break;
    }
}

void AdditiveSynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (voiceIsActive && sampleRate > 0 && nyquist > 0)
    {
        const float stretchEnvAmtInc = localParameters[STRETCH_ENV_AMT] + localParameters[STRETCH_ENV_AMT_FINE];
        const int numChannels = outputBuffer.getNumChannels();
        jassert(numChannels == 1 || numChannels == 2);

        while (--numSamples >= 0)
        {
            Amplitude currentSampleLeft = 0.0;
            Amplitude currentSampleRight = 0.0;
            Amplitude lfoLevel = lfo.output();
            float stretchEnvAmt = stretchEnvAmtInc * stretchEnvelope.amplitude();
            float stretch = localParameters[STRETCH] + localParameters[STRETCH_FINE];
            Frequency localFreq = freq + (freq * modWheel * lfoLevel);

            Frequency partialFrequencies[numPartials] = { 0.0 };
            for (int i = 0; i < numPartials; i++)
            {
                if (localParameters[PartialLevelToParamMapping[i]] > 0.0)
                {
                    Frequency partialFreq = localFreq + (localFreq * localParameters[PartialTuneToParamMapping[i]]);
                    if (i > 0)
                    {
                        partialFreq += (localFreq * ((float)i + stretch));
                        partialFreq += partialFreq * stretch * stretchEnvAmt;
                    }
                    partialFrequencies[i] += partialFreq;
                }
                stretch += stretch;
            }
            voice.setFrequencies(partialFrequencies);
            tick();
            
            for (int i = 0; i < numPartials; i++)
            {
                if (20 < partialFrequencies[i] && partialFrequencies[i] < nyquist)
                {
                    Amplitude value = voice.samples[i]
                    * (localParameters[PartialLevelToParamMapping[i]] + (lfoLevel * localParameters[PartialLfoAmtToParamMapping[i]]));

                    if (numChannels == 1)
                        currentSampleLeft += value;
                    else
                    {
                        Amplitude panRight = (1.0 + localParameters[PartialPanToParamMapping[i]]) * 0.5;
                        Amplitude panLeft  = 1.0 - panRight;
                        currentSampleLeft += value * panLeft;
                        currentSampleRight += value * panRight;
                    }
                }
            }
            
            if (localParameters[NOISE_LEVEL] > 0.0)
            {
                Amplitude value = noiseVoice.currentSample * (localParameters[NOISE_LEVEL] + (lfoLevel * localParameters[NOISE_LFO_AMT]));
                
                if (numChannels == 1)
                    currentSampleLeft += value;
                else
                {
                    Amplitude panRight = (1.0 + localParameters[NOISE_PAN]) * 0.5;
                    Amplitude panLeft  = 1.0 - panRight;
                    currentSampleLeft += value * panLeft;
                    currentSampleRight += value * panRight;
                }
            }
            
            if (numChannels == 1)
                outputBuffer.addSample(0, startSample, currentSampleLeft * 0.125);
            else
            {
                outputBuffer.addSample(0, startSample, currentSampleLeft * 0.125);
                outputBuffer.addSample(1, startSample, currentSampleRight * 0.125);
            }

            ++startSample;
        }
    }
}


void AdditiveSynthVoice::aftertouchChanged (int newAftertouchValue)
{

}

void AdditiveSynthVoice::setCurrentPlaybackSampleRate (double newRate)
{
    sampleRate = newRate;
    stretchEnvelope.setSampleRate(sampleRate);
    voice.setSampleRate(sampleRate);
    noiseVoice.setSampleRate(sampleRate);
    noiseVoice.setFrequency(sampleRate / waveTableLength);
    nyquist = sampleRate/2.0;
    lfo.setSampleRate(sampleRate);
}

bool AdditiveSynthVoice::isPlayingChannel (int midiChannel) const
{
    return true;
}

bool AdditiveSynthVoice::isVoiceActive() const
{

    return voiceIsActive;
}

void AdditiveSynthVoice::tick()
{
    bool keyIsDown = isKeyDown();
    stretchEnvelope.tick(keyIsDown);
    voiceIsActive = false;
    voice.tick(keyIsDown);
    voiceIsActive = voice.isActive();
    if (localParameters[NOISE_LEVEL] > 0.0 && noiseVoice.isActive())
    {
        noiseVoice.tick(keyIsDown);
        voiceIsActive = true;
    }
    lfo.tick();
}

void AdditiveSynthVoice::actionListenerCallback (const String &message)
{
    if (message.equalsIgnoreCase("LFO Frequency"))
        lfo.setFrequency(localParameters[LFO_FREQ]);
    else if (message.equalsIgnoreCase("LFO Shape"))
        lfo.setWaveTable(*localLfoShape);
    else if (message.equalsIgnoreCase("Envelope"))
    {
        Adsr adsr;
        adsr.attack = localParameters[ATTACK];
        adsr.decay = localParameters[DECAY];
        adsr.sustainLevel = localParameters[SUSTAIN];
        adsr.release = localParameters[RELEASE];
        stretchEnvelope.setAdsr(adsr);
    }
}
