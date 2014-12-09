/*
  ==============================================================================

    AdditiveSynthesiser.h
    Created: 6 Dec 2014 1:23:28pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef ADDITIVESYNTHESISER_H_INCLUDED
#define ADDITIVESYNTHESISER_H_INCLUDED

#include "AdditiveSynth.h"

class AdditiveSynthesiser : public Synthesiser
{
public:
    void refreshCurrentPlaybackSampleRate ();
    
protected:
    /** Chooses a voice that is most suitable for being re-used.
     The default method will attempt to find the oldest voice that isn't the
     bottom or top note being played. If that's not suitable for your synth,
     you can override this method and do something more cunning instead.
     */
    SynthesiserVoice* findVoiceToSteal (SynthesiserSound* soundToPlay,
                                        int midiChannel,
                                        int midiNoteNumber) const;
};



#endif  // ADDITIVESYNTHESISER_H_INCLUDED
