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

    for (int i = 1; i < numPartials; ++i)
        parameters[PARTIAL_1 + i] = 0.0;

    for (int i = 0; i < numPartials; ++i)
        parameters[PARTIAL_TUNE_1 + i] = 0.0;

    for (int i = 0; i < numPartials; ++i)
        parameters[PARTIAL_PAN_1 + i] = 0.0;

    for (int i = 0; i < numPartials; ++i)
        parameters[PARTIAL_LFO_AMT_1 + i] = 0.0;

    for (int i = 0; i < numPartials; ++i)
        parameters[PARTIAL_ATTACK_1 + i] = 0.001;

    for (int i = 0; i < numPartials; ++i)
        parameters[PARTIAL_DECAY_1 + i] = 0.001;

    for (int i = 0; i < numPartials; ++i)
        parameters[PARTIAL_SUSTAIN_1 + i] = 1.0;

    for (int i = 0; i < numPartials; ++i)
        parameters[PARTIAL_RELEASE_1 + i] = 0.01;

    parameters[NOISE_LEVEL] = 0.0;
    parameters[NOISE_LFO_AMT] = 0.0;
    parameters[NOISE_PAN] = 0.0;
    parameters[NOISE_ATTACK] = 0.01;
    parameters[NOISE_DECAY] = 0.01;
    parameters[NOISE_SUSTAIN] = 1.0;
    parameters[NOISE_RELEASE] = 0.01;
    parameters[LFO_FREQ] = 7.0;
    lfoShape = SINE_WAVE_TABLE;
    numberOfVoices = 8;
    scale = 1;
    scaleRoot = 1;

    initAllParameters();
    initVoices();

    synth.addSound(new AdditiveSynthSound());
    synth.setNoteStealingEnabled(true);
}

PlusAudioProcessor::~PlusAudioProcessor()
{
    synth.clearVoices();
    synth.clearSounds();
}

void PlusAudioProcessor::initVoices()
{
    synth.clearVoices();
    removeAllActionListeners();

    for (int i = 0; i < numberOfVoices; i++)
    {
        AdditiveSynthVoice *voice = new AdditiveSynthVoice(parameters, &lfoShape, &scale, &scaleRoot);
        addActionListener(voice);
        synth.addVoice(voice);
    }

    // make sure all the voices know the current sample rate
    synth.refreshCurrentPlaybackSampleRate ();
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
    
    for (int i = 0; i < numPartials; ++i)
    {
        char xmlName[30];
        sprintf(xmlName, "Partial_%i", i + 1);
        addFloatParam(PARTIAL_1 + i, xmlName, true, SAVE, &parameters[PARTIAL_1 + i], 0.0, 1.0);
    }
    
    for (int i = 0; i < numPartials; ++i)
    {
        char xmlName[30];
        sprintf(xmlName, "Partial_Tune%i", i + 1);
        addFloatParam(PARTIAL_TUNE_1 + i, xmlName, true, SAVE, &parameters[PARTIAL_TUNE_1 + i], -1.0, 1.0);
    }
    
    for (int i = 0; i < numPartials; ++i)
    {
        char xmlName[30];
        sprintf(xmlName, "Partial_Pan%i", i + 1);
        addFloatParam(PARTIAL_PAN_1 + i, xmlName, true, SAVE, &parameters[PARTIAL_PAN_1 + i], -1.0, 1.0);
    }
    
    for (int i = 0; i < numPartials; ++i)
    {
        char xmlName[30];
        sprintf(xmlName, "Partial_LfoAmt%i", i + 1);
        addFloatParam(PARTIAL_LFO_AMT_1 + i, xmlName, true, SAVE, &parameters[PARTIAL_LFO_AMT_1 + i], 0.0, 1.0);
    }

    for (int i = 0; i < numPartials; ++i)
    {
        char xmlName[30];
        sprintf(xmlName, "Partial_Attack%i", i + 1);
        addFloatParam(PARTIAL_ATTACK_1 + i, xmlName, true, SAVE, &parameters[PARTIAL_ATTACK_1 + i], 0.001, 10.0);
    }

    for (int i = 0; i < numPartials; ++i)
    {
        char xmlName[30];
        sprintf(xmlName, "Partial_Decay%i", i + 1);
        addFloatParam(PARTIAL_DECAY_1 + i, xmlName, true, SAVE, &parameters[PARTIAL_DECAY_1 + i], 0.001, 10.0);
    }

    for (int i = 0; i < numPartials; ++i)
    {
        char xmlName[30];
        sprintf(xmlName, "Partial_Sustain%i", i + 1);
        addFloatParam(PARTIAL_SUSTAIN_1 + i, xmlName, true, SAVE, &parameters[PARTIAL_SUSTAIN_1 + i], 0.0, 1.0);
    }

    for (int i = 0; i < numPartials; ++i)
    {
        char xmlName[30];
        sprintf(xmlName, "Partial_Release%i", i + 1);
        addFloatParam(PARTIAL_RELEASE_1 + i, xmlName, true, SAVE, &parameters[PARTIAL_RELEASE_1 + i], 0.001, 10.0);
    }

    addFloatParam(NOISE_LEVEL, "Noise_Level", true, SAVE, &parameters[NOISE_LEVEL], 0.0, 1.0);
    addFloatParam(NOISE_LFO_AMT, "Noise_LfoAmt", true, SAVE, &parameters[NOISE_LFO_AMT], 0.0, 1.0);
    addFloatParam(NOISE_PAN, "Noise_Pan", true, SAVE, &parameters[NOISE_PAN], -1.0, 1.0);
    addFloatParam(NOISE_ATTACK, "Noise_Attack", true, SAVE, &parameters[NOISE_ATTACK], 0.001, 10.0);
    addFloatParam(NOISE_DECAY, "Noise_Decay", true, SAVE, &parameters[NOISE_DECAY], 0.001, 10.0);
    addFloatParam(NOISE_SUSTAIN, "Noise_Sustain", true, SAVE, &parameters[NOISE_SUSTAIN], 0.0, 1.0);
    addFloatParam(NOISE_RELEASE, "Noise_Release", true, SAVE, &parameters[NOISE_RELEASE], 0.001, 10.0);
    addFloatParam(LFO_FREQ, "Lfo_Frequency", true, SAVE, &parameters[LFO_FREQ], 0.0, 100.0);
    addIntParam(LFO_SHAPE, "Lfo_Shape", true, SAVE, &lfoShape, SINE_WAVE_TABLE, NUMBER_OF_WAVE_TABLES);
    addIntParam(NUMBER_OF_VOICES, "Number_Of_Voices", true, SAVE, &numberOfVoices, 1, 16);
    addIntParam(SCALE, "Scale", true, SAVE, &scale, 1, numberOfScales+1);
    addIntParam(SCALE_ROOT, "Scale_Root", true, SAVE, &scaleRoot, 1, 12);
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
    getParam(paramIndex)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
    switch (paramIndex) {
        case LFO_FREQ:
            sendActionMessage("LFO Frequency");
            break;
        case LFO_SHAPE:
            sendActionMessage("LFO Shape");
            break;
        case ATTACK:
        case DECAY:
        case SUSTAIN:
        case RELEASE:
            sendActionMessage("Envelope");
            break;
        default:
            break;
    }
}

void PlusAudioProcessor::runAfterParamGroupUpdate()
{
    for (int i = 0; i < NUMBER_OF_PARAMETERS; ++i)
        getParam(ATTACK + i)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
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
        initVoices();
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PlusAudioProcessor();
}

