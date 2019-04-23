#include "360pad.h"
#include "guiMain.h"
#include "midi.h"


using namespace std;
//https://gist.github.com/ynonp/5991618 - Connect Example
MIDI midi;
guiMain::guiMain(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QTransform trans;
	trans.rotate(90);

	//Controller Mapper Layout Init
	ui.controllerMappingForm->addWidget(ui.greenOn_Label, 3, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.greenOn_Label->setPixmap(ui.greenOn_Label->pixmap()->transformed(trans));
	
	ui.controllerMappingForm->addWidget(ui.greenOff_Label,3, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.greenOff_Label->setPixmap(ui.greenOff_Label->pixmap()->transformed(trans));

	ui.controllerMappingForm->addWidget(ui.redOn_Label, 4, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.redOn_Label->setPixmap(ui.redOn_Label->pixmap()->transformed(trans));

	ui.controllerMappingForm->addWidget(ui.redOff_Label, 4, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.redOff_Label->setPixmap(ui.redOff_Label->pixmap()->transformed(trans));

	ui.controllerMappingForm->addWidget(ui.yellowOn_Label, 5, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.yellowOn_Label->setPixmap(ui.yellowOn_Label->pixmap()->transformed(trans));

	ui.controllerMappingForm->addWidget(ui.yellowOff_Label, 5, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.yellowOff_Label->setPixmap(ui.yellowOff_Label->pixmap()->transformed(trans));

	ui.controllerMappingForm->addWidget(ui.blueOn_Label, 6, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.blueOn_Label->setPixmap(ui.blueOn_Label->pixmap()->transformed(trans));

	ui.controllerMappingForm->addWidget(ui.blueOff_Label, 6, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.blueOff_Label->setPixmap(ui.blueOff_Label->pixmap()->transformed(trans));

	ui.controllerMappingForm->addWidget(ui.orangeOn_Label, 7, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.orangeOn_Label->setPixmap(ui.orangeOn_Label->pixmap()->transformed(trans));

	ui.controllerMappingForm->addWidget(ui.orangeOff_Label, 7, 0, Qt::AlignLeft | Qt::AlignTop);
	ui.orangeOff_Label->setPixmap(ui.orangeOff_Label->pixmap()->transformed(trans));
	
	//Connect list widget to listener
	QObject::connect(ui.midiDeviceList, SIGNAL(itemActivated(QListWidgetItem*)),
		this, SLOT(deviceItemActivated(QListWidgetItem*)));

	//Connect button to listener
	QObject::connect(ui.deviceScan, SIGNAL(clicked()),
		this, SLOT(updatePortList()));
	//Connect button to listener
	QObject::connect(ui.midiMessageTest, SIGNAL(clicked()),
		this, SLOT(testMidiConnection()));
	
}

void guiMain::deviceItemActivated(QListWidgetItem *item) {
	QString s = item->text(); //Convert item into QString object
	//Code goes here
	midi.openPort(s.toStdString());
	ui.greenOff_Label->hide();
}

void guiMain::updatePortList() {
	//Code goes here
	//Scan for avaliable ports
	//Update list widget
	vector <string> portNames = midi.getPorts();
	ui.midiDeviceList->clear();
	for (int i = 0; i < portNames.size() ; i++)
	{
		ui.midiDeviceList->addItem(QString::fromStdString(portNames[i]));
	}
}

void guiMain::testMidiConnection() {
	midi.sendMessage(midi.noteOn(0, 60, 90));
}
void guiMain::updateControllerList(int portNum) {
	bool tog = true;
	switch (portNum)
	{
	case 1:
		ui.controller1_Radio->setChecked(true);
		break;
	case 2:
		ui.controller2_Radio->setChecked(true);
		break;
	case 3:
		ui.controller3_Radio->setChecked(true);
		break;
	case 4:
		ui.controller4_Radio->setChecked(true);
		break;
	}
}
void guiMain::greenButtonPressed(bool toggle) {
	qDebug() << toggle;
	if (toggle == true) {
		ui.greenOff_Label->hide();
	}
	else {
		ui.greenOff_Label->show();
	}
}

void guiMain::redButtonPressed(bool toggle) {
	qDebug() << toggle;
	if (toggle == true) {
		ui.redOff_Label->hide();
	}
	else {
		ui.redOff_Label->show();
	}
}

void guiMain::yellowButtonPressed(bool toggle) {
	qDebug() << toggle;
	if (toggle == true) {
		ui.yellowOff_Label->hide();
	}
	else {
		ui.yellowOff_Label->show();
	}
}

void guiMain::blueButtonPressed(bool toggle) {
	qDebug() << toggle;
	if (toggle == true) {
		ui.blueOff_Label->hide();
	}
	else {
		ui.blueOff_Label->show();
	}
}

void guiMain::orangeButtonPressed(bool toggle) {
	qDebug() << toggle;
	if (toggle == true) {
		ui.orangeOff_Label->hide();
	}
	else {
		ui.orangeOff_Label->show();
	}
}