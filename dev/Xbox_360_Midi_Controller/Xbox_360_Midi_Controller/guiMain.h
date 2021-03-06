#pragma once

#include <QtWidgets/QMainWindow>
#include "controllerThread.h"
#include "ui_guiMain.h"



class guiMain : public QMainWindow
{
	Q_OBJECT

public:
	guiMain(QWidget *parent = Q_NULLPTR);
public slots:
	void deviceItemActivated(QListWidgetItem *item);
	void updatePortList();
	void updateControllerList(int);
	void greenButtonPressed(bool);
	void redButtonPressed(bool);
	void yellowButtonPressed(bool);
	void blueButtonPressed(bool);
	void orangeButtonPressed(bool);
signals:
	void openMidiPort(string);
	void closeMidiPort();
	vector <string> getPorts();
private:
	Ui::guiMainClass ui;
};
