//
//  AdditiveSynthSound.h
//  Plus
//
//  Created by William Bajzek on 11/25/14.
//
//

#ifndef __Plus__AdditiveSynthSound__
#define __Plus__AdditiveSynthSound__

#include "../JuceLibraryCode/JuceHeader.h"

class AdditiveSynthSound : public SynthesiserSound
{
public:
    AdditiveSynthSound();
    
    bool appliesToNote(const int /*midiNoteNumber*/);
    bool appliesToChannel(const int /*midiChannel*/);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AdditiveSynthSound);
};

#endif /* defined(__Plus__AdditiveSynthSound__) */
