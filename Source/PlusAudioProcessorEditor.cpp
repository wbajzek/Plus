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

    stretchAttack.setSliderStyle(Slider::LinearBarVertical);
    stretchAttack.setRange(0.01, 10.0, 0.01);
    stretchAttack.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    stretchAttack.setPopupDisplayEnabled(true, this);
    stretchAttack.setScrollWheelEnabled(false);
    addAndMakeVisible(stretchAttack);

    stretchDecay.setSliderStyle(Slider::LinearBarVertical);
    stretchDecay.setRange(0.01, 20.0, 0.01);
    stretchDecay.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    stretchDecay.setPopupDisplayEnabled(true, this);
    stretchDecay.setScrollWheelEnabled(false);
    addAndMakeVisible(stretchDecay);

    stretchSustain.setSliderStyle(Slider::LinearBarVertical);
    stretchSustain.setRange(0.0, 1.0, 0.01);
    stretchSustain.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    stretchSustain.setPopupDisplayEnabled(true, this);
    stretchSustain.setScrollWheelEnabled(false);
    addAndMakeVisible(stretchSustain);

    stretchRelease.setSliderStyle(Slider::LinearBarVertical);
    stretchRelease.setRange(0.01, 20.0, 0.01);
    stretchRelease.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    stretchRelease.setPopupDisplayEnabled(true, this);
    stretchRelease.setScrollWheelEnabled(false);
    addAndMakeVisible(stretchRelease);

    lfoFrequency.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    lfoFrequency.setRange(0.01, 100.0, 0.01);
    lfoFrequency.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    lfoFrequency.setPopupDisplayEnabled(true, this);
    lfoFrequency.setScrollWheelEnabled(false);
    addAndMakeVisible(lfoFrequency);

    lfoShape.addItem("Sine",SINE_WAVE_TABLE + 1);
    lfoShape.addItem("Triangle",TRIANGLE_WAVE_TABLE + 1);
    lfoShape.addItem("Saw",SAW_WAVE_TABLE + 1);
    lfoShape.addItem("Ramp",RAMP_WAVE_TABLE + 1);
    lfoShape.setWantsKeyboardFocus(false);
    lfoShape.setItemEnabled(0, false);
    lfoShape.setEditableText(false);
    lfoShape.setScrollWheelEnabled(false);
    addAndMakeVisible(lfoShape);

    numberOfVoices.addItem("1",1);
    numberOfVoices.addItem("2",2);
    numberOfVoices.addItem("4",4);
    numberOfVoices.addItem("6",6);
    numberOfVoices.addItem("8",8);
    numberOfVoices.addItem("10",10);
    numberOfVoices.addItem("12",12);
    numberOfVoices.addItem("14",14);
    numberOfVoices.addItem("16",16);
    numberOfVoices.setWantsKeyboardFocus(false);
    numberOfVoices.setItemEnabled(0, false);
    numberOfVoices.setEditableText(false);
    numberOfVoices.setScrollWheelEnabled(false);
    addAndMakeVisible(numberOfVoices);

    for (int i = 0; i < numberOfScales; i++)
    {
        jassert(scales[i].description.isNotEmpty());
        scale.addItem(scales[i].description, i+1);
    }
    scale.setWantsKeyboardFocus(false);
    scale.setEditableText(false);
    scale.setScrollWheelEnabled(false);
    addAndMakeVisible(scale);

    scaleRoot.addItem("C",1);
    scaleRoot.addItem("C#",2);
    scaleRoot.addItem("D",3);
    scaleRoot.addItem("D#",4);
    scaleRoot.addItem("E",5);
    scaleRoot.addItem("F",6);
    scaleRoot.addItem("F#",7);
    scaleRoot.addItem("G",8);
    scaleRoot.addItem("G#",9);
    scaleRoot.addItem("A",10);
    scaleRoot.addItem("A#",11);
    scaleRoot.addItem("B",12);
    scaleRoot.setWantsKeyboardFocus(false);
    scaleRoot.setItemEnabled(0, false);
    scaleRoot.setEditableText(false);
    scaleRoot.setScrollWheelEnabled(false);
    addAndMakeVisible(scaleRoot);

    partialStretch.setSliderStyle(Slider::LinearBarVertical);
    partialStretch.setRange(-1.0, 1.0, 0.01);
    partialStretch.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialStretch.setPopupDisplayEnabled(true, this);
    partialStretch.setScrollWheelEnabled(false);
    addAndMakeVisible(partialStretch);

    partialStretchFine.setSliderStyle(Slider::LinearBarVertical);
    partialStretchFine.setRange(-0.01, 0.01, 0.0001);
    partialStretchFine.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialStretchFine.setPopupDisplayEnabled(true, this);
    partialStretchFine.setScrollWheelEnabled(false);
    addAndMakeVisible(partialStretchFine);

    partialStretchEnvAmt.setSliderStyle(Slider::LinearBarVertical);
    partialStretchEnvAmt.setRange(0.0, 2.0, 0.01);
    partialStretchEnvAmt.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialStretchEnvAmt.setPopupDisplayEnabled(true, this);
    partialStretchEnvAmt.setScrollWheelEnabled(false);
    addAndMakeVisible(partialStretchEnvAmt);

    partialStretchEnvAmtFine.setSliderStyle(Slider::LinearBarVertical);
    partialStretchEnvAmtFine.setRange(-0.0, 0.1, 0.0001);
    partialStretchEnvAmtFine.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    partialStretchEnvAmtFine.setPopupDisplayEnabled(true, this);
    partialStretchEnvAmtFine.setScrollWheelEnabled(false);
    addAndMakeVisible(partialStretchEnvAmtFine);

    stretchAttack.addListener(this);
    stretchDecay.addListener(this);
    stretchSustain.addListener(this);
    stretchRelease.addListener(this);

    lfoFrequency.addListener(this);
    lfoShape.addListener(this);

    numberOfVoices.addListener(this);
    scale.addListener(this);
    scaleRoot.addListener(this);

    partialStretch.addListener(this);
    partialStretchFine.addListener(this);
    partialStretchEnvAmt.addListener(this);
    partialStretchEnvAmtFine.addListener(this);

    for (int i = 0; i < numPartials; ++i)
        setupPartialComponents(&partialLevel[i], &partialTune[i], &partialPan[i], &partialLfoAmt[i],
                               &partialAttack[i], &partialDecay[i], &partialSustain[i], &partialRelease[i]);

    
    setupPartialComponents(&noiseLevel, nullptr, &noisePan, &noiseLfoAmt, &noiseAttack, &noiseDecay, &noiseSustain, &noiseRelease);

    processor.updateUi(true,true);
    timerCallback();
    startTimer(50);
    setSize (950, 460);
}

void PlusAudioProcessorEditor::setupPartialComponents(Slider *level, Slider *tune, Slider *pan, Slider *lfoAmt, Slider *attack, Slider *decay, Slider *sustain, Slider *release)
{
    level->setSliderStyle(Slider::LinearBarVertical);
    level->setRange(0.0, 1.0, 0.001);
    level->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    level->setPopupDisplayEnabled(true, this);
    level->addListener(this);
    level->setScrollWheelEnabled(false);
    addAndMakeVisible(level);

    if (tune != nullptr)
    {
        tune->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
        tune->setRange(-1.0, 1.0, 0.001);
        tune->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
        tune->setPopupDisplayEnabled(true, this);
        tune->addListener(this);
        tune->setScrollWheelEnabled(false);
        addAndMakeVisible(tune);
    }

    pan->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    pan->setRange(-1.0, 1.0, 0.001);
    pan->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    pan->setPopupDisplayEnabled(true, this);
    pan->addListener(this);
    pan->setScrollWheelEnabled(false);
    addAndMakeVisible(pan);

    lfoAmt->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    lfoAmt->setRange(0.0, 1.0, 0.001);
    lfoAmt->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    lfoAmt->setPopupDisplayEnabled(true, this);
    lfoAmt->addListener(this);
    lfoAmt->setScrollWheelEnabled(false);
    addAndMakeVisible(lfoAmt);

    attack->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attack->setRange(0.001, 10.0, 0.001);
    attack->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    attack->setPopupDisplayEnabled(true, this);
    attack->addListener(this);
    attack->setScrollWheelEnabled(false);
    addAndMakeVisible(attack);

    decay->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decay->setRange(0.001, 10.0, 0.001);
    decay->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    decay->setPopupDisplayEnabled(true, this);
    decay->addListener(this);
    decay->setScrollWheelEnabled(false);
    addAndMakeVisible(decay);

    sustain->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustain->setRange(0.0, 1.0, 0.01);
    sustain->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    sustain->setPopupDisplayEnabled(true, this);
    sustain->addListener(this);
    sustain->setScrollWheelEnabled(false);
    addAndMakeVisible(sustain);

    release->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    release->setRange(0.001, 10.0, 0.001);
    release->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    release->setPopupDisplayEnabled(true, this);
    release->addListener(this);
    release->setScrollWheelEnabled(false);
    addAndMakeVisible(release);
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

    int partialControlLabelLeft = 180;
    g.drawFittedText ("LFO", partialControlLabelLeft, 238, 60, 30, Justification::right, 1);
    g.drawFittedText ("Tune", partialControlLabelLeft, 268, 60, 30, Justification::right, 1);
    g.drawFittedText ("Pan", partialControlLabelLeft, 298, 60, 30, Justification::right, 1);
    g.drawFittedText ("A", partialControlLabelLeft, 328, 60, 30, Justification::right, 1);
    g.drawFittedText ("D", partialControlLabelLeft, 358, 60, 30, Justification::right, 1);
    g.drawFittedText ("S", partialControlLabelLeft, 388, 60, 30, Justification::right, 1);
    g.drawFittedText ("R", partialControlLabelLeft, 418, 60, 30, Justification::right, 1);
    g.drawFittedText ("LFO Freq", 20, 238, 60, 30, Justification::centred, 1);
    g.drawFittedText ("LFO Shape", 20, 268, 60, 30, Justification::centred, 1);
    g.drawFittedText ("Voices", 20, 298, 60, 30, Justification::centred, 1);
    g.drawFittedText ("Scale", 20, 328, 60, 30, Justification::centred, 1);
    g.drawFittedText ("Scale Root", 20, 358, 60, 30, Justification::centred, 1);
    g.drawFittedText ("Noise", 890, 0, 60, 30, Justification::centred, 1);
}

void PlusAudioProcessorEditor::resized()
{
    int topRowHeight = 200;
    int topRowTop = 30;
    int lfoRowTop = 245;
    int lfoRowHeight = 20;
    int tuneRowTop = 275;
    int tuneRowHeight = 20;
    int panRowTop = 305;
    int panRowHeight = 20;
    int scaleRowTop = 335;
    int scaleRootRowTop = 365;
    int scaleRowHeight = 20;

    stretchAttack.setBounds (20, topRowTop, 20, topRowHeight);
    stretchDecay.setBounds (40, topRowTop, 20, topRowHeight);
    stretchSustain.setBounds (60, topRowTop, 20, topRowHeight);
    stretchRelease.setBounds (80, topRowTop, 20, topRowHeight);
    partialStretch.setBounds (130, topRowTop, 20, topRowHeight);
    partialStretchFine.setBounds (150, topRowTop, 20, topRowHeight);
    partialStretchEnvAmt.setBounds (190, topRowTop, 20, topRowHeight);
    partialStretchEnvAmtFine.setBounds (210, topRowTop, 20, topRowHeight);

    int partialAreaLeft = 250;
    for (int i = 0; i < numPartials; ++i)
        layoutPartialComponents(partialAreaLeft + (i * 20), topRowTop, &partialLevel[i], &partialTune[i], &partialPan[i],
                                &partialLfoAmt[i], &partialAttack[i], &partialDecay[i], &partialSustain[i], &partialRelease[i]);

    layoutPartialComponents(910, topRowTop, &noiseLevel, nullptr, &noisePan, &noiseLfoAmt, &noiseAttack, &noiseDecay, &noiseSustain, &noiseRelease);

    lfoFrequency.setBounds (90, lfoRowTop, 20, lfoRowHeight);
    lfoShape.setBounds (90, tuneRowTop, 90, tuneRowHeight);
    numberOfVoices.setBounds (90, panRowTop, 90, panRowHeight);
    scale.setBounds (90, scaleRowTop, 90, scaleRowHeight);
    scaleRoot.setBounds (90, scaleRootRowTop, 90, scaleRowHeight);
}

void PlusAudioProcessorEditor::layoutPartialComponents(int left, int top, Slider *level, Slider *tune, Slider *pan, Slider *lfoAmt, Slider *attack, Slider *decay, Slider *sustain, Slider *release)
{
    int levelHeight = 200;
    int knobHeight = 20;

    level->setBounds (left, top, 20, levelHeight);
    lfoAmt->setBounds (left, top + 215, 20, knobHeight);
    if (tune != nullptr)
        tune->setBounds (left, top + 245, 20, knobHeight);
    pan->setBounds (left, top + 275, 20, knobHeight);
    attack->setBounds (left, top + 305, 20, knobHeight);
    decay->setBounds (left, top + 335, 20, knobHeight);
    sustain->setBounds (left, top + 365, 20, knobHeight);
    release->setBounds (left, top + 395, 20, knobHeight);
}

void PlusAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &stretchAttack)
        processor.getFloatParam(ATTACK)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &stretchDecay)
        processor.getFloatParam(DECAY)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &stretchSustain)
        processor.getFloatParam(SUSTAIN)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &stretchRelease)
        processor.getFloatParam(RELEASE)->updateProcessorAndHostFromUi(slider->getValue());

    if (slider == &lfoFrequency)
        processor.getFloatParam(LFO_FREQ)->updateProcessorAndHostFromUi(slider->getValue());

    if (slider == &partialStretch)
        processor.getFloatParam(STRETCH)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialStretchFine)
        processor.getFloatParam(STRETCH_FINE)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialStretchEnvAmt)
        processor.getFloatParam(STRETCH_ENV_AMT)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &partialStretchEnvAmtFine)
        processor.getFloatParam(STRETCH_ENV_AMT_FINE)->updateProcessorAndHostFromUi(slider->getValue());

    for (int i = 0; i < numPartials; ++i)
    {
        if (slider == &partialLevel[i])
            processor.getFloatParam(PARTIAL_1 + i)->updateProcessorAndHostFromUi(slider->getValue());
        if (slider == &partialTune[i])
            processor.getFloatParam(PARTIAL_TUNE_1 + i)->updateProcessorAndHostFromUi(slider->getValue());
        if (slider == &partialPan[i])
            processor.getFloatParam(PARTIAL_PAN_1 + i)->updateProcessorAndHostFromUi(slider->getValue());
        if (slider == &partialLfoAmt[i])
            processor.getFloatParam(PARTIAL_LFO_AMT_1 + i)->updateProcessorAndHostFromUi(slider->getValue());
        if (slider == &partialAttack[i])
            processor.getFloatParam(PARTIAL_ATTACK_1 + i)->updateProcessorAndHostFromUi(slider->getValue());
        if (slider == &partialDecay[i])
            processor.getFloatParam(PARTIAL_DECAY_1 + i)->updateProcessorAndHostFromUi(slider->getValue());
        if (slider == &partialSustain[i])
            processor.getFloatParam(PARTIAL_SUSTAIN_1 + i)->updateProcessorAndHostFromUi(slider->getValue());
        if (slider == &partialRelease[i])
            processor.getFloatParam(PARTIAL_RELEASE_1 + i)->updateProcessorAndHostFromUi(slider->getValue());
    }

    if (slider == &noiseLevel)
        processor.getFloatParam(NOISE_LEVEL)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &noiseLfoAmt)
        processor.getFloatParam(NOISE_LFO_AMT)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &noisePan)
        processor.getFloatParam(NOISE_PAN)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &noiseAttack)
        processor.getFloatParam(NOISE_ATTACK)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &noiseDecay)
        processor.getFloatParam(NOISE_DECAY)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &noiseSustain)
        processor.getFloatParam(NOISE_SUSTAIN)->updateProcessorAndHostFromUi(slider->getValue());
    if (slider == &noiseRelease)
        processor.getFloatParam(NOISE_RELEASE)->updateProcessorAndHostFromUi(slider->getValue());

}

void PlusAudioProcessorEditor::comboBoxChanged (ComboBox* comboBox)
{
    if (comboBox == &lfoShape)
        processor.getIntParam(LFO_SHAPE)->updateProcessorAndHostFromUi(comboBox->getSelectedId() - 1);
    if (comboBox == &numberOfVoices)
    {
        processor.getIntParam(NUMBER_OF_VOICES)->updateProcessorAndHostFromUi(comboBox->getSelectedId());
        processor.initVoices();
    }
    if (comboBox == &scale)
        processor.getIntParam(SCALE)->updateProcessorAndHostFromUi(comboBox->getSelectedId());
    if (comboBox == &scaleRoot)
        processor.getIntParam(SCALE_ROOT)->updateProcessorAndHostFromUi(comboBox->getSelectedId());
}


void PlusAudioProcessorEditor::timerCallback()
{
    FloatParam *param=processor.getFloatParam(ATTACK);
    if (&stretchAttack && param->updateUiRequested()){
        stretchAttack.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(DECAY);
    if (&stretchDecay && param->updateUiRequested()){
        stretchDecay.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(SUSTAIN);
    if (&stretchSustain && param->updateUiRequested()){
        stretchSustain.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(RELEASE);
    if (&stretchRelease && param->updateUiRequested()){
        stretchRelease.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(LFO_FREQ);
    if (&lfoFrequency && param->updateUiRequested()){
        lfoFrequency.setValue (param->uiGet(), dontSendNotification);
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
    for (int i = 0; i < numPartials; ++i)
    {
        param=processor.getFloatParam(PARTIAL_1 + i);
        if (&partialLevel[i] && param->updateUiRequested()){
            partialLevel[i].setValue (param->uiGet(), dontSendNotification);
        }
        param=processor.getFloatParam(PARTIAL_TUNE_1 + i);
        if (&partialTune[i] && param->updateUiRequested()){
            partialTune[i].setValue (param->uiGet(), dontSendNotification);
        }
        param=processor.getFloatParam(PARTIAL_PAN_1 + i);
        if (&partialPan[i] && param->updateUiRequested()){
            partialPan[i].setValue (param->uiGet(), dontSendNotification);
        }
        param=processor.getFloatParam(PARTIAL_LFO_AMT_1 + i);
        if (&partialLfoAmt[i] && param->updateUiRequested()){
            partialLfoAmt[i].setValue (param->uiGet(), dontSendNotification);
        }
        param=processor.getFloatParam(PARTIAL_ATTACK_1 + i);
        if (&partialAttack[i] && param->updateUiRequested()){
            partialAttack[i].setValue (param->uiGet(), dontSendNotification);
        }
        param=processor.getFloatParam(PARTIAL_DECAY_1 + i);
        if (&partialDecay[i] && param->updateUiRequested()){
            partialDecay[i].setValue (param->uiGet(), dontSendNotification);
        }
        param=processor.getFloatParam(PARTIAL_SUSTAIN_1 + i);
        if (&partialSustain[i] && param->updateUiRequested()){
            partialSustain[i].setValue (param->uiGet(), dontSendNotification);
        }
        param=processor.getFloatParam(PARTIAL_RELEASE_1 + i);
        if (&partialRelease[i] && param->updateUiRequested()){
            partialRelease[i].setValue (param->uiGet(), dontSendNotification);
        }
    }

    param=processor.getFloatParam(NOISE_LEVEL);
    if (&noiseLevel && param->updateUiRequested()){
        noiseLevel.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(NOISE_LFO_AMT);
    if (&noiseLfoAmt && param->updateUiRequested()){
        noiseLfoAmt.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(NOISE_PAN);
    if (&noisePan && param->updateUiRequested()){
        noisePan.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(NOISE_ATTACK);
    if (&noiseAttack && param->updateUiRequested()){
        noiseAttack.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(NOISE_DECAY);
    if (&noiseDecay && param->updateUiRequested()){
        noiseDecay.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(NOISE_SUSTAIN);
    if (&noiseSustain && param->updateUiRequested()){
        noiseSustain.setValue (param->uiGet(), dontSendNotification);
    }
    param=processor.getFloatParam(NOISE_RELEASE);
    if (&noiseRelease && param->updateUiRequested()){
        noiseRelease.setValue (param->uiGet(), dontSendNotification);
    }

    IntParam *intParam = processor.getIntParam(LFO_SHAPE);
    if (&lfoShape && intParam->updateUiRequested()){
        lfoShape.setSelectedId(intParam->uiGet() + 1, dontSendNotification);
    }
    intParam = processor.getIntParam(NUMBER_OF_VOICES);
    if (&numberOfVoices && intParam->updateUiRequested()){
        numberOfVoices.setSelectedId(intParam->uiGet(), dontSendNotification);
    }
    intParam = processor.getIntParam(SCALE);
    if (&scale && intParam->updateUiRequested()){
        scale.setSelectedId(intParam->uiGet(), dontSendNotification);
    }
    intParam = processor.getIntParam(SCALE_ROOT);
    if (&scaleRoot && intParam->updateUiRequested()){
        scaleRoot.setSelectedId(intParam->uiGet(), dontSendNotification);
    }
}
