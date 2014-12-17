# Additive Synthesizer #

## Wishlist ##
* noise 'partial'
* velocity sensitivity control
* keyboard scaling of partial levels
* LFO tempo sync
* don't calculate envelopes for partials not in use, but if they are turned on
  in mid-note, jump straight to the sustain portion of the envelope
* aftertouch/velocity options:
  * stretch
  * partial scale (ie, pressing harder or using more velocity gives brighter
sound)
* Mono legato mode
* ADSR range switch (short/long) to make editing easier.
* ADSR helper buttons
  * reset
  * treat first partial ADSR as global (only one envelope)
* portamento
* Phase control per partial
* LFO Phase control per partial
* less ghetto UI
  * custom UI component where you can just draw in the partials
* midi CC

## Bugs ##
* When you select a tuning, when the popup menu disappears, the previous tuning
  will be selected.
* Click at the end of notes getting cut off, if the amplitudes are
  significantly different.
* Performance is poor.
* Missing labels
* scroll wheel sucks on ALL controls
* stretch ADSR knobs should look like other ADSR knobs
* make undo/redo don't work, possibly without buying a commercial license for
  PluginParameters
* voice stealing: prefer to steal unheld notes before held?
