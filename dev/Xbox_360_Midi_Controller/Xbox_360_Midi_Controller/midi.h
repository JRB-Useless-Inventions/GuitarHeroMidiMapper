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
	vector<unsigned char> noteOn(int chnl, int pitch, int velo);
	vector<unsigned char> noteOff(int chnl, int pitch, int velo);
	void closePort();
	void openPort(string);

	vector <string> outputPorts;
	string activePort;

private:
	int MAX_BITS = 3;
	int MAX_VALUE = 255;
	RtMidiOut *midiout = new RtMidiOut();
	string lastKnownActiveOutputPort;
};

