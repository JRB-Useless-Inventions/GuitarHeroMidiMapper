#pragma once
#include "midi.h"
#include "360pad.h"
#include <QtCore>
#include <QThread>
#include <QObject>

class controllerThread : public QThread, public QObject
{
	Q_OBJECT
public:
	controllerThread();
	MIDI midi;
	Gamepad gamepad;
	Button Green;
	Button Red;
	Button Yellow;
	Button Blue;
	Button Orange;
	Button StrumUp;
	Button StrumDown;
	int tuning = 60;
	void run();
	bool wasConnected = true;
	int lastNote = 0;
public slots:
	void openMidiPort(string);
	void closeMidiPort();
	vector <string> getPorts();
signals:
	void controllerConnected(int);
	void greenButtonPressed(bool);
	void redButtonPressed(bool);
	void yellowButtonPressed(bool);
	void blueButtonPressed(bool);
	void orangeButtonPressed(bool);
};