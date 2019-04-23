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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
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
    QPushButton *midiMessageTest;
    QWidget *formLayoutWidget;
    QGridLayout *controllerMappingForm;
    QLabel *label_2;
    QSpinBox *yellowButtonValue;
    QSpinBox *blueButtonValue;
    QSpinBox *rootNote;
    QSpinBox *greenButtonValue;
    QSpinBox *orangeButtonValue;
    QSpinBox *redButtonValue;
    QLabel *label;
    QLabel *greenOff_Label;
    QLabel *greenOn_Label;
    QLabel *redOn_Label;
    QLabel *yellowOff_Label;
    QLabel *yellowOn_Label;
    QLabel *blueOff_Label;
    QLabel *blueOn_Label;
    QLabel *orangeOff_Label;
    QLabel *orangeOn_Label;
    QLabel *redOff_Label;
    QWidget *formLayoutWidget_2;
    QFormLayout *controllerList;
    QLabel *label_4;
    QRadioButton *controller2_Radio;
    QLabel *label_6;
    QRadioButton *controller3_Radio;
    QLabel *label_7;
    QRadioButton *controller4_Radio;
    QLabel *label_5;
    QRadioButton *controller1_Radio;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *guiMainClass)
    {
        if (guiMainClass->objectName().isEmpty())
            guiMainClass->setObjectName(QString::fromUtf8("guiMainClass"));
        guiMainClass->resize(929, 658);
        centralWidget = new QWidget(guiMainClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        midiDeviceList = new QListWidget(centralWidget);
        midiDeviceList->setObjectName(QString::fromUtf8("midiDeviceList"));
        midiDeviceList->setGeometry(QRect(40, 50, 256, 192));
        deviceScan = new QPushButton(centralWidget);
        deviceScan->setObjectName(QString::fromUtf8("deviceScan"));
        deviceScan->setGeometry(QRect(320, 60, 93, 28));
        midiMessageTest = new QPushButton(centralWidget);
        midiMessageTest->setObjectName(QString::fromUtf8("midiMessageTest"));
        midiMessageTest->setGeometry(QRect(320, 190, 93, 28));
        midiMessageTest->setFocusPolicy(Qt::NoFocus);
        midiMessageTest->setAutoFillBackground(false);
        midiMessageTest->setCheckable(true);
        midiMessageTest->setAutoExclusive(true);
        midiMessageTest->setFlat(false);
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(490, 110, 322, 221));
        controllerMappingForm = new QGridLayout(formLayoutWidget);
        controllerMappingForm->setSpacing(6);
        controllerMappingForm->setContentsMargins(11, 11, 11, 11);
        controllerMappingForm->setObjectName(QString::fromUtf8("controllerMappingForm"));
        controllerMappingForm->setSizeConstraint(QLayout::SetDefaultConstraint);
        controllerMappingForm->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        controllerMappingForm->addWidget(label_2, 1, 0, 1, 1, Qt::AlignHCenter);

        yellowButtonValue = new QSpinBox(formLayoutWidget);
        yellowButtonValue->setObjectName(QString::fromUtf8("yellowButtonValue"));

        controllerMappingForm->addWidget(yellowButtonValue, 5, 1, 1, 1);

        blueButtonValue = new QSpinBox(formLayoutWidget);
        blueButtonValue->setObjectName(QString::fromUtf8("blueButtonValue"));

        controllerMappingForm->addWidget(blueButtonValue, 6, 1, 1, 1);

        rootNote = new QSpinBox(formLayoutWidget);
        rootNote->setObjectName(QString::fromUtf8("rootNote"));

        controllerMappingForm->addWidget(rootNote, 1, 1, 1, 1);

        greenButtonValue = new QSpinBox(formLayoutWidget);
        greenButtonValue->setObjectName(QString::fromUtf8("greenButtonValue"));

        controllerMappingForm->addWidget(greenButtonValue, 3, 1, 1, 1);

        orangeButtonValue = new QSpinBox(formLayoutWidget);
        orangeButtonValue->setObjectName(QString::fromUtf8("orangeButtonValue"));

        controllerMappingForm->addWidget(orangeButtonValue, 7, 1, 1, 1);

        redButtonValue = new QSpinBox(formLayoutWidget);
        redButtonValue->setObjectName(QString::fromUtf8("redButtonValue"));

        controllerMappingForm->addWidget(redButtonValue, 4, 1, 1, 1);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        controllerMappingForm->addWidget(label, 0, 0, 1, 3, Qt::AlignHCenter);

        greenOff_Label = new QLabel(centralWidget);
        greenOff_Label->setObjectName(QString::fromUtf8("greenOff_Label"));
        greenOff_Label->setGeometry(QRect(110, 460, 102, 163));
        greenOff_Label->setCursor(QCursor(Qt::PointingHandCursor));
        greenOff_Label->setAutoFillBackground(false);
        greenOff_Label->setFrameShape(QFrame::NoFrame);
        greenOff_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/GREEN_NOT_PRESSED.png")));
        greenOff_Label->setScaledContents(true);
        greenOn_Label = new QLabel(centralWidget);
        greenOn_Label->setObjectName(QString::fromUtf8("greenOn_Label"));
        greenOn_Label->setGeometry(QRect(0, 460, 102, 161));
        greenOn_Label->setAutoFillBackground(false);
        greenOn_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/GREEN_PRESSED.png")));
        greenOn_Label->setScaledContents(true);
        redOn_Label = new QLabel(centralWidget);
        redOn_Label->setObjectName(QString::fromUtf8("redOn_Label"));
        redOn_Label->setGeometry(QRect(370, 340, 101, 161));
        redOn_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/RED_PRESSED.png")));
        redOn_Label->setScaledContents(true);
        yellowOff_Label = new QLabel(centralWidget);
        yellowOff_Label->setObjectName(QString::fromUtf8("yellowOff_Label"));
        yellowOff_Label->setGeometry(QRect(490, 450, 101, 161));
        yellowOff_Label->setCursor(QCursor(Qt::PointingHandCursor));
        yellowOff_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/YELLOW_NOT_PRESSED.png")));
        yellowOff_Label->setScaledContents(true);
        yellowOn_Label = new QLabel(centralWidget);
        yellowOn_Label->setObjectName(QString::fromUtf8("yellowOn_Label"));
        yellowOn_Label->setGeometry(QRect(600, 450, 101, 161));
        yellowOn_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/YELLOW_PRESSED.png")));
        yellowOn_Label->setScaledContents(true);
        blueOff_Label = new QLabel(centralWidget);
        blueOff_Label->setObjectName(QString::fromUtf8("blueOff_Label"));
        blueOff_Label->setGeometry(QRect(310, 570, 101, 161));
        blueOff_Label->setCursor(QCursor(Qt::PointingHandCursor));
        blueOff_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/BLUE_NOT_PRESSED.png")));
        blueOff_Label->setScaledContents(true);
        blueOn_Label = new QLabel(centralWidget);
        blueOn_Label->setObjectName(QString::fromUtf8("blueOn_Label"));
        blueOn_Label->setGeometry(QRect(420, 570, 101, 161));
        blueOn_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/BLUE_PRESSED.png")));
        blueOn_Label->setScaledContents(true);
        orangeOff_Label = new QLabel(centralWidget);
        orangeOff_Label->setObjectName(QString::fromUtf8("orangeOff_Label"));
        orangeOff_Label->setGeometry(QRect(550, 550, 101, 161));
        orangeOff_Label->setCursor(QCursor(Qt::PointingHandCursor));
        orangeOff_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/ORANGE_NOT_PRESSED.png")));
        orangeOff_Label->setScaledContents(true);
        orangeOn_Label = new QLabel(centralWidget);
        orangeOn_Label->setObjectName(QString::fromUtf8("orangeOn_Label"));
        orangeOn_Label->setGeometry(QRect(670, 550, 101, 161));
        orangeOn_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/ORANGE_PRESSED.png")));
        orangeOn_Label->setScaledContents(true);
        redOff_Label = new QLabel(centralWidget);
        redOff_Label->setObjectName(QString::fromUtf8("redOff_Label"));
        redOff_Label->setGeometry(QRect(240, 410, 101, 161));
        redOff_Label->setCursor(QCursor(Qt::PointingHandCursor));
        redOff_Label->setPixmap(QPixmap(QString::fromUtf8(":/Buttons/RED_NOT_PRESSED.png")));
        redOff_Label->setScaledContents(true);
        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(550, 0, 171, 111));
        controllerList = new QFormLayout(formLayoutWidget_2);
        controllerList->setSpacing(6);
        controllerList->setContentsMargins(11, 11, 11, 11);
        controllerList->setObjectName(QString::fromUtf8("controllerList"));
        controllerList->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        controllerList->setWidget(0, QFormLayout::LabelRole, label_4);

        controller2_Radio = new QRadioButton(formLayoutWidget_2);
        controller2_Radio->setObjectName(QString::fromUtf8("controller2_Radio"));
        controller2_Radio->setEnabled(false);
        controller2_Radio->setAutoExclusive(false);

        controllerList->setWidget(1, QFormLayout::FieldRole, controller2_Radio);

        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        controllerList->setWidget(2, QFormLayout::LabelRole, label_6);

        controller3_Radio = new QRadioButton(formLayoutWidget_2);
        controller3_Radio->setObjectName(QString::fromUtf8("controller3_Radio"));
        controller3_Radio->setEnabled(false);
        controller3_Radio->setAutoExclusive(false);

        controllerList->setWidget(2, QFormLayout::FieldRole, controller3_Radio);

        label_7 = new QLabel(formLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        controllerList->setWidget(3, QFormLayout::LabelRole, label_7);

        controller4_Radio = new QRadioButton(formLayoutWidget_2);
        controller4_Radio->setObjectName(QString::fromUtf8("controller4_Radio"));
        controller4_Radio->setEnabled(false);
        controller4_Radio->setAutoExclusive(false);

        controllerList->setWidget(3, QFormLayout::FieldRole, controller4_Radio);

        label_5 = new QLabel(formLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        controllerList->setWidget(1, QFormLayout::LabelRole, label_5);

        controller1_Radio = new QRadioButton(formLayoutWidget_2);
        controller1_Radio->setObjectName(QString::fromUtf8("controller1_Radio"));
        controller1_Radio->setEnabled(false);
        controller1_Radio->setCheckable(true);
        controller1_Radio->setChecked(false);
        controller1_Radio->setAutoExclusive(false);

        controllerList->setWidget(0, QFormLayout::FieldRole, controller1_Radio);

        guiMainClass->setCentralWidget(centralWidget);
        redOff_Label->raise();
        redOn_Label->raise();
        greenOn_Label->raise();
        greenOff_Label->raise();
        midiDeviceList->raise();
        deviceScan->raise();
        midiMessageTest->raise();
        formLayoutWidget->raise();
        yellowOff_Label->raise();
        yellowOn_Label->raise();
        blueOff_Label->raise();
        blueOn_Label->raise();
        orangeOff_Label->raise();
        orangeOn_Label->raise();
        formLayoutWidget_2->raise();
        menuBar = new QMenuBar(guiMainClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 929, 26));
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
        deviceScan->setText(QApplication::translate("guiMainClass", "SCAN", nullptr));
        midiMessageTest->setText(QApplication::translate("guiMainClass", "Test", nullptr));
        label_2->setText(QApplication::translate("guiMainClass", "Root Note", nullptr));
        label->setText(QApplication::translate("guiMainClass", "Controller Mapping", nullptr));
        greenOff_Label->setText(QString());
        greenOn_Label->setText(QString());
        redOn_Label->setText(QString());
        yellowOff_Label->setText(QString());
        yellowOn_Label->setText(QString());
        blueOff_Label->setText(QString());
        blueOn_Label->setText(QString());
        orangeOff_Label->setText(QString());
        orangeOn_Label->setText(QString());
        redOff_Label->setText(QString());
        label_4->setText(QApplication::translate("guiMainClass", "Controller 1", nullptr));
        controller2_Radio->setText(QString());
        label_6->setText(QApplication::translate("guiMainClass", "Controller 3", nullptr));
        controller3_Radio->setText(QString());
        label_7->setText(QApplication::translate("guiMainClass", "Controller 4", nullptr));
        controller4_Radio->setText(QString());
        label_5->setText(QApplication::translate("guiMainClass", "Controller 2", nullptr));
        controller1_Radio->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class guiMainClass: public Ui_guiMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIMAIN_H
