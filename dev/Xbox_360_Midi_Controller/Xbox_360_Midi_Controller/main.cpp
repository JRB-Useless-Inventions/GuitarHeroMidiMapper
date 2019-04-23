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

	//Connect Controller Connection to listener
	controllerThread *ct = new controllerThread();
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
