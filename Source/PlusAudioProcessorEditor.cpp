/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "AdditiveSynth.h"
#include "PlusAudioProcessorEditor.h"


//==============================================================================
PlusAudioProcessorEditor::PlusAudioProcessorEditor (PlusAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    globalAttack.setSliderStyle(Slider::LinearBarVertical);
    globalAttack.setRange(0.01, 10.0, 0.01);
    globalAttack.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    globalAttack.setPopupDisplayEnabled(true, this);
    globalAttack.setValue(0.02);
    addAndMakeVisible(globalAttack);

    globalDecay.setSliderStyle(Slider::LinearBarVertical);
    globalDecay.setRange(0.01, 20.0, 0.01);
    globalDecay.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    globalDecay.setPopupDisplayEnabled(true, this);
    globalDecay.setValue(1.0);
    addAndMakeVisible(globalDecay);

    globalSustain.setSliderStyle(Slider::LinearBarVertical);
    globalSustain.setRange(0.0, 1.0, 0.01);
    globalSustain.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    globalSustain.setPopupDisplayEnabled(true, this);
    globalSustain.setValue(0.8);
    addAndMakeVisible(globalSustain);

    globalRelease.setSliderStyle(Slider::LinearBarVertical);
    globalRelease.setRange(0.01, 20.0, 0.01);
    globalRelease.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    globalRelease.setPopupDisplayEnabled(true, this);
    globalRelease.setValue(1.0);
    addAndMakeVisible(globalRelease);

    partialStretch.setSliderStyle(Slider::LinearBarVertical);
    partialStretch.setRange(-1.0, 1.0, 0.01);
    partialStretch.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialStretch.setPopupDisplayEnabled(true, this);
    partialStretch.setValue(0.0);
    addAndMakeVisible(partialStretch);

    partialStretchFine.setSliderStyle(Slider::LinearBarVertical);
    partialStretchFine.setRange(-0.1, 0.1, 0.001);
    partialStretchFine.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialStretchFine.setPopupDisplayEnabled(true, this);
    partialStretchFine.setValue(0.0);
    addAndMakeVisible(partialStretchFine);

    partialStretchEnvAmt.setSliderStyle(Slider::LinearBarVertical);
    partialStretchEnvAmt.setRange(0.0, 2.0, 0.01);
    partialStretchEnvAmt.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialStretchEnvAmt.setPopupDisplayEnabled(true, this);
    partialStretchEnvAmt.setValue(0.0);
    addAndMakeVisible(partialStretchEnvAmt);

    partialStretchEnvAmtFine.setSliderStyle(Slider::LinearBarVertical);
    partialStretchEnvAmtFine.setRange(-0.0, 0.1, 0.0001);
    partialStretchEnvAmtFine.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialStretchEnvAmtFine.setPopupDisplayEnabled(true, this);
    partialStretchEnvAmtFine.setValue(0.0);
    addAndMakeVisible(partialStretchEnvAmtFine);

    partialLevelEnvAmt.setSliderStyle(Slider::LinearBarVertical);
    partialLevelEnvAmt.setRange(0.0, 1.0, 0.001);
    partialLevelEnvAmt.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevelEnvAmt.setPopupDisplayEnabled(true, this);
    partialLevelEnvAmt.setValue(0.0);
    addAndMakeVisible(partialLevelEnvAmt);

    partialLevel_1.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_1.setRange(0.0, 1.0, 0.001);
    partialLevel_1.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_1.setPopupDisplayEnabled(true, this);
    partialLevel_1.setValue(1.0);
    addAndMakeVisible(partialLevel_1);

    partialLevel_2.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_2.setRange(0.0, 1.0, 0.001);
    partialLevel_2.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_2.setPopupDisplayEnabled(true, this);
    partialLevel_2.setValue(0.0);
    addAndMakeVisible(partialLevel_2);

    partialLevel_3.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_3.setRange(0.0, 1.0, 0.001);
    partialLevel_3.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_3.setPopupDisplayEnabled(true, this);
    partialLevel_3.setValue(0.0);
    addAndMakeVisible(partialLevel_3);

    partialLevel_4.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_4.setRange(0.0, 1.0, 0.001);
    partialLevel_4.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_4.setPopupDisplayEnabled(true, this);
    partialLevel_4.setValue(0.0);
    addAndMakeVisible(partialLevel_4);

    partialLevel_5.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_5.setRange(0.0, 1.0, 0.001);
    partialLevel_5.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_5.setPopupDisplayEnabled(true, this);
    partialLevel_5.setValue(0.0);
    addAndMakeVisible(partialLevel_5);

    partialLevel_6.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_6.setRange(0.0, 1.0, 0.001);
    partialLevel_6.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_6.setPopupDisplayEnabled(true, this);
    partialLevel_6.setValue(0.0);
    addAndMakeVisible(partialLevel_6);

    partialLevel_7.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_7.setRange(0.0, 1.0, 0.001);
    partialLevel_7.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_7.setPopupDisplayEnabled(true, this);
    partialLevel_7.setValue(0.0);
    addAndMakeVisible(partialLevel_7);

    partialLevel_8.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_8.setRange(0.0, 1.0, 0.001);
    partialLevel_8.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_8.setPopupDisplayEnabled(true, this);
    partialLevel_8.setValue(0.0);
    addAndMakeVisible(partialLevel_8);

    partialLevel_9.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_9.setRange(0.0, 1.0, 0.001);
    partialLevel_9.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_9.setPopupDisplayEnabled(true, this);
    partialLevel_9.setValue(0.0);
    addAndMakeVisible(partialLevel_9);

    partialLevel_10.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_10.setRange(0.0, 1.0, 0.001);
    partialLevel_10.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_10.setPopupDisplayEnabled(true, this);
    partialLevel_10.setValue(0.0);
    addAndMakeVisible(partialLevel_10);

    partialLevel_11.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_11.setRange(0.0, 1.0, 0.001);
    partialLevel_11.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_11.setPopupDisplayEnabled(true, this);
    partialLevel_11.setValue(0.0);
    addAndMakeVisible(partialLevel_11);

    partialLevel_12.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_12.setRange(0.0, 1.0, 0.001);
    partialLevel_12.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_12.setPopupDisplayEnabled(true, this);
    partialLevel_12.setValue(0.0);
    addAndMakeVisible(partialLevel_12);

    partialLevel_13.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_13.setRange(0.0, 1.0, 0.001);
    partialLevel_13.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_13.setPopupDisplayEnabled(true, this);
    partialLevel_13.setValue(0.0);
    addAndMakeVisible(partialLevel_13);

    partialLevel_14.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_14.setRange(0.0, 1.0, 0.001);
    partialLevel_14.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_14.setPopupDisplayEnabled(true, this);
    partialLevel_14.setValue(0.0);
    addAndMakeVisible(partialLevel_14);

    partialLevel_15.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_15.setRange(0.0, 1.0, 0.001);
    partialLevel_15.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_15.setPopupDisplayEnabled(true, this);
    partialLevel_15.setValue(0.0);
    addAndMakeVisible(partialLevel_15);

    partialLevel_16.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_16.setRange(0.0, 1.0, 0.001);
    partialLevel_16.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_16.setPopupDisplayEnabled(true, this);
    partialLevel_16.setValue(0.0);
    addAndMakeVisible(partialLevel_16);

    partialLevel_16.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_16.setRange(0.0, 1.0, 0.001);
    partialLevel_16.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_16.setPopupDisplayEnabled(true, this);
    partialLevel_16.setValue(0.0);
    addAndMakeVisible(partialLevel_16);

    partialLevel_17.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_17.setRange(0.0, 1.0, 0.001);
    partialLevel_17.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_17.setPopupDisplayEnabled(true, this);
    partialLevel_17.setValue(0.0);
    addAndMakeVisible(partialLevel_17);

    partialLevel_18.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_18.setRange(0.0, 1.0, 0.001);
    partialLevel_18.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_18.setPopupDisplayEnabled(true, this);
    partialLevel_18.setValue(0.0);
    addAndMakeVisible(partialLevel_18);

    partialLevel_19.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_19.setRange(0.0, 1.0, 0.001);
    partialLevel_19.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_19.setPopupDisplayEnabled(true, this);
    partialLevel_19.setValue(0.0);
    addAndMakeVisible(partialLevel_19);

    partialLevel_20.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_20.setRange(0.0, 1.0, 0.001);
    partialLevel_20.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_20.setPopupDisplayEnabled(true, this);
    partialLevel_20.setValue(0.0);
    addAndMakeVisible(partialLevel_20);

    partialLevel_21.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_21.setRange(0.0, 1.0, 0.001);
    partialLevel_21.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_21.setPopupDisplayEnabled(true, this);
    partialLevel_21.setValue(0.0);
    addAndMakeVisible(partialLevel_21);

    partialLevel_22.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_22.setRange(0.0, 1.0, 0.001);
    partialLevel_22.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_22.setPopupDisplayEnabled(true, this);
    partialLevel_22.setValue(0.0);
    addAndMakeVisible(partialLevel_22);

    partialLevel_23.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_23.setRange(0.0, 1.0, 0.001);
    partialLevel_23.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_23.setPopupDisplayEnabled(true, this);
    partialLevel_23.setValue(0.0);
    addAndMakeVisible(partialLevel_23);

    partialLevel_24.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_24.setRange(0.0, 1.0, 0.001);
    partialLevel_24.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_24.setPopupDisplayEnabled(true, this);
    partialLevel_24.setValue(0.0);
    addAndMakeVisible(partialLevel_24);

    partialLevel_25.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_25.setRange(0.0, 1.0, 0.001);
    partialLevel_25.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_25.setPopupDisplayEnabled(true, this);
    partialLevel_25.setValue(0.0);
    addAndMakeVisible(partialLevel_25);

    partialLevel_26.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_26.setRange(0.0, 1.0, 0.001);
    partialLevel_26.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_26.setPopupDisplayEnabled(true, this);
    partialLevel_26.setValue(0.0);
    addAndMakeVisible(partialLevel_26);

    partialLevel_27.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_27.setRange(0.0, 1.0, 0.001);
    partialLevel_27.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_27.setPopupDisplayEnabled(true, this);
    partialLevel_27.setValue(0.0);
    addAndMakeVisible(partialLevel_27);

    partialLevel_28.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_28.setRange(0.0, 1.0, 0.001);
    partialLevel_28.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_28.setPopupDisplayEnabled(true, this);
    partialLevel_28.setValue(0.0);
    addAndMakeVisible(partialLevel_28);

    partialLevel_29.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_29.setRange(0.0, 1.0, 0.001);
    partialLevel_29.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_29.setPopupDisplayEnabled(true, this);
    partialLevel_29.setValue(0.0);
    addAndMakeVisible(partialLevel_29);

    partialLevel_30.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_30.setRange(0.0, 1.0, 0.001);
    partialLevel_30.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_30.setPopupDisplayEnabled(true, this);
    partialLevel_30.setValue(0.0);
    addAndMakeVisible(partialLevel_30);

    partialLevel_31.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_31.setRange(0.0, 1.0, 0.001);
    partialLevel_31.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_31.setPopupDisplayEnabled(true, this);
    partialLevel_31.setValue(0.0);
    addAndMakeVisible(partialLevel_31);

    partialLevel_32.setSliderStyle(Slider::LinearBarVertical);
    partialLevel_32.setRange(0.0, 1.0, 0.001);
    partialLevel_32.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialLevel_32.setPopupDisplayEnabled(true, this);
    partialLevel_32.setValue(0.0);
    addAndMakeVisible(partialLevel_32);

    globalAttack.addListener(this);
    globalDecay.addListener(this);
    globalSustain.addListener(this);
    globalRelease.addListener(this);
    partialStretch.addListener(this);
    partialStretchFine.addListener(this);
    partialStretchEnvAmt.addListener(this);
    partialStretchEnvAmtFine.addListener(this);
    partialLevel_1.addListener(this);
    partialLevel_2.addListener(this);
    partialLevel_3.addListener(this);
    partialLevel_4.addListener(this);
    partialLevel_5.addListener(this);
    partialLevel_6.addListener(this);
    partialLevel_7.addListener(this);
    partialLevel_8.addListener(this);
    partialLevel_9.addListener(this);
    partialLevel_10.addListener(this);
    partialLevel_11.addListener(this);
    partialLevel_12.addListener(this);
    partialLevel_13.addListener(this);
    partialLevel_14.addListener(this);
    partialLevel_15.addListener(this);
    partialLevel_16.addListener(this);
    partialLevel_17.addListener(this);
    partialLevel_18.addListener(this);
    partialLevel_19.addListener(this);
    partialLevel_20.addListener(this);
    partialLevel_21.addListener(this);
    partialLevel_22.addListener(this);
    partialLevel_23.addListener(this);
    partialLevel_24.addListener(this);
    partialLevel_25.addListener(this);
    partialLevel_26.addListener(this);
    partialLevel_27.addListener(this);
    partialLevel_28.addListener(this);
    partialLevel_29.addListener(this);
    partialLevel_30.addListener(this);
    partialLevel_31.addListener(this);
    partialLevel_32.addListener(this);

    timerCallback();
    startTimer(50);
    setSize (910, 300);
}

PlusAudioProcessorEditor::~PlusAudioProcessorEditor()
{
}

//==============================================================================
void PlusAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("ADSR", 20, 0, 80, 30, Justification::centred, 1);
    g.drawFittedText ("Stretch", 120, 0, 60, 30, Justification::centred, 1);
    g.drawFittedText ("Env", 180, 0, 60, 30, Justification::centred, 1);
    g.drawFittedText ("Partial Levels", 250, 0, 640, 30, Justification::centred, 1);
}

void PlusAudioProcessorEditor::resized()
{
    globalAttack.setBounds (20, 30, 20, getHeight() - 60);
    globalDecay.setBounds (40, 30, 20, getHeight() - 60);
    globalSustain.setBounds (60, 30, 20, getHeight() - 60);
    globalRelease.setBounds (80, 30, 20, getHeight() - 60);
    partialStretch.setBounds (130, 30, 20, getHeight() - 60);
    partialStretchFine.setBounds (150, 30, 20, getHeight() - 60);
    partialStretchEnvAmt.setBounds (190, 30, 20, getHeight() - 60);
    partialStretchEnvAmtFine.setBounds (210, 30, 20, getHeight() - 60);
    partialLevel_1.setBounds (250, 30, 20, getHeight() - 60);
    partialLevel_2.setBounds (270, 30, 20, getHeight() - 60);
    partialLevel_3.setBounds (290, 30, 20, getHeight() - 60);
    partialLevel_4.setBounds (310, 30, 20, getHeight() - 60);
    partialLevel_5.setBounds (330, 30, 20, getHeight() - 60);
    partialLevel_6.setBounds (350, 30, 20, getHeight() - 60);
    partialLevel_7.setBounds (370, 30, 20, getHeight() - 60);
    partialLevel_8.setBounds (390, 30, 20, getHeight() - 60);
    partialLevel_9.setBounds (410, 30, 20, getHeight() - 60);
    partialLevel_10.setBounds (430, 30, 20, getHeight() - 60);
    partialLevel_11.setBounds (450, 30, 20, getHeight() - 60);
    partialLevel_12.setBounds (470, 30, 20, getHeight() - 60);
    partialLevel_13.setBounds (490, 30, 20, getHeight() - 60);
    partialLevel_14.setBounds (510, 30, 20, getHeight() - 60);
    partialLevel_15.setBounds (530, 30, 20, getHeight() - 60);
    partialLevel_16.setBounds (550, 30, 20, getHeight() - 60);
    partialLevel_17.setBounds (570, 30, 20, getHeight() - 60);
    partialLevel_18.setBounds (590, 30, 20, getHeight() - 60);
    partialLevel_19.setBounds (610, 30, 20, getHeight() - 60);
    partialLevel_20.setBounds (630, 30, 20, getHeight() - 60);
    partialLevel_21.setBounds (650, 30, 20, getHeight() - 60);
    partialLevel_22.setBounds (670, 30, 20, getHeight() - 60);
    partialLevel_23.setBounds (690, 30, 20, getHeight() - 60);
    partialLevel_24.setBounds (710, 30, 20, getHeight() - 60);
    partialLevel_25.setBounds (730, 30, 20, getHeight() - 60);
    partialLevel_26.setBounds (750, 30, 20, getHeight() - 60);
    partialLevel_27.setBounds (770, 30, 20, getHeight() - 60);
    partialLevel_28.setBounds (790, 30, 20, getHeight() - 60);
    partialLevel_29.setBounds (810, 30, 20, getHeight() - 60);
    partialLevel_30.setBounds (830, 30, 20, getHeight() - 60);
    partialLevel_31.setBounds (850, 30, 20, getHeight() - 60);
    partialLevel_32.setBounds (870, 30, 20, getHeight() - 60);
}

void PlusAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &globalAttack)
        processor.getFloatParam(ATTACK)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &globalDecay)
        processor.getFloatParam(DECAY)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &globalSustain)
        processor.getFloatParam(SUSTAIN)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &globalRelease)
        processor.getFloatParam(RELEASE)->updateProcessorAndHostFromUi(slider->getValue());

    if (slider == &partialStretch)
        processor.getFloatParam(STRETCH)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialStretchFine)
        processor.getFloatParam(STRETCH_FINE)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialStretchEnvAmt)
        processor.getFloatParam(STRETCH_ENV_AMT)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialStretchEnvAmtFine)
        processor.getFloatParam(STRETCH_ENV_AMT_FINE)->updateProcessorAndHostFromUi(slider->getValue());

    if (slider == &partialLevel_1)
        processor.getFloatParam(PARTIAL_1)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_2)
        processor.getFloatParam(PARTIAL_2)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_3)
        processor.getFloatParam(PARTIAL_3)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_4)
        processor.getFloatParam(PARTIAL_4)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_5)
        processor.getFloatParam(PARTIAL_5)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_6)
        processor.getFloatParam(PARTIAL_6)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_7)
        processor.getFloatParam(PARTIAL_7)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_8)
        processor.getFloatParam(PARTIAL_8)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_9)
        processor.getFloatParam(PARTIAL_9)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_10)
        processor.getFloatParam(PARTIAL_10)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_11)
        processor.getFloatParam(PARTIAL_11)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_12)
        processor.getFloatParam(PARTIAL_12)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_13)
        processor.getFloatParam(PARTIAL_13)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_14)
        processor.getFloatParam(PARTIAL_14)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_15)
        processor.getFloatParam(PARTIAL_15)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_16)
        processor.getFloatParam(PARTIAL_16)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_17)
        processor.getFloatParam(PARTIAL_17)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_18)
        processor.getFloatParam(PARTIAL_18)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_19)
        processor.getFloatParam(PARTIAL_19)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_20)
        processor.getFloatParam(PARTIAL_20)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_21)
        processor.getFloatParam(PARTIAL_21)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_22)
        processor.getFloatParam(PARTIAL_22)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_23)
        processor.getFloatParam(PARTIAL_23)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_24)
        processor.getFloatParam(PARTIAL_24)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_25)
        processor.getFloatParam(PARTIAL_25)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_26)
        processor.getFloatParam(PARTIAL_26)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_27)
        processor.getFloatParam(PARTIAL_27)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_28)
        processor.getFloatParam(PARTIAL_28)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_29)
        processor.getFloatParam(PARTIAL_29)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_30)
        processor.getFloatParam(PARTIAL_30)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_31)
        processor.getFloatParam(PARTIAL_31)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialLevel_32)
        processor.getFloatParam(PARTIAL_32)->updateProcessorAndHostFromUi(slider->getValue());

}

void PlusAudioProcessorEditor::timerCallback(){
    FloatParam *param=processor.getFloatParam(ATTACK);
    if (&globalAttack && param->updateUiRequested()){
        globalAttack.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(DECAY);
    if (&globalDecay && param->updateUiRequested()){
        globalDecay.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(SUSTAIN);
    if (&globalSustain && param->updateUiRequested()){
        globalSustain.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(RELEASE);
    if (&globalRelease && param->updateUiRequested()){
        globalRelease.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(STRETCH);
    if (&partialStretch && param->updateUiRequested()){
        partialStretch.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(STRETCH_FINE);
    if (&partialStretchFine && param->updateUiRequested()){
        partialStretchFine.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(STRETCH_ENV_AMT);
    if (&partialStretchEnvAmt && param->updateUiRequested()){
        partialStretchEnvAmt.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(STRETCH_ENV_AMT_FINE);
    if (&partialStretchEnvAmtFine && param->updateUiRequested()){
        partialStretchEnvAmtFine.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_1);
    if (&partialLevel_1 && param->updateUiRequested()){
        partialLevel_1.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_2);
    if (&partialLevel_2 && param->updateUiRequested()){
        partialLevel_2.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_3);
    if (&partialLevel_3 && param->updateUiRequested()){
        partialLevel_3.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_4);
    if (&partialLevel_4 && param->updateUiRequested()){
        partialLevel_4.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_5);
    if (&partialLevel_5 && param->updateUiRequested()){
        partialLevel_5.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_6);
    if (&partialLevel_6 && param->updateUiRequested()){
        partialLevel_6.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_7);
    if (&partialLevel_7 && param->updateUiRequested()){
        partialLevel_7.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_8);
    if (&partialLevel_8 && param->updateUiRequested()){
        partialLevel_8.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_9);
    if (&partialLevel_9 && param->updateUiRequested()){
        partialLevel_9.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_10);
    if (&partialLevel_10 && param->updateUiRequested()){
        partialLevel_10.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_11);
    if (&partialLevel_11 && param->updateUiRequested()){
        partialLevel_11.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_12);
    if (&partialLevel_12 && param->updateUiRequested()){
        partialLevel_12.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_13);
    if (&partialLevel_13 && param->updateUiRequested()){
        partialLevel_13.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_14);
    if (&partialLevel_14 && param->updateUiRequested()){
        partialLevel_14.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_15);
    if (&partialLevel_15 && param->updateUiRequested()){
        partialLevel_15.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_16);
    if (&partialLevel_16 && param->updateUiRequested()){
        partialLevel_16.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_17);
    if (&partialLevel_17 && param->updateUiRequested()){
        partialLevel_17.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_18);
    if (&partialLevel_18 && param->updateUiRequested()){
        partialLevel_18.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_19);
    if (&partialLevel_19 && param->updateUiRequested()){
        partialLevel_19.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_20);
    if (&partialLevel_20 && param->updateUiRequested()){
        partialLevel_20.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_21);
    if (&partialLevel_21 && param->updateUiRequested()){
        partialLevel_21.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_22);
    if (&partialLevel_22 && param->updateUiRequested()){
        partialLevel_22.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_23);
    if (&partialLevel_23 && param->updateUiRequested()){
        partialLevel_23.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_24);
    if (&partialLevel_24 && param->updateUiRequested()){
        partialLevel_24.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_25);
    if (&partialLevel_25 && param->updateUiRequested()){
        partialLevel_25.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_26);
    if (&partialLevel_26 && param->updateUiRequested()){
        partialLevel_26.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_27);
    if (&partialLevel_27 && param->updateUiRequested()){
        partialLevel_27.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_28);
    if (&partialLevel_28 && param->updateUiRequested()){
        partialLevel_28.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_29);
    if (&partialLevel_29 && param->updateUiRequested()){
        partialLevel_29.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_30);
    if (&partialLevel_30 && param->updateUiRequested()){
        partialLevel_30.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_31);
    if (&partialLevel_31 && param->updateUiRequested()){
        partialLevel_31.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(PARTIAL_32);
    if (&partialLevel_32 && param->updateUiRequested()){
        partialLevel_32.setValue (param->uiGet(), dontSendNotification);
    }
}
