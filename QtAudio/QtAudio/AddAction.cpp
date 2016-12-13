#include "AddAction.h"

AddAction::AddAction(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setCentralWidget(ui.gridLayoutWidget);
}

void AddAction::updateList(std::vector<VoiceAction>* commands) {
	QStringList commandList;
	for (auto i : *commands) {
		commandList << i.getName().data();
	}
	model = new QStringListModel(commandList);
	ui.listView->setModel(model);
	this->commands = commands;
}

void AddAction::chooseCom(QModelIndex mInd) {
	ui.lineEdit_command->clear();
	ui.lineEdit_path->clear();
	ui.lineEdit_name->clear();

	for (auto i : *commands) {
		if (QString::fromStdString(i.getName()) == mInd.data().toString()) {
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

void AddAction::addAction_onClickButton() {
	if (ui.lineEdit_name->text().toStdString() == "") {
		QMessageBox q(this);
		q.setWindowTitle("Add command error");
		q.setText("Please set name");
		q.exec();
		return;
	}
	for (auto i : *commands) {
		if (i.getName() == ui.lineEdit_name->text().toStdString()) {
			QMessageBox q(this);
			q.setText("Command already exist! Change name and try again.");
			q.exec();
			return;
		}
	}
	VoiceAction va(ui.lineEdit_name->text().toStdString(), ui.lineEdit_path->text().toStdString(),
		ui.lineEdit_command->text().toStdString());
	commands->push_back(va);
	updateList(commands);
}

void AddAction::deleteAction_onClickButton() {
	for (auto i = (*commands).begin(); i != (*commands).end(); ++i) {
		if (i->getName() == ui.listView->currentIndex().data().toString().toStdString()) {
			(*commands).erase(i);
			break;
		}
	}

	updateList(commands);
}

void AddAction::editAction_onClickButton() {
	if (ui.lineEdit_name->text().toStdString() == "") {
		QMessageBox q(this);
		q.setWindowTitle("Edit command error");
		q.setText("Please set name");
		q.exec();
		return;
	}
	VoiceAction va(ui.lineEdit_name->text().toStdString(), ui.lineEdit_path->text().toStdString(),
		ui.lineEdit_command->text().toStdString());

	for (auto i = 0; i < commands->size(); ++i) {
		if ((*commands)[i].getName() != ui.listView->currentIndex().data().toString().toStdString()) {
			if ((*commands)[i].getName() == va.getName()) {
				QMessageBox q(this);
				q.setText("Command already exist! Change name and try again.");
				q.exec();
				return;
			}
		}
		else {
			(*commands)[i] = va;
		}
	}
}

void AddAction::getPathDial() {
	QFileDialog qfd(this);
	qfd.setFileMode(QFileDialog::ExistingFile);
	qfd.setAcceptMode(QFileDialog::AcceptOpen);
	if (qfd.exec()) {
		ui.lineEdit_path->setText(QDir::toNativeSeparators(qfd.selectedFiles()[0]));
	}
}

AddAction::~AddAction()
{
}
