# GuitarHeroMidiMapper
A MIDI Mapper for any Guitar Hero Contorller

Fret 0 : None
Fret 1 : G
Fret 2 : R
Fret 3 : G+R
Fret 4 : Y
Fret 5 : Y+G
Fret 6 : Y+R
Fret 7 : Y+G+R
Fret 8 : B
Fret 9 : B+G
Fret 10 : B+R
Fret 11 : B+G+R
Fret 12 : B+Y
Fret 13 : B+Y+G
Fret 14 : B+Y+R
Fret 15 : B+Y+G+R
	
Green, Red, Yellow and Blue are mapped as Notes.
Orange is TBC on functionality.

Download loopMIDI from http://www.tobias-erichsen.de/wp-content/uploads/2015/08/loopMIDISetup_1_0_13_24.zip
Open loopMIDI.
Activate a port.
Program will link the MIDI to this port. No error checking as of yet, to alter access midi.h and change the midiout->openport(x) to the relevant port number.
Connect to a software device via the ‘Preferences’ menu.
Shred away.
