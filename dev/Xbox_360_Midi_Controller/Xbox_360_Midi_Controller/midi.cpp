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
	for (int i = 0; i < arr.size(); i++) {
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
		midiout->sendMessage(&out); //Once the message is set the array is reset to 0
		return true; //Message Sent
	}
	catch (const std::exception&)
	{
		//throw "MIDI Message not sent";
		return false; //Message not sent
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

vector <string> MIDI::getPorts() {
	int nPorts = midiout->getPortCount();
	this->outputPorts.clear();
	if (nPorts == 0) {
		throw "no Ports Avalible";
	}

	for (int i = 0; i < nPorts; i++)
	{
		outputPorts.push_back(midiout->getPortName(i));
	}

	return outputPorts;
}

void MIDI::openPort(string port = "default") {
	this->closePort();
	int portNum;
	if (port == "default") {
		//Run last know active port
		for (int i = 0; i < outputPorts.size(); i++)
		{
			if (outputPorts[i] == this->lastKnownActiveOutputPort) {
				portNum = i;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < outputPorts.size(); i++)
		{
			if (outputPorts[i] == port) {
				portNum = i;
				break;
			}
			else if (i == outputPorts.size()) {
				//Port not found
				throw "Port Not Valid";
			}
		}
	}

	try
	{
		midiout->openPort(portNum);
		this->lastKnownActiveOutputPort = outputPorts[portNum];
	}
	catch (const exception&)
	{
		throw "There was an error setting the MIDI port";
	}

}

void MIDI::closePort() {

	try
	{
		midiout->closePort();
	}
	catch (const std::exception&)
	{
		throw "there was an error closing the MIDI port";
	}

}