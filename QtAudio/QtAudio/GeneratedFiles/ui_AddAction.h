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
    QLineEdit *lineEdit_path;
    QPushButton *button_path;
    QListView *listView;
    QPushButton *button_add;
    QLineEdit *lineEdit_command;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *AddAction)
    {
        if (AddAction->objectName().isEmpty())
            AddAction->setObjectName(QStringLiteral("AddAction"));
        AddAction->resize(352, 440);
        gridLayoutWidget = new QWidget(AddAction);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 301, 391));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(15, 8, 15, 10);
        lineEdit_path = new QLineEdit(gridLayoutWidget);
        lineEdit_path->setObjectName(QStringLiteral("lineEdit_path"));

        gridLayout->addWidget(lineEdit_path, 4, 0, 1, 1);

        button_path = new QPushButton(gridLayoutWidget);
        button_path->setObjectName(QStringLiteral("button_path"));

        gridLayout->addWidget(button_path, 4, 1, 1, 1);

        listView = new QListView(gridLayoutWidget);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout->addWidget(listView, 0, 0, 1, 2);

        button_add = new QPushButton(gridLayoutWidget);
        button_add->setObjectName(QStringLiteral("button_add"));

        gridLayout->addWidget(button_add, 7, 0, 1, 2);

        lineEdit_command = new QLineEdit(gridLayoutWidget);
        lineEdit_command->setObjectName(QStringLiteral("lineEdit_command"));

        gridLayout->addWidget(lineEdit_command, 6, 0, 1, 2);

        lineEdit_name = new QLineEdit(gridLayoutWidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 2, 0, 1, 2);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 5, 0, 1, 2);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 2);


        retranslateUi(AddAction);
        QObject::connect(listView, SIGNAL(clicked(QModelIndex)), AddAction, SLOT(chooseCom(QModelIndex)));
        QObject::connect(listView, SIGNAL(entered(QModelIndex)), AddAction, SLOT(changeValue(QModelIndex)));
        QObject::connect(button_add, SIGNAL(clicked()), AddAction, SLOT(addEditAction()));
        QObject::connect(button_path, SIGNAL(clicked()), AddAction, SLOT(getPathDial()));

        QMetaObject::connectSlotsByName(AddAction);
    } // setupUi

    void retranslateUi(QWidget *AddAction)
    {
        AddAction->setWindowTitle(QApplication::translate("AddAction", "Add Voice Action", 0));
        button_path->setText(QApplication::translate("AddAction", "...", 0));
        button_add->setText(QApplication::translate("AddAction", "Choose action before editing", 0));
        label_3->setText(QApplication::translate("AddAction", "Command name:", 0));
        label->setText(QApplication::translate("AddAction", "Associative words:", 0));
        label_2->setText(QApplication::translate("AddAction", "Path to file:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddAction: public Ui_AddAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDACTION_H
