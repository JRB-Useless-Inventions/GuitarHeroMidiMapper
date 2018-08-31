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
	void setValue(int);
	int getValue();
	void setDefaultValue(int);
	int getDefaultValue();
	bool held = false;
	WORD ID = 0;
private:
	int value = 0;
	int defaultValue = 0;
};

Button::Button(WORD id)
{
	this->ID = id;
}

Button::~Button()
{
}

int Button::getDefaultValue() {
	return this->defaultValue;
}
void Button::setDefaultValue(int x) {
	this->defaultValue = x;
}
int Button::getValue() {
	return this->value;
}
void Button::setValue(int x) {
	this->value = x;
}

int main(){
	
	Gamepad gamepad;
	Button Green(gamepad.A);
	Green.setDefaultValue(1);
	Button Red(gamepad.B);
	Red.setDefaultValue(2);
	Button Yellow(gamepad.Y);
	Yellow.setDefaultValue(4);
	Button Blue(gamepad.X);
	Blue.setDefaultValue(8);
	Button StrumUp(gamepad.DPU);
	Button StrumDown(gamepad.DPD);

	int tuning = 60;

	MIDI midi;
	midi.setPort(1);

	bool wasConnected = true;

	// Program change: 192, 5
	midi.message[0] = 192;
	midi.message[1] = 5;
	midi.sendMessage(midi.message);
	// Control Change: 176, 7, 100 (volume)
	midi.message[0] = 176;
	midi.message[1] = 7;
	midi.message[2] = 100;
	midi.sendMessage(midi.message);

	while (true){
		if (!gamepad.Refresh()){
			if (wasConnected){
				wasConnected = false;

				cout << "Please connect an Xbox 360 controller." << endl;
			}
		}
		else{
			//Gamepad Found!!
			if (!wasConnected){
				wasConnected = true;

				cout << "Controller connected on port " << gamepad.GetPort() << endl;
			}
			if (gamepad.IsPressed(Green.ID)) {
				if (Green.held == true){
					//Do nothing...
				}
				else{
					cout << "(A) button pressed" << endl;
					Green.setValue(Green.getDefaultValue());
					Green.held = false;
				}
				Green.held = true;
			}
			else {
				//cout << "(A) button released" << endl;
				Green.held = false;
				Green.setValue(0);
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

			if (gamepad.IsPressed(StrumDown.ID)) {
				int note = Green.getValue() + 
					Red.getValue() + 
					Yellow.getValue() + 
					Blue.getValue();

				if (StrumDown.held == true) {
					//Do nothing...
				}
				else {

					// Note On: 144, 64, 90
					midi.message[0] = 144; //Note on
					midi.message[1] = note+tuning; //Pitch
					midi.message[2] = 90; //Velo
					midi.sendMessage(midi.message);

					cout << "(Down) button pressed" << endl;
					StrumDown.held = false;
				}

				Sleep(10); // Platform-dependent ... see example in tests directory.
				StrumDown.held = true;
			}
			else {
				// Note Off: 128, 64, 40
				midi.message[0] = 128;
				midi.message[2] = 90;
				midi.sendMessage(midi.message);
				//cout << "(A) button released" << endl;
				StrumDown.held = false;
			}
		}
		Sleep(10);
	}//Forever Loop
}//Main