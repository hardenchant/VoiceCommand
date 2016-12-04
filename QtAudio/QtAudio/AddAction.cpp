#include "AddAction.h"
#include <iostream>

AddAction::AddAction(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setCentralWidget(ui.verticalLayoutWidget);
	ui.button_add->setDisabled(true);
}

void AddAction::updateList(std::vector<VoiceAction>* commands) {
	QStringList commandList;
	for (auto i : *commands) {
		commandList << i.getName().data();
	}
	commandList << "" << "New...";
	model = new QStringListModel(commandList);
	ui.listView->setModel(model);
	this->commands = commands;
}

void AddAction::chooseCom(QModelIndex mInd) {
	ui.lineEdit_command->clear();
	ui.lineEdit_path->clear();
	ui.lineEdit_name->clear();

	for (auto i : *commands) {
		if (mInd.data().toString() == "New...") {
			ui.button_add->setEnabled(true);
			ui.button_add->setText("Add action");
		}
		if (QString::fromStdString(i.getName()) == mInd.data().toString()) {
			ui.button_add->setEnabled(true);
			ui.button_add->setText("Edit action");
			ui.lineEdit_name->setText(i.getName().data());
			ui.lineEdit_path->setText(i.getPath().data());
			for (auto j : i.getWords()) {
				ui.lineEdit_command->setText(ui.lineEdit_command->text() + j.data() + ";");
			}
			break;
		}
	}
}

void AddAction::addEditAction() {
	VoiceAction va(ui.lineEdit_name->text().toStdString(), ui.lineEdit_path->text().toStdString(),
		ui.lineEdit_command->text().toStdString());

	if (ui.listView->currentIndex().data().toString() == "New...") {
		commands->push_back(va);
	}
	else
	{
		for (auto i = 0; i < commands->size(); ++i) {
			if ((*commands)[i].getName() == ui.listView->currentIndex().data().toString().toStdString()) {
				(*commands)[i] = va;
			}
		}
	}
	updateList(commands);
}

AddAction::~AddAction()
{
}
