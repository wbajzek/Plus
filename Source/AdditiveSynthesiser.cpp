/*
  ==============================================================================

    AdditiveSynthesiser.cpp
    Created: 6 Dec 2014 1:23:28pm
    Author:  William Bajzek

  ==============================================================================
*/

#include "AdditiveSynthesiser.h"

struct VoiceAgeSorter
{
    static int compareElements (SynthesiserVoice* v1, SynthesiserVoice* v2) noexcept
    {
        return v1->wasStartedBefore (*v2) ? 1 : (v2->wasStartedBefore (*v1) ? -1 : 0);
    }
};

SynthesiserVoice* AdditiveSynthesiser::findVoiceToSteal (SynthesiserSound* soundToPlay,
                                                         int /*midiChannel*/, int midiNoteNumber) const
{
    // this is a list of voices we can steal, sorted by how long they've been running
    Array<SynthesiserVoice*> usableVoices;
    usableVoices.ensureStorageAllocated (voices.size());
    
    for (int i = 0; i < voices.size(); ++i)
    {
        SynthesiserVoice* const voice = voices.getUnchecked (i);
        
        if (voice->canPlaySound (soundToPlay))
        {
            VoiceAgeSorter sorter;
            usableVoices.addSorted (sorter, voice);

        }
    }

    // steal the oldest note
    return usableVoices[voices.size()-1];
}