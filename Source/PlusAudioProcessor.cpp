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
    parameters[PARTIAL_17] = 0.0;
    parameters[PARTIAL_18] = 0.0;
    parameters[PARTIAL_19] = 0.0;
    parameters[PARTIAL_20] = 0.0;
    parameters[PARTIAL_21] = 0.0;
    parameters[PARTIAL_22] = 0.0;
    parameters[PARTIAL_23] = 0.0;
    parameters[PARTIAL_24] = 0.0;
    parameters[PARTIAL_25] = 0.0;
    parameters[PARTIAL_26] = 0.0;
    parameters[PARTIAL_27] = 0.0;
    parameters[PARTIAL_28] = 0.0;
    parameters[PARTIAL_29] = 0.0;
    parameters[PARTIAL_30] = 0.0;
    parameters[PARTIAL_31] = 0.0;
    parameters[PARTIAL_32] = 0.0;
    parameters[PARTIAL_TUNE_1] = 0.0;
    parameters[PARTIAL_TUNE_2] = 0.0;
    parameters[PARTIAL_TUNE_3] = 0.0;
    parameters[PARTIAL_TUNE_4] = 0.0;
    parameters[PARTIAL_TUNE_5] = 0.0;
    parameters[PARTIAL_TUNE_6] = 0.0;
    parameters[PARTIAL_TUNE_7] = 0.0;
    parameters[PARTIAL_TUNE_8] = 0.0;
    parameters[PARTIAL_TUNE_9] = 0.0;
    parameters[PARTIAL_TUNE_10] = 0.0;
    parameters[PARTIAL_TUNE_11] = 0.0;
    parameters[PARTIAL_TUNE_12] = 0.0;
    parameters[PARTIAL_TUNE_13] = 0.0;
    parameters[PARTIAL_TUNE_14] = 0.0;
    parameters[PARTIAL_TUNE_15] = 0.0;
    parameters[PARTIAL_TUNE_16] = 0.0;
    parameters[PARTIAL_TUNE_17] = 0.0;
    parameters[PARTIAL_TUNE_18] = 0.0;
    parameters[PARTIAL_TUNE_19] = 0.0;
    parameters[PARTIAL_TUNE_20] = 0.0;
    parameters[PARTIAL_TUNE_21] = 0.0;
    parameters[PARTIAL_TUNE_22] = 0.0;
    parameters[PARTIAL_TUNE_23] = 0.0;
    parameters[PARTIAL_TUNE_24] = 0.0;
    parameters[PARTIAL_TUNE_25] = 0.0;
    parameters[PARTIAL_TUNE_26] = 0.0;
    parameters[PARTIAL_TUNE_27] = 0.0;
    parameters[PARTIAL_TUNE_28] = 0.0;
    parameters[PARTIAL_TUNE_29] = 0.0;
    parameters[PARTIAL_TUNE_30] = 0.0;
    parameters[PARTIAL_TUNE_31] = 0.0;
    parameters[PARTIAL_TUNE_32] = 0.0;

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
    addFloatParam(STRETCH_FINE, "Stretch_Fine", true, SAVE, &parameters[STRETCH_FINE], -0.01, 0.01);
    addFloatParam(STRETCH_ENV_AMT, "Stretch_Env_Amt", true, SAVE, &parameters[STRETCH_ENV_AMT], 0.0, 2.0);
    addFloatParam(STRETCH_ENV_AMT_FINE, "Stretch_Env_Amt_Fine", true, SAVE, &parameters[STRETCH_ENV_AMT_FINE], 0.0, 0.1);
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
    addFloatParam(PARTIAL_17, "Partial_17", true, SAVE, &parameters[PARTIAL_17], 0.0, 1.0);
    addFloatParam(PARTIAL_18, "Partial_18", true, SAVE, &parameters[PARTIAL_18], 0.0, 1.0);
    addFloatParam(PARTIAL_19, "Partial_19", true, SAVE, &parameters[PARTIAL_19], 0.0, 1.0);
    addFloatParam(PARTIAL_20, "Partial_20", true, SAVE, &parameters[PARTIAL_20], 0.0, 1.0);
    addFloatParam(PARTIAL_21, "Partial_21", true, SAVE, &parameters[PARTIAL_21], 0.0, 1.0);
    addFloatParam(PARTIAL_22, "Partial_22", true, SAVE, &parameters[PARTIAL_22], 0.0, 1.0);
    addFloatParam(PARTIAL_23, "Partial_23", true, SAVE, &parameters[PARTIAL_23], 0.0, 1.0);
    addFloatParam(PARTIAL_24, "Partial_24", true, SAVE, &parameters[PARTIAL_24], 0.0, 1.0);
    addFloatParam(PARTIAL_25, "Partial_25", true, SAVE, &parameters[PARTIAL_25], 0.0, 1.0);
    addFloatParam(PARTIAL_26, "Partial_26", true, SAVE, &parameters[PARTIAL_26], 0.0, 1.0);
    addFloatParam(PARTIAL_27, "Partial_27", true, SAVE, &parameters[PARTIAL_27], 0.0, 1.0);
    addFloatParam(PARTIAL_28, "Partial_28", true, SAVE, &parameters[PARTIAL_28], 0.0, 1.0);
    addFloatParam(PARTIAL_29, "Partial_29", true, SAVE, &parameters[PARTIAL_29], 0.0, 1.0);
    addFloatParam(PARTIAL_30, "Partial_30", true, SAVE, &parameters[PARTIAL_30], 0.0, 1.0);
    addFloatParam(PARTIAL_31, "Partial_31", true, SAVE, &parameters[PARTIAL_31], 0.0, 1.0);
    addFloatParam(PARTIAL_32, "Partial_32", true, SAVE, &parameters[PARTIAL_32], 0.0, 1.0);
    addFloatParam(PARTIAL_TUNE_1, "Partial_Tune1", true, SAVE, &parameters[PARTIAL_TUNE_1], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_2, "Partial_Tune2", true, SAVE, &parameters[PARTIAL_TUNE_2], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_3, "Partial_Tune3", true, SAVE, &parameters[PARTIAL_TUNE_3], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_4, "Partial_Tune4", true, SAVE, &parameters[PARTIAL_TUNE_4], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_5, "Partial_Tune5", true, SAVE, &parameters[PARTIAL_TUNE_5], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_6, "Partial_Tune6", true, SAVE, &parameters[PARTIAL_TUNE_6], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_7, "Partial_Tune7", true, SAVE, &parameters[PARTIAL_TUNE_7], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_8, "Partial_Tune8", true, SAVE, &parameters[PARTIAL_TUNE_8], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_9, "Partial_Tune9", true, SAVE, &parameters[PARTIAL_TUNE_9], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_10, "Partial_Tune10", true, SAVE, &parameters[PARTIAL_TUNE_10], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_11, "Partial_Tune11", true, SAVE, &parameters[PARTIAL_TUNE_11], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_12, "Partial_Tune12", true, SAVE, &parameters[PARTIAL_TUNE_12], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_13, "Partial_Tune13", true, SAVE, &parameters[PARTIAL_TUNE_13], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_14, "Partial_Tune14", true, SAVE, &parameters[PARTIAL_TUNE_14], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_15, "Partial_Tune15", true, SAVE, &parameters[PARTIAL_TUNE_15], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_16, "Partial_Tune16", true, SAVE, &parameters[PARTIAL_TUNE_16], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_17, "Partial_Tune17", true, SAVE, &parameters[PARTIAL_TUNE_17], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_18, "Partial_Tune18", true, SAVE, &parameters[PARTIAL_TUNE_18], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_19, "Partial_Tune19", true, SAVE, &parameters[PARTIAL_TUNE_19], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_20, "Partial_Tune20", true, SAVE, &parameters[PARTIAL_TUNE_20], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_21, "Partial_Tune21", true, SAVE, &parameters[PARTIAL_TUNE_21], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_22, "Partial_Tune22", true, SAVE, &parameters[PARTIAL_TUNE_22], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_23, "Partial_Tune23", true, SAVE, &parameters[PARTIAL_TUNE_23], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_24, "Partial_Tune24", true, SAVE, &parameters[PARTIAL_TUNE_24], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_25, "Partial_Tune25", true, SAVE, &parameters[PARTIAL_TUNE_25], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_26, "Partial_Tune26", true, SAVE, &parameters[PARTIAL_TUNE_26], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_27, "Partial_Tune27", true, SAVE, &parameters[PARTIAL_TUNE_27], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_28, "Partial_Tune28", true, SAVE, &parameters[PARTIAL_TUNE_28], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_29, "Partial_Tune29", true, SAVE, &parameters[PARTIAL_TUNE_29], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_30, "Partial_Tune30", true, SAVE, &parameters[PARTIAL_TUNE_30], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_31, "Partial_Tune31", true, SAVE, &parameters[PARTIAL_TUNE_31], -1.0, 1.0);
    addFloatParam(PARTIAL_TUNE_32, "Partial_Tune32", true, SAVE, &parameters[PARTIAL_TUNE_32], -1.0, 1.0);
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
    getParam(PARTIAL_17)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_18)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_19)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_20)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_21)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_22)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_23)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_24)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_25)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_26)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_27)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_28)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_29)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_30)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_31)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_32)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_1)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_2)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_3)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_4)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_5)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_6)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_7)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_8)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_9)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_10)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_11)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_12)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_13)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_14)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_15)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_16)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_17)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_18)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_19)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_20)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_21)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_22)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_23)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_24)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_25)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_26)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_27)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_28)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_29)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_30)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_31)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(PARTIAL_TUNE_32)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
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

