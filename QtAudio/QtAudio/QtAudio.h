#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtAudio.h"
#include <qaudiorecorder.h>
#include <qaudioencodersettingscontrol.h>
#include <qshortcut.h>
#include <qurl.h>
#include <qmediaplayer.h>
#include <qfile.h>
#include <qdir.h>
#include <qprocess.h>
#include <qmessagebox.h>
#include <qstring.h>

#include <string>
#include <fstream>
#include <stdio.h>


#include "recog.h"
#include "AddAction.h"
#include "VoiceAction.h"

class QtAudio : public QMainWindow
{
    Q_OBJECT

public:
    QtAudio(QWidget *parent = Q_NULLPTR);
	~QtAudio();
private:
    Ui::QtAudioClass ui;
	AddAction addact_wnd;
	
	QAudioRecorder* audioRecorder;
	QAudioEncoderSettings audioSettings;
	
	std::vector<VoiceAction> commands;

	const QString settingsFilePath = QApplication::applicationDirPath() + "/data.ini";
	const QString audioFilePath = QApplication::applicationDirPath() + "/speech.wav";

	bool press;

public slots:
	void onPushButton_startRecord();
	void onPushButton_stopRecord();
	void onPushButton_recognize();
	void stopAndRecognize();
	void showDebugOptions(int check);
	void HotSlot();
private:
	size_t write_response_data(char *ptr, size_t size, size_t nmemb, void *userdata);
	size_t read_request_data(char *ptr, size_t size, size_t nmemb, void *userdata);
	void set_audio_config();
	void loadFileCfg();
	void setInterfaceAndConnects();

protected:
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);

signals:
	void sendCommands(std::vector<VoiceAction>*);
	void MyPressedKey();
};
