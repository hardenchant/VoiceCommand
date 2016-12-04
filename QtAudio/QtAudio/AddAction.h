#pragma once

#include <qmainwindow.h>
#include <qstringlistmodel.h>
#include <qtableview.h>
#include <qmessagebox.h>

#include <vector>

#include "ui_AddAction.h"
#include "VoiceAction.h"

class AddAction : public QMainWindow
{
	Q_OBJECT

public:
	AddAction(QWidget *parent = Q_NULLPTR);
	~AddAction();
private:
	Ui::AddAction ui;
	QAbstractItemModel *model;
	std::vector<VoiceAction>* commands;
public slots:
	void updateList(std::vector<VoiceAction>*);
	void chooseCom(QModelIndex);
	void addEditAction();
};
