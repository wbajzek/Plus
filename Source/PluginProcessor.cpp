#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "AdditiveSynth.h"

//==============================================================================
PlusAudioProcessor::PlusAudioProcessor()
{
    parameters[STRETCH] = 0.0; // partial scaling
    for (int i = 0; i < numVoices; i++)
        synth.addVoice(new AdditiveSynthVoice(parameters));
    synth.addSound(new AdditiveSynthSound());
    synth.setNoteStealingEnabled(true);
}

PlusAudioProcessor::~PlusAudioProcessor()
{
}

//==============================================================================
const String PlusAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int PlusAudioProcessor::getNumParameters()
{
    return 4;
}

float PlusAudioProcessor::getParameter (int index)
{
    return parameters[index];
}

void PlusAudioProcessor::setParameter (int index, float newValue)
{
    parameters[index] = newValue;
}

const String PlusAudioProcessor::getParameterName (int index)
{
    return String();
}

const String PlusAudioProcessor::getParameterText (int index)
{
    return String();
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

bool PlusAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PlusAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PlusAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
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
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PlusAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PlusAudioProcessor();
}

