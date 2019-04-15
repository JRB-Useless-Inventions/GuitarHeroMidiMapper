#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_guiMain.h"


class guiMain : public QMainWindow
{
	Q_OBJECT

public:
	guiMain(QWidget *parent = Q_NULLPTR);
public slots:
	void deviceItemActivated(QListWidgetItem *item);
	void updatePortList();
private:
	Ui::guiMainClass ui;
};
