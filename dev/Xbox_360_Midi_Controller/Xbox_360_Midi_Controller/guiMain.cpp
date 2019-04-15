#include "360pad.h"
#include "guiMain.h"
#include "midi.h"
#include <cstring>

//https://gist.github.com/ynonp/5991618 - Connect Example
MIDI midi;
guiMain::guiMain(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Connect list widget to listener
	QObject::connect(ui.midiDeviceList, SIGNAL(itemActivated(QListWidgetItem*)),
		this, SLOT(deviceItemActivated(QListWidgetItem*)));
	//Connect button to listener
	QObject::connect(ui.deviceScan, SIGNAL(clicked()),
		this, SLOT(updatePortList()));

}

void guiMain::deviceItemActivated(QListWidgetItem *item) {
	//Code goes here
	throw item;

}

void guiMain::updatePortList() {
	//Code goes here
	//Scan for avaliable ports
	//Update list widget
	vector <string> portNames = midi.getPorts();

	for (int i = 0; i < 4 ; i++)
	{
		ui.midiDeviceList->addItem(QString::fromStdString(portNames[i]));
	}
	
	//ui.midiDeviceList->addItem((QString portNames[i])); //Add Item To List
}