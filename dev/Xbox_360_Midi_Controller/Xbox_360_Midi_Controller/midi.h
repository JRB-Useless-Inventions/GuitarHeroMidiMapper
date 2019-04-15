#pragma once
#include "./Libs/RtMidi/RtMidi.h"
using namespace std;

class MIDI
{
public:
	MIDI();
	~MIDI();
	vector<unsigned char> message;
	vector <string> getPorts();
	bool sendMessage(vector<unsigned char> in);
	int setPort(int port);
	vector<unsigned char> noteOn(int chnl, int pitch, int velo);
	vector<unsigned char> noteOff(int chnl, int pitch, int velo);

	int MAX_BITS = 3;
	int MAX_VALUE = 255;

private:
	RtMidiOut *midiout = new RtMidiOut();
	unsigned int nPorts = midiout->getPortCount();

};