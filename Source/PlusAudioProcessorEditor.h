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

    Slider globalAttack;
    Slider globalDecay;
    Slider globalSustain;
    Slider globalRelease;
    Slider lfoFrequency;
    ComboBox lfoShape;
    ComboBox numberOfVoices;
    ComboBox scale;
    ComboBox scaleRoot;
    Slider partialStretch;
    Slider partialStretchFine;
    Slider partialStretchEnvAmt;
    Slider partialStretchEnvAmtFine;
    Slider partialLevel_1;
    Slider partialLevel_2;
    Slider partialLevel_3;
    Slider partialLevel_4;
    Slider partialLevel_5;
    Slider partialLevel_6;
    Slider partialLevel_7;
    Slider partialLevel_8;
    Slider partialLevel_9;
    Slider partialLevel_10;
    Slider partialLevel_11;
    Slider partialLevel_12;
    Slider partialLevel_13;
    Slider partialLevel_14;
    Slider partialLevel_15;
    Slider partialLevel_16;
    Slider partialLevel_17;
    Slider partialLevel_18;
    Slider partialLevel_19;
    Slider partialLevel_20;
    Slider partialLevel_21;
    Slider partialLevel_22;
    Slider partialLevel_23;
    Slider partialLevel_24;
    Slider partialLevel_25;
    Slider partialLevel_26;
    Slider partialLevel_27;
    Slider partialLevel_28;
    Slider partialLevel_29;
    Slider partialLevel_30;
    Slider partialLevel_31;
    Slider partialLevel_32;
    Slider partialTune_1;
    Slider partialTune_2;
    Slider partialTune_3;
    Slider partialTune_4;
    Slider partialTune_5;
    Slider partialTune_6;
    Slider partialTune_7;
    Slider partialTune_8;
    Slider partialTune_9;
    Slider partialTune_10;
    Slider partialTune_11;
    Slider partialTune_12;
    Slider partialTune_13;
    Slider partialTune_14;
    Slider partialTune_15;
    Slider partialTune_16;
    Slider partialTune_17;
    Slider partialTune_18;
    Slider partialTune_19;
    Slider partialTune_20;
    Slider partialTune_21;
    Slider partialTune_22;
    Slider partialTune_23;
    Slider partialTune_24;
    Slider partialTune_25;
    Slider partialTune_26;
    Slider partialTune_27;
    Slider partialTune_28;
    Slider partialTune_29;
    Slider partialTune_30;
    Slider partialTune_31;
    Slider partialTune_32;
    Slider partialPan_1;
    Slider partialPan_2;
    Slider partialPan_3;
    Slider partialPan_4;
    Slider partialPan_5;
    Slider partialPan_6;
    Slider partialPan_7;
    Slider partialPan_8;
    Slider partialPan_9;
    Slider partialPan_10;
    Slider partialPan_11;
    Slider partialPan_12;
    Slider partialPan_13;
    Slider partialPan_14;
    Slider partialPan_15;
    Slider partialPan_16;
    Slider partialPan_17;
    Slider partialPan_18;
    Slider partialPan_19;
    Slider partialPan_20;
    Slider partialPan_21;
    Slider partialPan_22;
    Slider partialPan_23;
    Slider partialPan_24;
    Slider partialPan_25;
    Slider partialPan_26;
    Slider partialPan_27;
    Slider partialPan_28;
    Slider partialPan_29;
    Slider partialPan_30;
    Slider partialPan_31;
    Slider partialPan_32;
    Slider partialLfoAmt_1;
    Slider partialLfoAmt_2;
    Slider partialLfoAmt_3;
    Slider partialLfoAmt_4;
    Slider partialLfoAmt_5;
    Slider partialLfoAmt_6;
    Slider partialLfoAmt_7;
    Slider partialLfoAmt_8;
    Slider partialLfoAmt_9;
    Slider partialLfoAmt_10;
    Slider partialLfoAmt_11;
    Slider partialLfoAmt_12;
    Slider partialLfoAmt_13;
    Slider partialLfoAmt_14;
    Slider partialLfoAmt_15;
    Slider partialLfoAmt_16;
    Slider partialLfoAmt_17;
    Slider partialLfoAmt_18;
    Slider partialLfoAmt_19;
    Slider partialLfoAmt_20;
    Slider partialLfoAmt_21;
    Slider partialLfoAmt_22;
    Slider partialLfoAmt_23;
    Slider partialLfoAmt_24;
    Slider partialLfoAmt_25;
    Slider partialLfoAmt_26;
    Slider partialLfoAmt_27;
    Slider partialLfoAmt_28;
    Slider partialLfoAmt_29;
    Slider partialLfoAmt_30;
    Slider partialLfoAmt_31;
    Slider partialLfoAmt_32;
    Slider partialLevelEnvAmt;

    void setupPartialComponents(Slider *level, Slider *tune, Slider *pan, Slider *lfoAmt);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlusAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
