/********************************************************************************
** Form generated from reading UI file 'QtAudio.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTAUDIO_H
#define UI_QTAUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtAudioClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button_stop;
    QPushButton *button_start;
    QLabel *label;
    QLineEdit *textOut;
    QPushButton *button_go;
    QTextEdit *textEdit;
    QPushButton *button_clear;
    QPushButton *button_recognize;
    QCheckBox *checkBox_debug;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *QtAudioClass)
    {
        if (QtAudioClass->objectName().isEmpty())
            QtAudioClass->setObjectName(QStringLiteral("QtAudioClass"));
        QtAudioClass->resize(270, 424);
        centralWidget = new QWidget(QtAudioClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 40, 201, 321));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(8);
        gridLayout->setContentsMargins(15, 8, 15, 10);
        button_stop = new QPushButton(gridLayoutWidget);
        button_stop->setObjectName(QStringLiteral("button_stop"));

        gridLayout->addWidget(button_stop, 2, 1, 1, 1);

        button_start = new QPushButton(gridLayoutWidget);
        button_start->setObjectName(QStringLiteral("button_start"));

        gridLayout->addWidget(button_start, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        textOut = new QLineEdit(gridLayoutWidget);
        textOut->setObjectName(QStringLiteral("textOut"));
        textOut->setReadOnly(true);

        gridLayout->addWidget(textOut, 6, 0, 1, 3);

        button_go = new QPushButton(gridLayoutWidget);
        button_go->setObjectName(QStringLiteral("button_go"));

        gridLayout->addWidget(button_go, 7, 0, 1, 3);

        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 8, 0, 1, 3);

        button_clear = new QPushButton(gridLayoutWidget);
        button_clear->setObjectName(QStringLiteral("button_clear"));

        gridLayout->addWidget(button_clear, 9, 2, 1, 1);

        button_recognize = new QPushButton(gridLayoutWidget);
        button_recognize->setObjectName(QStringLiteral("button_recognize"));

        gridLayout->addWidget(button_recognize, 2, 2, 1, 1);

        checkBox_debug = new QCheckBox(gridLayoutWidget);
        checkBox_debug->setObjectName(QStringLiteral("checkBox_debug"));

        gridLayout->addWidget(checkBox_debug, 0, 0, 1, 3);

        QtAudioClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtAudioClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 270, 21));
        QtAudioClass->setMenuBar(menuBar);

        retranslateUi(QtAudioClass);
        QObject::connect(button_start, SIGNAL(clicked()), QtAudioClass, SLOT(onPushButton_startRecord()));
        QObject::connect(button_stop, SIGNAL(clicked()), QtAudioClass, SLOT(onPushButton_stopRecord()));
        QObject::connect(button_recognize, SIGNAL(clicked()), QtAudioClass, SLOT(onPushButton_recognize()));
        QObject::connect(button_go, SIGNAL(pressed()), QtAudioClass, SLOT(onPushButton_startRecord()));
        QObject::connect(button_go, SIGNAL(released()), QtAudioClass, SLOT(stopAndRecognize()));
        QObject::connect(button_clear, SIGNAL(clicked()), textEdit, SLOT(clear()));
        QObject::connect(checkBox_debug, SIGNAL(stateChanged(int)), QtAudioClass, SLOT(showDebugOptions(int)));

        QMetaObject::connectSlotsByName(QtAudioClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtAudioClass)
    {
        QtAudioClass->setWindowTitle(QApplication::translate("QtAudioClass", "AudioCake", 0));
        button_stop->setText(QApplication::translate("QtAudioClass", "Stop", 0));
        button_start->setText(QApplication::translate("QtAudioClass", "Start", 0));
        label->setText(QApplication::translate("QtAudioClass", "Record:", 0));
        button_go->setText(QApplication::translate("QtAudioClass", "Go", 0));
        button_clear->setText(QApplication::translate("QtAudioClass", "Clear", 0));
        button_recognize->setText(QApplication::translate("QtAudioClass", "Recognize", 0));
        checkBox_debug->setText(QApplication::translate("QtAudioClass", "Show debug options", 0));
    } // retranslateUi

};

namespace Ui {
    class QtAudioClass: public Ui_QtAudioClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTAUDIO_H
