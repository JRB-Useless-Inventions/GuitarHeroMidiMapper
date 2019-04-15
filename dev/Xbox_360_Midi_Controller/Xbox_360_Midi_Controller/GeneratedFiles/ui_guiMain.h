/********************************************************************************
** Form generated from reading UI file 'guiMain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIMAIN_H
#define UI_GUIMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiMainClass
{
public:
    QWidget *centralWidget;
    QListWidget *midiDeviceList;
    QPushButton *deviceScan;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *guiMainClass)
    {
        if (guiMainClass->objectName().isEmpty())
            guiMainClass->setObjectName(QString::fromUtf8("guiMainClass"));
        guiMainClass->resize(600, 400);
        centralWidget = new QWidget(guiMainClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        midiDeviceList = new QListWidget(centralWidget);
        new QListWidgetItem(midiDeviceList);
        new QListWidgetItem(midiDeviceList);
        new QListWidgetItem(midiDeviceList);
        midiDeviceList->setObjectName(QString::fromUtf8("midiDeviceList"));
        midiDeviceList->setGeometry(QRect(40, 50, 256, 192));
        deviceScan = new QPushButton(centralWidget);
        deviceScan->setObjectName(QString::fromUtf8("deviceScan"));
        deviceScan->setGeometry(QRect(320, 60, 93, 28));
        guiMainClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(guiMainClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        guiMainClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(guiMainClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        guiMainClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(guiMainClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        guiMainClass->setStatusBar(statusBar);

        retranslateUi(guiMainClass);

        QMetaObject::connectSlotsByName(guiMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *guiMainClass)
    {
        guiMainClass->setWindowTitle(QApplication::translate("guiMainClass", "guiMain", nullptr));

        const bool __sortingEnabled = midiDeviceList->isSortingEnabled();
        midiDeviceList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = midiDeviceList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("guiMainClass", "1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = midiDeviceList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("guiMainClass", "2", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = midiDeviceList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("guiMainClass", "3", nullptr));
        midiDeviceList->setSortingEnabled(__sortingEnabled);

        deviceScan->setText(QApplication::translate("guiMainClass", "SCAN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiMainClass: public Ui_guiMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIMAIN_H
