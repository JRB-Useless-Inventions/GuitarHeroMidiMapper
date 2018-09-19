# GuitarHeroMidiMapper

A MIDI Mapper for the Xbox360 Guitar Hero Contorller

## Getting Started

This program is intended for the Guitar Hero World Tour Controller, but can work with pretty much anyother device including the regular Xbox360 Gamepad.

###Sending MIDI Messages
```C++
#include "midi.h"

MIDI midi

midi.sendMessage(midi.noteOn(0,60,127)); //On Channel 0 trigger midi note 60 @ 127 Velocity ON
Sleep(1000); //Hold note for 1 sec
midi.sendMessage(midi.noteOff(0,60,0)); //On Channel 0 trigger midi note 60 @ 127 Velocity OFF
```
###Xbox360 Peripheral Trigger Event
```C++
#include "360pad.h"

Gamepad gamepad;

if (!gamepad.Refresh()){
	if (wasConnected){
		wasConnected = false;

		cout << "Please connect an Xbox 360 controller." << endl;
	}
}
else{
	//Gamepad Found!!
	cout << "Controller connected on port " << gamepad.GetPort() << endl;

	if(gamepad.IsPressed(gamepad.A.ID) == true){
		//A Button was pressed
	}

	//...
}
```
### Prerequisites

OS: Win
###Libraries
##RtMidi - https://github.com/thestk/rtmidi
##XInput - https://docs.microsoft.com/en-us/windows/desktop/xinput/xinput-versions
##Hardware: All XBOX 360 Controller Devices

## Deployment

Download loopMIDI from http://www.tobias-erichsen.de/wp-content/uploads/2015/08/loopMIDISetup_1_0_13_24.zip
Open loopMIDI.
Activate a port.
Build & Run project in IDE.
Program will link the MIDI to this port.
Connect to your favourite soft sampler.
Shred away!!!

## Authors

* **Jack Biles** - *Initial work* - [JRB-Useless-Inventions](https://github.com/JRB-Useless-Inventions)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments














* Default Map

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
Program will link the MIDI to this port.
Connect to your favourite soft sampler.
Shred away.

Default Functions:




Upcoming Features:
A GUI whcih allows the user to change which button / button combination sends out a custom midi message.
A GUI which allows for different MIDI port mapping.
OSX & Linux support.
Controller Accelerometer features.
Test XBOX One Controller Hardware
