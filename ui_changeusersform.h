/********************************************************************************
** Form generated from reading UI file 'changeusersform.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEUSERSFORM_H
#define UI_CHANGEUSERSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeUsersForm
{
public:
    QGridLayout *gridLayout;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *createButton;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ChangeUsersForm)
    {
        if (ChangeUsersForm->objectName().isEmpty())
            ChangeUsersForm->setObjectName(QStringLiteral("ChangeUsersForm"));
        ChangeUsersForm->resize(499, 408);
        gridLayout = new QGridLayout(ChangeUsersForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        exitButton = new QPushButton(ChangeUsersForm);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        gridLayout->addWidget(exitButton, 3, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        createButton = new QPushButton(ChangeUsersForm);
        createButton->setObjectName(QStringLiteral("createButton"));

        gridLayout->addWidget(createButton, 3, 0, 1, 1);

        listWidget = new QListWidget(ChangeUsersForm);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 3);


        retranslateUi(ChangeUsersForm);

        QMetaObject::connectSlotsByName(ChangeUsersForm);
    } // setupUi

    void retranslateUi(QWidget *ChangeUsersForm)
    {
        ChangeUsersForm->setWindowTitle(QApplication::translate("ChangeUsersForm", "Form", 0));
        exitButton->setText(QApplication::translate("ChangeUsersForm", "Exit", 0));
        createButton->setText(QApplication::translate("ChangeUsersForm", "New User", 0));
    } // retranslateUi

};

namespace Ui {
    class ChangeUsersForm: public Ui_ChangeUsersForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEUSERSFORM_H
