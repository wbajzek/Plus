//
//  AdditiveSynthVoice.h
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#ifndef __Plus__AdditiveSynthVoice__
#define __Plus__AdditiveSynthVoice__


class AdditiveSynthVoice : public SynthesiserVoice
{
public:
    AdditiveSynthVoice(float* parameters);
    ~AdditiveSynthVoice();
    float getParameter(int index);
    
    bool canPlaySound (SynthesiserSound* sound);
    
    void startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int /*currrentPitchWheelPosition*/);
    
    void stopNote (float velocity, const bool allowTailOff);
    
    void pitchWheelMoved (const int /*newValue*/);
    
    void controllerMoved (const int /*controllerNumber*/, const int /*newValue*/);
    
    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
    
    bool isVoiceActive() const;
    
    void aftertouchChanged (int newAftertouchValue);
    
    void setCurrentPlaybackSampleRate (double newRate);

    bool isPlayingChannel (int midiChannel) const;

    
private:
    enum Parameters
    {
    };
    
    float* localParameters;
    double freq = 110.0;
    double level = 0;
    double partialLevels[numPartials];
    double currentAngles[numPartials] = { 0.0 };
};

#endif /* defined(__Plus__AdditiveSynthVoice__) */
