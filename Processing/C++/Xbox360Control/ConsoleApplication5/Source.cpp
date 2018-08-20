#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "midi.h"
#include "360pad.h"
class Button
{
public:
	Button(WORD);
	~Button();
	bool held = false;
private:

};

Button::Button(WORD id)
{

}

Button::~Button()
{
}
int main(){
	
	Gamepad gamepad;
	Button A(gamepad.A);
	Button B(gamepad.B);
	Button X(gamepad.X);
	Button Y(gamepad.Y);
	MIDI midi;
	midi.setPort(1);

	bool wasConnected = true;

	midi.message.push_back(0);
	midi.message.push_back(0);
	midi.message.push_back(0);
	//Midi Message must be 3 bytes long

	while (true)
	{
		Sleep(10);

		if (!gamepad.Refresh())
		{
			if (wasConnected)
			{
				wasConnected = false;

				cout << "Please connect an Xbox 360 controller." << endl;
			}
		}
		else
		{
			//Gamepad Found!!
			if (!wasConnected)
			{
				wasConnected = true;

				cout << "Controller connected on port " << gamepad.GetPort() << endl;
			}
			if (gamepad.IsPressed(gamepad.A)) {
				if (A.held == true)
				{
					//Do nothing...
				}
				else
				{
					// Program change: 192, 5
					midi.message[0] = 192;
					midi.message[1] = 5;
					midi.sendMessage(midi.message);
					// Control Change: 176, 7, 100 (volume)
					midi.message[0] = 176;
					midi.message[1] = 7;
					midi.message[2] = 100;
					midi.sendMessage(midi.message);
					// Note On: 144, 64, 90
					midi.message[0] = 144;
					midi.message[1] = 64;
					midi.message[2] = 90;
					midi.sendMessage(midi.message);
					//cout << midi.message << endl;
					cout << "(A) button pressed" << endl;
					A.held = false;
				}
			
				Sleep(10); // Platform-dependent ... see example in tests directory.
				A.held = true;
			}
			else {
				// Note Off: 128, 64, 40
				midi.message[0] = 128;
				midi.message[1] = 64;
				midi.message[2] = 40;
				midi.sendMessage(midi.message);
				//cout << "(A) button released" << endl;
				A.held = false;
			}
			if (gamepad.getRightTriggerValue()) {
				if(gamepad.getRightTriggerValue() == 0)
				cout << gamepad.getRightTriggerValue() << endl;

				//Send out midi message
				midi.message[0] = 224;
				midi.message[1] = 0;
				midi.message[2] = gamepad.getRightTriggerValue();
				midi.sendMessage(midi.message);
			}
			else {
				//cout << "Left Trigger Deactivated" << endl;
			}
		}
	}
}