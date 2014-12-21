/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PlusAudioProcessor.h"


//==============================================================================
/**
*/
class PlusAudioProcessorEditor  : public AudioProcessorEditor, private Slider::Listener, private ComboBoxListener, public Timer
{
public:
    PlusAudioProcessorEditor (PlusAudioProcessor&);
    ~PlusAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider* slider) override;
    void comboBoxChanged (ComboBox* comboBox) override;
    void timerCallback();

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PlusAudioProcessor& processor;

    Slider stretchAttack;
    Slider stretchDecay;
    Slider stretchSustain;
    Slider stretchRelease;
    Slider lfoFrequency;
    ComboBox lfoShape;
    ComboBox numberOfVoices;
    ComboBox scale;
    ComboBox scaleRoot;
    Slider partialStretch;
    Slider partialStretchFine;
    Slider partialStretchEnvAmt;
    Slider partialStretchEnvAmtFine;
    Slider partialLevel[numPartials];
    Slider partialTune[numPartials];
    Slider partialPan[numPartials];
    Slider partialLfoAmt[numPartials];
    Slider partialAttack[numPartials];
    Slider partialDecay[numPartials];
    Slider partialSustain[numPartials];
    Slider partialRelease[numPartials];

    Slider noiseLevel;
    Slider noiseLfoAmt;
    Slider noisePan;
    Slider noiseAttack;
    Slider noiseDecay;
    Slider noiseSustain;
    Slider noiseRelease;
    

    void setupPartialComponents(Slider *level, Slider *tune, Slider *pan, Slider *lfoAmt, Slider *attack, Slider *decay, Slider *sustain, Slider *release);
    void layoutPartialComponents(int left, int top, Slider *level, Slider *tune, Slider *pan, Slider *lfoAmt, Slider *attack, Slider *decay, Slider *sustain, Slider *release);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlusAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
