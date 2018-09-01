#include <string>
#include <iostream>
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
	void onAction(bool trig);
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
void MIDI::onAction(bool trig){
	if (trig) {
		if (this->held == true){
			//Do nothing...
		}
		else{
			this->setValue(this->getDefaultValue());
			this->held = false;
		}
		this->held = true;
	}
	else {
		this->held = false;
		this->setValue(0);
	}
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

class Trigger
{
public:
	Button(WORD);
	~Button();
	void setValue(int);
	int getValue();
	WORD ID = 0;
	void onChange(int);
private:
	int value = 0;
};

Trigger::Trigger(WORD id){

	this->ID = id;
}

Trigger::~Trigger(){

}
Trigger::onChange(int val){
	//Trigger value changed
}

int main(){
	int lastNote = 0;
	Gamepad gamepad;

	Button Green(gamepad.A);
	Green.setDefaultValue(1);
	Button Red(gamepad.B);
	Red.setDefaultValue(2);
	Button Yellow(gamepad.Y);
	Yellow.setDefaultValue(4);
	Button Blue(gamepad.X);
	Blue.setDefaultValue(8);
	Button Orange(gamepad.LB);
	Orange.setDefaultValue(0);
	Button StrumUp(gamepad.DPU);
	Button StrumDown(gamepad.DPD);

	MIDI midi;
	int tuning = 32;
	midi.setPort(1);
	bool wasConnected = true;

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
				try
				{
					midi.sendMessage(midi.message); // Test Connection
					cout << "Controller connected on port " << gamepad.GetPort() << endl;
				}
				catch (const std::exception&)
				{
					//Alert user the midi message failed to send
					throw "MIDI Message not sent";
				}
			}
			//GREEN
			Green.onAction(gamepad.IsPressed(Green.ID));
			//RED
			Red.onAction(gamepad.IsPressed(Red.ID));
			//YELLOW
			Yellow.onAction(gamepad.IsPressed(Yellow.ID));
			//BLUE
			Blue.onAction(gamepad.IsPressed(Blue.ID));

			if (gamepad.getRightTriggerValue()) {
				if(gamepad.getRightTriggerValue() == 0)

				//Send out midi message
				midi.message[0] = 224;//Pitch Bend
				midi.message[1] = 0;
				midi.message[2] = gamepad.getRightTriggerValue(); //Value
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
					//Initial Press
					midi.sendMessage(midi.noteOn(0,note+tuning,127));
					lastNote = midi.message[1];

					cout << "(Down) button pressed" << endl;
					StrumDown.held = false;
				}

				Sleep(10); // Platform-dependent ... see example in tests directory.
				StrumDown.held = true;
			}
			else {

				midi.sendMessage(midi.noteOff(0,lastNote,0));
				StrumDown.held = false;
			}
		}//Controller Connected
		Sleep(10);
	}//Forever Loop
}//Main