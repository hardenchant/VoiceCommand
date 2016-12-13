/********************************************************************************
** Form generated from reading UI file 'AddAction.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDACTION_H
#define UI_ADDACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAction
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_command;
    QPushButton *button_path;
    QListView *listView;
    QPushButton *button_add;
    QPushButton *button_edit;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QPushButton *button_delete;
    QLineEdit *lineEdit_path;

    void setupUi(QWidget *AddAction)
    {
        if (AddAction->objectName().isEmpty())
            AddAction->setObjectName(QStringLiteral("AddAction"));
        AddAction->resize(362, 450);
        gridLayoutWidget = new QWidget(AddAction);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 301, 391));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(15, 8, 15, 10);
        lineEdit_name = new QLineEdit(gridLayoutWidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 2, 0, 1, 3);

        lineEdit_command = new QLineEdit(gridLayoutWidget);
        lineEdit_command->setObjectName(QStringLiteral("lineEdit_command"));

        gridLayout->addWidget(lineEdit_command, 6, 0, 1, 3);

        button_path = new QPushButton(gridLayoutWidget);
        button_path->setObjectName(QStringLiteral("button_path"));

        gridLayout->addWidget(button_path, 4, 2, 1, 1);

        listView = new QListView(gridLayoutWidget);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout->addWidget(listView, 0, 0, 1, 3);

        button_add = new QPushButton(gridLayoutWidget);
        button_add->setObjectName(QStringLiteral("button_add"));

        gridLayout->addWidget(button_add, 7, 0, 1, 1);

        button_edit = new QPushButton(gridLayoutWidget);
        button_edit->setObjectName(QStringLiteral("button_edit"));

        gridLayout->addWidget(button_edit, 7, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 3);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 5, 0, 1, 3);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 3);

        button_delete = new QPushButton(gridLayoutWidget);
        button_delete->setObjectName(QStringLiteral("button_delete"));

        gridLayout->addWidget(button_delete, 7, 1, 1, 1);

        lineEdit_path = new QLineEdit(gridLayoutWidget);
        lineEdit_path->setObjectName(QStringLiteral("lineEdit_path"));

        gridLayout->addWidget(lineEdit_path, 4, 0, 1, 2);


        retranslateUi(AddAction);
        QObject::connect(listView, SIGNAL(clicked(QModelIndex)), AddAction, SLOT(chooseCom(QModelIndex)));
        QObject::connect(listView, SIGNAL(entered(QModelIndex)), AddAction, SLOT(changeValue(QModelIndex)));
        QObject::connect(button_path, SIGNAL(clicked()), AddAction, SLOT(getPathDial()));
        QObject::connect(button_add, SIGNAL(clicked()), AddAction, SLOT(addAction_onClickButton()));
        QObject::connect(button_delete, SIGNAL(clicked()), AddAction, SLOT(deleteAction_onClickButton()));
        QObject::connect(button_edit, SIGNAL(clicked()), AddAction, SLOT(editAction_onClickButton()));

        QMetaObject::connectSlotsByName(AddAction);
    } // setupUi

    void retranslateUi(QWidget *AddAction)
    {
        AddAction->setWindowTitle(QApplication::translate("AddAction", "Add Voice Action", 0));
        button_path->setText(QApplication::translate("AddAction", "...", 0));
        button_add->setText(QApplication::translate("AddAction", "Add", 0));
        button_edit->setText(QApplication::translate("AddAction", "Edit", 0));
        label_3->setText(QApplication::translate("AddAction", "Command name:", 0));
        label->setText(QApplication::translate("AddAction", "Associative words:", 0));
        label_2->setText(QApplication::translate("AddAction", "Path to file:", 0));
        button_delete->setText(QApplication::translate("AddAction", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class AddAction: public Ui_AddAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDACTION_H
