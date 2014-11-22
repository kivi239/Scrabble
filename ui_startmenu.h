/********************************************************************************
** Form generated from reading UI file 'startmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTMENU_H
#define UI_STARTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartMenu
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *startGameButton;
    QPushButton *exitButton;

    void setupUi(QWidget *StartMenu)
    {
        if (StartMenu->objectName().isEmpty())
            StartMenu->setObjectName(QStringLiteral("StartMenu"));
        StartMenu->resize(473, 380);
        gridLayout_2 = new QGridLayout(StartMenu);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        startGameButton = new QPushButton(StartMenu);
        startGameButton->setObjectName(QStringLiteral("startGameButton"));
        startGameButton->setStyleSheet(QLatin1String("QPushButton {\n"
"             color: black;\n"
"             border-image: url(:/new/prefix1/background2.jpg)10 10 10 10;\n"
"             border-top: 10px transparent;\n"
"             border-bottom: 10px transparent;\n"
"             border-right: 10px transparent;\n"
"             border-left: 10px transparent;\n"
"			 font: 75 10pt \"System\";\n"
"            \n"
"         }"));
        startGameButton->setIconSize(QSize(100, 100));
        startGameButton->setAutoRepeat(false);
        startGameButton->setAutoDefault(false);
        startGameButton->setDefault(false);
        startGameButton->setFlat(true);

        gridLayout->addWidget(startGameButton, 3, 0, 1, 1);

        exitButton = new QPushButton(StartMenu);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setStyleSheet(QLatin1String("QPushButton {\n"
"             color: black;\n"
"             border-image:url(:/new/prefix1/background2.jpg) 10 100 10 100;\n"
"             border-top: 10px transparent;\n"
"             border-bottom: 10px transparent;\n"
"             border-right: 100px transparent;\n"
"             border-left: 100px transparent;\n"
"			 font: 75 10pt \"System\";\n"
"         }"));
        exitButton->setFlat(true);

        gridLayout->addWidget(exitButton, 4, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(StartMenu);

        QMetaObject::connectSlotsByName(StartMenu);
    } // setupUi

    void retranslateUi(QWidget *StartMenu)
    {
        StartMenu->setWindowTitle(QApplication::translate("StartMenu", "Form", 0));
        startGameButton->setText(QApplication::translate("StartMenu", "Start Game", 0));
        exitButton->setText(QApplication::translate("StartMenu", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class StartMenu: public Ui_StartMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
