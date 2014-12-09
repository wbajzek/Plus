//
//  AdditiveSynthVoice.cpp
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#include "AdditiveSynth.h"

AdditiveSynthVoice::AdditiveSynthVoice(float* parameters, int* lfoShape)
{
    localParameters = parameters;
    localLfoShape = lfoShape;
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
    lfoIndex = 0;
    velocity = midiVelocity;
    envLevel = 0.001;
    releaseEnvLevel = envLevel;
    samplesSinceTrigger = 0;

    attack = localParameters[ATTACK] * sampleRate;
    decay = localParameters[DECAY] * sampleRate;
    sustainLevel = localParameters[SUSTAIN] * velocity;
    release = localParameters[RELEASE] * sampleRate;

    // precompute normalization of partials
    minPartialLevel = maxPartialLevel = 0.0;
    for (int i = 0; i < numPartials; i++)
    {
        if (localParameters[PartialLevelToParamMapping[i]] < minPartialLevel)
            minPartialLevel = localParameters[PartialLevelToParamMapping[i]];
        if (localParameters[PartialLevelToParamMapping[i]] > maxPartialLevel)
            maxPartialLevel = localParameters[PartialLevelToParamMapping[i]];

        partialLevels[i] = scaleRange(localParameters[PartialLevelToParamMapping[i]], minPartialLevel, maxPartialLevel, 0.0, 1.0);

        stretchedIndices[i] = 0.0;
    }

    envelopeState = ATTACK_STATE;
}

void AdditiveSynthVoice::stopNote (float velocity, const bool allowTailOff)
{
    samplesSinceTrigger = 0;
    releaseEnvLevel = envLevel;
}

float AdditiveSynthVoice::calculateFrequency(int currentPitchWheelPosition)
{
    float pbCents = ( (float)currentPitchWheelPosition / 16383.0) * (400.0) + -200.0;
    return MidiMessage::getMidiNoteInHertz(noteNumber) * pow(2, pbCents/1200);
}

void AdditiveSynthVoice::pitchWheelMoved (const int currentPitchWheelPosition)
{
    freq = calculateFrequency(currentPitchWheelPosition);
}

void AdditiveSynthVoice::controllerMoved (const int controllerNumber, const int newValue)
{
    switch (controllerNumber) {
        case MOD_WHEEL_CONTROL:
            modWheel = (float)newValue / 3.0 / 127.0;
            break;
        default:
            break;
    }
}

void AdditiveSynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (envLevel > 0.000 && sampleRate > 0 && nyquist > 0)
    {
        const float stretchEnvAmtInc = localParameters[STRETCH_ENV_AMT] + localParameters[STRETCH_ENV_AMT_FINE];

        while (--numSamples >= 0)
        {
            float currentSampleLeft = 0.0;
            float currentSampleRight = 0.0;
            const float masterAmplitude = envLevel / numPartials * 4; // * 4 fudge factor to make the synth reasonably louder
            float stretchEnvAmt = stretchEnvAmtInc * envLevel;
            float stretch = localParameters[STRETCH] + localParameters[STRETCH_FINE];
            float localFreq = freq + (freq * modWheel * lfoLevel);

            for (int i = 0; i < numPartials; i++)
            {
                if (localParameters[PartialLevelToParamMapping[i]] > 0.0)
                {
                    float partialFreq = localFreq + (localFreq * localParameters[PartialTuneToParamMapping[i]]);
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

                        float panRight = (1.0 + localParameters[PartialPanToParamMapping[i]]) / 2.0;
                        float panLeft  = 1.0 - panRight;
                        double value = sineWaveTable[((stretchedIndices[i]+0x8000) >> 16)]
                            * (localParameters[PartialLevelToParamMapping[i]] + (lfoLevel * localParameters[PartialLfoAmtToParamMapping[i]]));

                        currentSampleLeft += value * panLeft;
                        currentSampleRight += value * panRight;

                        stretchedIndices[i] = stretchedIndices[i] + increment & ((waveTableLength << 16) - 1);
                    }
                }
                stretch += stretch;
            }

            outputBuffer.addSample(0, startSample, currentSampleLeft * masterAmplitude);
            outputBuffer.addSample(1, startSample, currentSampleRight * masterAmplitude);

            ++startSample;
            tick();
        }
    }
}

float getSegmentCoefficient(float startLevel, float endLevel, int durationInSamples) {
    // add a tiny fudge factor when calculating the end level because it doesn't work
    // when it's exactly 0.0
    return (log((endLevel) + 0.0001) - log(startLevel)) / durationInSamples;
}

float AdditiveSynthVoice::getAmplitude()
{
    bool keyIsDown = isKeyDown();
    switch (envelopeState) {
        case ATTACK_STATE:
            if (samplesSinceTrigger == 0)
                envIncrement = velocity / attack;
            else if (samplesSinceTrigger > attack)
            {
                envelopeState = DECAY_STATE;
                coefficient = getSegmentCoefficient(envLevel, sustainLevel * velocity, decay);
            }

            if (attack == 0.0)
            {
                envLevel = velocity;
                envIncrement = 0.0;
                envelopeState = DECAY_STATE;
            }
            else
                envLevel += envIncrement;

            if (!keyIsDown)
            {
                envelopeState = RELEASE_STATE;
                coefficient = getSegmentCoefficient(envLevel, 0.0, release);
            }
            break;
        case DECAY_STATE:
            if (samplesSinceTrigger > attack + decay)
                envelopeState = SUSTAIN_STATE;
            else if (!keyIsDown)
            {
                envelopeState = RELEASE_STATE;
                coefficient = getSegmentCoefficient(envLevel, 0.0, release);
            }
            else
                envLevel += coefficient * envLevel;
            break;
        case SUSTAIN_STATE:
            envLevel = sustainLevel * velocity;
            if (!keyIsDown)
            {
                envelopeState = RELEASE_STATE;
                coefficient = getSegmentCoefficient(envLevel, 0.0, release);
            }
            break;
        case RELEASE_STATE:
            envLevel += coefficient * envLevel;
            if (envLevel < 0.001)
            {
                envLevel = 0.0;
                clearCurrentNote();
            }
            break;
    }
    return envLevel;
}

void AdditiveSynthVoice::aftertouchChanged (int newAftertouchValue)
{

}

void AdditiveSynthVoice::setCurrentPlaybackSampleRate (double newRate)
{
    sampleRate = newRate;
    nyquist = sampleRate/2.0;
    frqTI = waveTableLength/sampleRate;
}

bool AdditiveSynthVoice::isPlayingChannel (int midiChannel) const
{
    return true;
}

bool AdditiveSynthVoice::isVoiceActive() const
{
    return envLevel > 0.0;
}

void AdditiveSynthVoice::tick()
{
    setCurrentPlaybackSampleRate(getSampleRate());
    getAmplitude();

    switch (*localLfoShape) {
        case SINE_WAVE_TABLE:
            lfoLevel = sineWaveTable[lfoIndex];
            break;
        case TRIANGLE_WAVE_TABLE:
            lfoLevel = triangleWaveTable[lfoIndex];
            break;
        case SAW_WAVE_TABLE:
            lfoLevel = sawWaveTable[lfoIndex];
            break;
        case RAMP_WAVE_TABLE:
            lfoLevel = rampWaveTable[lfoIndex];
            break;
        default:
            break;
    }
    
    lfoIndex += frqTI * localParameters[LFO_FREQ];
    while (lfoIndex >= waveTableLength)
        lfoIndex -= waveTableLength;

    ++samplesSinceTrigger;
}
