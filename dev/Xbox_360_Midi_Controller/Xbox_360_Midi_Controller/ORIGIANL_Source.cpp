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
	void onAction(int trig);
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
void Button::onAction(int trig){
	//cout << trig << endl;
	if (trig > 0)
	{
		this->setValue(this->getDefaultValue());
	}
	else {
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
	Trigger(WORD);
	~Trigger();
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
void Trigger::onChange(int val){
	//Trigger value changed
}

int main(){
	int lastNote = 0;
	Gamepad gamepad; //360 Gamepad

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

	MIDI midi; //RtMidi
	int tuning = 52-11;
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
					//midi.sendMessage(midi.message); // Test Connection
					cout << "Controller connected on port " << gamepad.GetPort() << endl;
				}
				catch (const std::exception&)
				{
					//Alert user the midi message failed to send
					//throw "MIDI Message not sent";
				}
			}
			if (gamepad.getRightTriggerValue()) {
				if(gamepad.getRightTriggerValue() == 0)

				//Send out midi message
				midi.message[0] = 224;//Pitch Bend
				midi.message[1] = 0;
				midi.message[2] = gamepad.getRightTriggerValue(); //Value
				//midi.sendMessage(midi.message);
			}
			else {
				//cout << "Left Trigger Deactivated" << endl;
			}
			
			if (gamepad.IsPressed(StrumDown.ID) == true || gamepad.IsPressed(StrumUp.ID) == true) {
				if (StrumDown.held == true || StrumUp.held == true) {
					//Do nothing...
				}
				else {
					//Delay added to allow for human reaction times with button presses
					int delayWindow = 17; //Time delay 0.00xx ms
					int inc = 1; //0.00xxms Increment
					int note;
					for (int step = 0; step < delayWindow; step++)
					{
						gamepad.Refresh(); //Recheck state of pad
						//GREEN
						Green.onAction(gamepad.IsPressed(Green.ID));
						//RED
						Red.onAction(gamepad.IsPressed(Red.ID));
						//YELLOW
						Yellow.onAction(gamepad.IsPressed(Yellow.ID));
						//BLUE
						Blue.onAction(gamepad.IsPressed(Blue.ID));

						note = Green.getValue() +
							Red.getValue() +
							Yellow.getValue() +
							Blue.getValue();

						Sleep(inc);
					}

					//Initial Press
					midi.sendMessage(midi.noteOn(0,note+tuning,127));
					lastNote = midi.message[1];

					StrumUp.held = false;
					StrumDown.held = false;
				}

				StrumDown.held = true;
				StrumUp.held = true;
			}
			else {

				midi.sendMessage(midi.noteOff(0,lastNote,0));
				StrumUp.held = false;
				StrumDown.held = false;
			}
		}//Controller Connected
		Sleep(1);//Fallback buffer delay
	}//Forever Loop
}//Main
