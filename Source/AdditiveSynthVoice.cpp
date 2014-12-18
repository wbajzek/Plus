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
    velocity = midiVelocity;
    envLevel = 0.001;
    samplesSinceTrigger = 0;

    envelope.setAdsr(localParameters[ATTACK], localParameters[DECAY], localParameters[SUSTAIN], localParameters[RELEASE]);
    envelope.trigger(velocity);
    for (int i = 0; i < numPartials; i++)
    {
        partialEnvelopeLevels[i] = 0.0;
        partialEnvelopes[i].setAdsr(localParameters[PartialAttackToParamMapping[i]], localParameters[PartialDecayToParamMapping[i]], localParameters[PartialSustainToParamMapping[i]], localParameters[PartialReleaseToParamMapping[i]]);
        partialEnvelopes[i].trigger(velocity);
        voiceIsActive = true;
    }
    noiseEnvelope.setAdsr(localParameters[NOISE_ATTACK], localParameters[NOISE_DECAY], localParameters[NOISE_SUSTAIN], localParameters[NOISE_RELEASE]);
    noiseEnvelope.trigger(velocity);
    lfo.setFrequency(localParameters[LFO_FREQ]);
    lfo.setWaveTable(*localLfoShape);

    for (int i = 0; i < numPartials; i++)
    {
        partialIndices[i] = 0.0;
    }
}

void AdditiveSynthVoice::stopNote (float velocity, const bool allowTailOff)
{
    samplesSinceTrigger = 0;
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
            float stretchEnvAmt = stretchEnvAmtInc * envLevel;
            float stretch = localParameters[STRETCH] + localParameters[STRETCH_FINE];
            Frequency localFreq = freq + (freq * modWheel * lfoLevel);

            for (int i = 0; i < numPartials; i++)
            {
                if (localParameters[PartialLevelToParamMapping[i]] > 0.0 && partialEnvelopeLevels[i] > 0.0)
                {
                    Frequency partialFreq = localFreq + (localFreq * localParameters[PartialTuneToParamMapping[i]]);
                    if (i > 0)
                    {
                        partialFreq += (localFreq * ((float)i + stretch));
                        partialFreq += partialFreq * stretch * stretchEnvAmt;
                    }
                    if (20 < partialFreq && partialFreq < nyquist)
                    {
                        // this '16' business is converting floating point to fixed for the sake of performance.
                        // and oh boy, does it improve performance.
                        const long increment = (long)(frqTI * partialFreq) << 16;

                        Amplitude value = sineWaveTable[((partialIndices[i]+0x8000) >> 16)]
                            * partialEnvelopeLevels[i] * (localParameters[PartialLevelToParamMapping[i]] + (lfoLevel * localParameters[PartialLfoAmtToParamMapping[i]]));

                        if (numChannels == 1)
                            currentSampleLeft += value;
                        else
                        {
                            Amplitude panRight = (1.0 + localParameters[PartialPanToParamMapping[i]]) / 2.0;
                            Amplitude panLeft  = 1.0 - panRight;
                            currentSampleLeft += value * panLeft;
                            currentSampleRight += value * panRight;
                        }

                        partialIndices[i] = partialIndices[i] + increment & ((waveTableLength << 16) - 1);
                    }
                }
                stretch += stretch;
            }
            
            if (localParameters[NOISE_LEVEL] > 0.0)
            {
                Amplitude value = noiseOscillator.tick();
                value *= noiseLevel * (localParameters[NOISE_LEVEL] + (lfoLevel * localParameters[NOISE_LFO_AMT]));
                
                if (numChannels == 1)
                    currentSampleLeft += value;
                else
                {
                    Amplitude panRight = (1.0 + localParameters[NOISE_PAN]) / 2.0;
                    Amplitude panLeft  = 1.0 - panRight;
                    currentSampleLeft += value * panLeft;
                    currentSampleRight += value * panRight;
                }
            }
            
            if (numChannels == 1)
                outputBuffer.addSample(0, startSample, currentSampleLeft / 8);
            else
            {
                outputBuffer.addSample(0, startSample, currentSampleLeft / 8);
                outputBuffer.addSample(1, startSample, currentSampleRight / 8);
            }

            ++startSample;
            tick();
        }
    }
}


void AdditiveSynthVoice::aftertouchChanged (int newAftertouchValue)
{

}

void AdditiveSynthVoice::setCurrentPlaybackSampleRate (double newRate)
{
    sampleRate = newRate;
    envelope.setSampleRate(sampleRate);
    for (int i = 0; i < numPartials; i++)
        partialEnvelopes[i].setSampleRate(sampleRate);
    noiseEnvelope.setSampleRate(sampleRate);
    noiseOscillator.setSampleRate(sampleRate);
    noiseOscillator.setFrequency(sampleRate);
    noiseOscillator.setWaveTable(NOISE_WAVE_TABLE);
    nyquist = sampleRate/2.0;
    frqTI = waveTableLength/sampleRate;
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
    envLevel = envelope.tick(keyIsDown);
    voiceIsActive = false;
    for (int i = 0; i < numPartials; i++)
    {
        if (localParameters[PartialLevelToParamMapping[i]] > 0.0)
        {
            partialEnvelopeLevels[i] = partialEnvelopes[i].tick(keyIsDown);
            voiceIsActive |= (partialEnvelopeLevels[i] != 0.0);            
        }
    }
    if (localParameters[NOISE_LEVEL] > 0.0)
    {
        noiseLevel = noiseEnvelope.tick(keyIsDown);
        voiceIsActive |= (noiseLevel != 0.0);
    }
    lfoLevel = lfo.tick();

    ++samplesSinceTrigger;
}

void AdditiveSynthVoice::actionListenerCallback (const String &message)
{
    if (message.equalsIgnoreCase("LFO Frequency"))
        lfo.setFrequency(localParameters[LFO_FREQ]);
    else if (message.equalsIgnoreCase("LFO Shape"))
        lfo.setWaveTable(*localLfoShape);
    else if (message.equalsIgnoreCase("Envelope"))
        envelope.setAdsr(localParameters[ATTACK], localParameters[DECAY], localParameters[SUSTAIN], localParameters[RELEASE]);
}
