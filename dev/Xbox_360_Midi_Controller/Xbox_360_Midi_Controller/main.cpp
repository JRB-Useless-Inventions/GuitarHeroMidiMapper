#include "guiMain.h"
#include "controllerThread.h"
#include <QtWidgets/QApplication>
#include <QtCore>
#include <QObject>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	guiMain *w = new guiMain();
	w->show();

	controllerThread *ct = new controllerThread();
	//Connect GUI to Controller
	QObject::connect(
		w, SIGNAL(openMidiPort(string)),
		ct, SLOT(openMidiPort(string))
	);
	QObject::connect(
		w, SIGNAL(closeMidiPort()),
		ct, SLOT(closeMidiPort())
	);
	QObject::connect(
		w, SIGNAL(getPorts()),
		ct, SLOT(getPorts())
	);

	//Connect Controller to GUI
	
	QObject::connect(
		ct, SIGNAL(controllerConnected(int)),
		w, SLOT(updateControllerList(int))
	);

	//Connect Green Button to listener
	QObject::connect(
		ct, SIGNAL(greenButtonPressed(bool)),
		w, SLOT(greenButtonPressed(bool))
	);

	//Connect Red Button to listener
	QObject::connect(
		ct, SIGNAL(redButtonPressed(bool)),
		w, SLOT(redButtonPressed(bool))
	);

	//Connect Thread to listener
	QObject::connect(
		ct, SIGNAL(yellowButtonPressed(bool)),
		w, SLOT(yellowButtonPressed(bool))
	);

	//Connect Thread to listener
	QObject::connect(
		ct, SIGNAL(blueButtonPressed(bool)),
		w, SLOT(blueButtonPressed(bool))
	);

	//Connect Thread to listener
	QObject::connect(
		ct, SIGNAL(orangeButtonPressed(bool)),
		w, SLOT(orangeButtonPressed(bool))
	);

	ct->start();
	return a.exec();
}
