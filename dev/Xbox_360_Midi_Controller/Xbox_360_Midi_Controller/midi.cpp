#include "midi.h"
#include <iostream> //For debug

MIDI::MIDI() {
	message.push_back(0);
	message.push_back(0);
	message.push_back(0);
	//Midi Message must be 3 bytes long
}
MIDI::~MIDI() {

}

vector<unsigned char> sanitizeArrayValue(vector<unsigned char> arr, int max) {
	//If a value of an array is out of bounds, re-write to maximum value
	for (int i = 0; i < 3; i++) {
		if (arr[i] > max) {
			arr[i] = max;
		}
		else if (arr[i] < 0) {
			arr[i] = 0;
		}
	}

	return arr;
}



bool MIDI::sendMessage(vector<unsigned char> in) {
	in = sanitizeArrayValue(in, this->MAX_VALUE);
	vector<unsigned char> out = in;

	try
	{
		midiout->sendMessage(&out); //Once the message is set the marray is reset to 0
		return true; //Message Sent
	}
	catch (const std::exception&)
	{
		//throw "MIDI Message not sent";
		return false; //Message not sent
	}
}

vector <string> MIDI::getPorts() {
	nPorts = midiout->getPortCount();

	if (nPorts == 0) {
		cout << "No ports available!\n";
	}
	vector <string> portList;

	for (int i = 0; i < nPorts; i++)
	{
		portList.push_back(midiout->getPortName(i));
	}

	return portList;
}

int MIDI::setPort(int port) {
	nPorts = midiout->getPortCount();

	if (nPorts == 0) {
		cout << "No ports available!\n";
		return 0;
	}
	else if (port > nPorts) {
		cout << "PORT NUMBER EXCEEDS MAXIMUM OF " << nPorts;
	}
	else {
		try
		{
			midiout->openPort(port);
			cout << midiout->getPortName(port) << endl;
			return true; //Message sent
		}
		catch (const std::exception&)
		{
			return false; //Message not sent
		}


	}
}

vector<unsigned char> MIDI::noteOn(int chnl = 1, int pitch = 0, int velo = 0) {
	if (chnl <= 0) {
		chnl = 1;
	}
	else if (chnl > 16) {
		chnl = 16;
	}
	this->message[0] = 143 + chnl;
	this->message[1] = pitch;
	this->message[2] = velo;

	return this->message;

}

vector<unsigned char> MIDI::noteOff(int chnl = 0, int pitch = 0, int velo = 0) {
	if (chnl <= 0) {
		chnl = 1;
	}
	else if (chnl > 16) {
		chnl = 16;
	}
	this->message[0] = 127 + chnl;
	this->message[1] = pitch;
	this->message[2] = velo;

	return this->message;
}