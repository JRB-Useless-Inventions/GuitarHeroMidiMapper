#include "./Lib/RtMidi/RtMidi.h"
#include <iostream> //For debug
using namespace std;

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
~MIDI::MIDI(){

}

bool MIDI::sendMessage(vector<unsigned char> in) {
	//int status = in[0];
	//int data1 = in[1];
	//int data2 = in[2];

	if(checkArraySize(in,MAX_BITS) == false){

	}else{
		midiout->sendMessage(&in);

		return true; //Message Sent
	}
}

int MIDI::setPort(int port) {
	nPorts = midiout->getPortCount();

	if (nPorts == 0) {
		cout << "No ports available!\n";
		return void;
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

int checkArraySize(arr,max){
	bool out = true;

	if (length(arr) != max)
	{
		out = !out;
	}

	return out;
}
int checkArrayValue(arr,max){
	bool out = true;

	for(int i = 0; i < length(arr); i++){
		if (arr[i] > max){
			arr[i] = max;
		}
		else if (arr[i] <= 0){
			arr[i] = 0;
		}
	}

	return arr;
}
