#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "AdditiveSynth.h"

//==============================================================================
PlusAudioProcessor::PlusAudioProcessor()
{
    parameters[ATTACK] = 1.0;
    parameters[DECAY] = 1.0;
    parameters[SUSTAIN] = 0.8;
    parameters[RELEASE] = 1.0;

    initAllParameters();

    parameters[STRETCH] = 0.0; // partial scaling

    for (int i = 0; i < numVoices; i++)
        synth.addVoice(new AdditiveSynthVoice(parameters));
    synth.addSound(new AdditiveSynthSound());
    synth.setNoteStealingEnabled(true);

}

void PlusAudioProcessor::initParameters()
{
    addFloatParam(ATTACK, "Attack", true, SAVE, &parameters[ATTACK], 0.01, 10.0);
    addFloatParam(DECAY, "Decay", true, SAVE, &parameters[DECAY], 0.01, 20.0);
    addFloatParam(SUSTAIN, "Sustain", true, SAVE, &parameters[SUSTAIN], 0.8, 1.0);
    addFloatParam(RELEASE, "Release", true, SAVE, &parameters[RELEASE], 0.01, 20.0);
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
    switch(paramIndex){
        case ATTACK: {
        }
        case DECAY: {
        }
        case SUSTAIN: {
        }
        case RELEASE: {
            runAfterParamGroupUpdate();
            getParam(paramIndex)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
            break;
        }
        default: break;
    }
}

void PlusAudioProcessor::runAfterParamGroupUpdate()
{
    getParam(ATTACK)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(DECAY)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(SUSTAIN)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    getParam(RELEASE)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
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

