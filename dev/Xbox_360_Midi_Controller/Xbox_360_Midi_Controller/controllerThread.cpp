#include "controllerThread.h"
#include <QtCore>
#include <QDebug>

controllerThread::controllerThread(){
	Green.setID(gamepad.A);
	Green.setDefaultValue(1);
	Red.setID(gamepad.B);
	Red.setDefaultValue(2);
	Yellow.setID(gamepad.Y);
	Yellow.setDefaultValue(4);
	Blue.setID(gamepad.X);
	Blue.setDefaultValue(8);
	Orange.setID(gamepad.LB);
	Orange.setDefaultValue(0);
	StrumUp.setID(gamepad.DPU);
	StrumDown.setID(gamepad.DPD);
}

void controllerThread::run() {
	qDebug() << "Controller Thread Running";
	while (true) {
		if (!gamepad.Refresh()) {
			if (wasConnected) {
				wasConnected = false;
				//Controller Not Connected
				qDebug() << "Please connect an Xbox 360 controller." << endl;
			}
		}
		else {
			//Gamepad Found!!
			if (!wasConnected) {
				wasConnected = true;
				qDebug() << "Controller connected on port " << gamepad.GetPort() << endl;
				//Raise event
				int port = gamepad.GetPort();
				emit this->controllerConnected(port);
			}

			emit this->greenButtonPressed(gamepad.IsPressed(Green.ID));
			emit this->redButtonPressed(gamepad.IsPressed(Red.ID));
			emit this->yellowButtonPressed(gamepad.IsPressed(Yellow.ID));
			emit this->blueButtonPressed(gamepad.IsPressed(Blue.ID));
			emit this->orangeButtonPressed(gamepad.IsPressed(Orange.ID));

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
					midi.sendMessage(midi.noteOn(0, note + tuning, 127));
					lastNote = midi.message[1];

					StrumUp.held = false;
					StrumDown.held = false;
				}

				StrumDown.held = true;
				StrumUp.held = true;
			}
			else {

				midi.sendMessage(midi.noteOff(0, lastNote, 0));
				StrumUp.held = false;
				StrumDown.held = false;
			}
		}//Controller Connected
		Sleep(1);//Fallback buffer delay
	}
	
}