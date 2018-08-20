#include "RtMidi.h"
#include <iostream> //For debug
using namespace std;

class MIDI
{
private:
	RtMidiOut *midiout = new RtMidiOut();
	unsigned int nPorts = midiout->getPortCount();
public:
	vector<unsigned char> message;
	void sendMessage(vector<unsigned char> in);
	int setPort(int port);
	
};

void MIDI::sendMessage(vector<unsigned char> in) {
	//int status = in[0];
	//int data1 = in[1];
	//int data2 = in[2];

	midiout->sendMessage(&in);

	//return 0;
}

int MIDI::setPort(int port) {
	nPorts = midiout->getPortCount();

	if (nPorts == 0) {
		cout << "No ports available!\n";
	}
	else if (port > nPorts) {
		cout << "PORT NUMBER EXCEEDS MAXIMUM OF " << nPorts;
	}
	else {
		midiout->openPort(port);
		cout <<midiout->getPortName(port) << endl;
	}
	return 0;
}
