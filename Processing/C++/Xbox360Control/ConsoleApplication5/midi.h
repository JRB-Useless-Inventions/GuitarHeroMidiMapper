#include "./Lib/RtMidi/RtMidi.h"
#include <iostream> //For debug
using namespace std;


vector<unsigned char> sanitizeArrayValue(vector<unsigned char> arr, int max) {
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

class MIDI
{
private:
	RtMidiOut *midiout = new RtMidiOut();
	unsigned int nPorts = midiout->getPortCount();
	
public:
	MIDI();
	~MIDI();
	vector<unsigned char> message;
	bool sendMessage(vector<unsigned char> in);
	int setPort(int port);
	
	int MAX_BITS = 3;
	int MAX_VALUE = 255;
	
};

MIDI::MIDI(){
	message.push_back(0);
	message.push_back(0);
	message.push_back(0);
	//Midi Message must be 3 bytes long
}
MIDI::~MIDI(){

}

bool MIDI::sendMessage(vector<unsigned char> in) {
	//int status = in[0];
	//int data1 = in[1];
	//int data2 = in[2];

	in = sanitizeArrayValue(in, this->MAX_VALUE);

	try
	{
		midiout->sendMessage(&in);
		return true; //Message Sent
	}
	catch (const std::exception&)
	{
		cout << 111;
		throw "MIDI Message not sent";
		return false; //Message not sent
	}	
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

int checkArraySize(int arr,int max){
	bool out = true;

	if (sizeof(arr) != max)
	{
		out = !out;
	}

	return out;
}

