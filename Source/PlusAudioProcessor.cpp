#include "AdditiveSynth.h"
#include "PlusAudioProcessor.h"
#include "PlusAudioProcessorEditor.h"

//==============================================================================
PlusAudioProcessor::PlusAudioProcessor()
{
    parameters[ATTACK] = 0.01;
    parameters[DECAY] = 1.0;
    parameters[SUSTAIN] = 0.8;
    parameters[RELEASE] = 1.0;
    parameters[STRETCH] = 0.0;
    parameters[STRETCH_FINE] = 0.0;
    parameters[STRETCH_ENV_AMT] = 0.0;
    parameters[STRETCH_ENV_AMT_FINE] = 0.0;
    parameters[PARTIAL_1] = 1.0;
    parameters[PARTIAL_2] = 0.0;
    parameters[PARTIAL_3] = 0.0;
    parameters[PARTIAL_4] = 0.0;
    parameters[PARTIAL_5] = 0.0;
    parameters[PARTIAL_6] = 0.0;
    parameters[PARTIAL_7] = 0.0;
    parameters[PARTIAL_8] = 0.0;
    parameters[PARTIAL_9] = 0.0;
    parameters[PARTIAL_10] = 0.0;
    parameters[PARTIAL_11] = 0.0;
    parameters[PARTIAL_12] = 0.0;
    parameters[PARTIAL_13] = 0.0;
    parameters[PARTIAL_14] = 0.0;
    parameters[PARTIAL_15] = 0.0;
    parameters[PARTIAL_16] = 0.0;

    initAllParameters();


    for (int i = 0; i < numVoices; i++)
        synth.addVoice(new AdditiveSynthVoice(parameters));
    synth.addSound(new AdditiveSynthSound());
    synth.setNoteStealingEnabled(true);

}

void PlusAudioProcessor::initParameters()
{
    addFloatParam(ATTACK, "Attack", true, SAVE, &parameters[ATTACK], 0.01, 10.0);
    addFloatParam(DECAY, "Decay", true, SAVE, &parameters[DECAY], 0.01, 20.0);
    addFloatParam(SUSTAIN, "Sustain", true, SAVE, &parameters[SUSTAIN], 0.0, 1.0);
    addFloatParam(RELEASE, "Release", true, SAVE, &parameters[RELEASE], 0.01, 20.0);
    addFloatParam(STRETCH, "Stretch", true, SAVE, &parameters[STRETCH], -1.0, 1.0);
    addFloatParam(STRETCH_FINE, "Stretch_Fine", true, SAVE, &parameters[STRETCH_FINE], -0.1, 0.1);
    addFloatParam(STRETCH_ENV_AMT, "Stretch_Env_Amt", true, SAVE, &parameters[STRETCH_ENV_AMT], -1.0, 1.0);
    addFloatParam(STRETCH_ENV_AMT_FINE, "Stretch_Env_Amt_Fine", true, SAVE, &parameters[STRETCH_ENV_AMT_FINE], -0.1, 0.1);
    addFloatParam(PARTIAL_1, "Partial_1", true, SAVE, &parameters[PARTIAL_1], 0.0, 1.0);
    addFloatParam(PARTIAL_2, "Partial_2", true, SAVE, &parameters[PARTIAL_2], 0.0, 1.0);
    addFloatParam(PARTIAL_3, "Partial_3", true, SAVE, &parameters[PARTIAL_3], 0.0, 1.0);
    addFloatParam(PARTIAL_4, "Partial_4", true, SAVE, &parameters[PARTIAL_4], 0.0, 1.0);
    addFloatParam(PARTIAL_5, "Partial_5", true, SAVE, &parameters[PARTIAL_5], 0.0, 1.0);
    addFloatParam(PARTIAL_6, "Partial_6", true, SAVE, &parameters[PARTIAL_6], 0.0, 1.0);
    addFloatParam(PARTIAL_7, "Partial_7", true, SAVE, &parameters[PARTIAL_7], 0.0, 1.0);
    addFloatParam(PARTIAL_8, "Partial_8", true, SAVE, &parameters[PARTIAL_8], 0.0, 1.0);
    addFloatParam(PARTIAL_9, "Partial_9", true, SAVE, &parameters[PARTIAL_9], 0.0, 1.0);
    addFloatParam(PARTIAL_10, "Partial_10", true, SAVE, &parameters[PARTIAL_10], 0.0, 1.0);
    addFloatParam(PARTIAL_11, "Partial_11", true, SAVE, &parameters[PARTIAL_11], 0.0, 1.0);
    addFloatParam(PARTIAL_12, "Partial_12", true, SAVE, &parameters[PARTIAL_12], 0.0, 1.0);
    addFloatParam(PARTIAL_13, "Partial_13", true, SAVE, &parameters[PARTIAL_13], 0.0, 1.0);
    addFloatParam(PARTIAL_14, "Partial_14", true, SAVE, &parameters[PARTIAL_14], 0.0, 1.0);
    addFloatParam(PARTIAL_15, "Partial_15", true, SAVE, &parameters[PARTIAL_15], 0.0, 1.0);
    addFloatParam(PARTIAL_16, "Partial_16", true, SAVE, &parameters[PARTIAL_16], 0.0, 1.0);
}

PlusAudioProcessor::~PlusAudioProcessor()
{
}


const String PlusAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String PlusAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool PlusAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool PlusAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

double PlusAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PlusAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int PlusAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PlusAudioProcessor::setCurrentProgram (int index)
{
}

const String PlusAudioProcessor::getProgramName (int index)
{
    return String();
}

void PlusAudioProcessor::changeProgramName (int index, const String& newName)
{
}


void PlusAudioProcessor::runAfterParamChange(int paramIndex,UpdateFromFlags updateFromFlag)
{
  runAfterParamGroupUpdate();
  getParam(paramIndex)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
}

void PlusAudioProcessor::runAfterParamGroupUpdate()
{
    getParam(ATTACK)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(DECAY)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(SUSTAIN)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(RELEASE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(STRETCH)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(STRETCH_FINE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(STRETCH_ENV_AMT)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(STRETCH_ENV_AMT_FINE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_1)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_2)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_3)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_4)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_5)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_6)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_7)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_8)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_9)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_10)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_11)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_12)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_13)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_14)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_15)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_16)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
}

const String PlusAudioProcessor::getParameterText (int index)
{
    return String (getParameter(index), 1024);
}

//==============================================================================
void PlusAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    synth.setCurrentPlaybackSampleRate (sampleRate);
}

void PlusAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void PlusAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    buffer.clear();
    int numSamples = buffer.getNumSamples();
    keyboardState.processNextMidiBuffer(midiMessages, 0, numSamples, true);

    synth.renderNextBlock(buffer, midiMessages, 0, numSamples);
}

//==============================================================================
bool PlusAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PlusAudioProcessor::createEditor()
{
    return new PlusAudioProcessorEditor (*this);
}

//==============================================================================
void PlusAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    //Save all the parameter values into an XML tag with name JucePlugin_Name.
    XmlElement xml(JucePlugin_Name);
    saveXml(&xml,false,true);
    //Save it as binary data
    copyXmlToBinary (xml, destData);
}

void PlusAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    //Convert the binary data saved in getStateInformation(...) back into XML.
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    // Check that it is valid XML and that the tag has name JucePlugin_Name.
    if (xmlState != 0 && xmlState->getTagName()==JucePlugin_Name){
        //Preload XML values into memory
        readXml(xmlState, true);
        //Update the parameter values from the preloaded XML values
        updateProcessorHostAndUiFromXml(true,true,true);
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PlusAudioProcessor();
}

