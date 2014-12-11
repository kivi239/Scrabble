/********************************************************************************
** Form generated from reading UI file 'createusers.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSERS_H
#define UI_CREATEUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createUsers
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *nameEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *createUsers)
    {
        if (createUsers->objectName().isEmpty())
            createUsers->setObjectName(QStringLiteral("createUsers"));
        createUsers->resize(394, 309);
        gridLayout = new QGridLayout(createUsers);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 76, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(createUsers);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        nameEdit = new QTextEdit(createUsers);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        verticalLayout->addWidget(nameEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(createUsers);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        exitButton = new QPushButton(createUsers);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(100, 76, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(createUsers);

        QMetaObject::connectSlotsByName(createUsers);
    } // setupUi

    void retranslateUi(QWidget *createUsers)
    {
        createUsers->setWindowTitle(QApplication::translate("createUsers", "Form", 0));
        label->setText(QApplication::translate("createUsers", "Enter your name", 0));
        okButton->setText(QApplication::translate("createUsers", "OK", 0));
        exitButton->setText(QApplication::translate("createUsers", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class createUsers: public Ui_createUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSERS_H
