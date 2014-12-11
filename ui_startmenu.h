/********************************************************************************
** Form generated from reading UI file 'startmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartMenu
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *exitButton;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *changePlayer;
    QPushButton *againstAndroid;
    QSpacerItem *verticalSpacer_4;
    QPushButton *startGameButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;

    void setupUi(QWidget *StartMenu)
    {
        if (StartMenu->objectName().isEmpty())
            StartMenu->setObjectName(QStringLiteral("StartMenu"));
        StartMenu->resize(520, 500);
        gridLayout_2 = new QGridLayout(StartMenu);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer_6 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_6, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(StartMenu);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        verticalLayout->addWidget(label);


        gridLayout_2->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(100, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 3, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 6, 0, 1, 1);

        exitButton = new QPushButton(StartMenu);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setStyleSheet(QLatin1String("QPushButton {		    \n"
"             color: white;\n"
"             background-color: rgb(0, 120, 150);\n"
"             border-radius: 20px;	\n"
"             border-top: 20px transparent;\n"
"             border-bottom: 20px transparent;\n"
"             border-right: 100px transparent;\n"
"             border-left: 100px transparent;\n"
"             min-height: 1.5em;\n"
"             min-width: 10em;\n"
"             font: 100 20pt \"System\";\n"
"         }"));
        exitButton->setFlat(true);

        gridLayout->addWidget(exitButton, 10, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_5, 11, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 9, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 7, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        changePlayer = new QPushButton(StartMenu);
        changePlayer->setObjectName(QStringLiteral("changePlayer"));
        changePlayer->setStyleSheet(QLatin1String("QPushButton {		    \n"
"             color: white;\n"
"             background-color: rgb(0, 120, 150);\n"
"             border-radius: 20px;	\n"
"             border-top: 20px transparent;\n"
"             border-bottom: 20px transparent;\n"
"             border-right: 100px transparent;\n"
"             border-left: 100px transparent;\n"
"             min-height: 1.5em;\n"
"             min-width: 10em;\n"
"             font: 100 20pt \"System\";\n"
"         }"));

        gridLayout->addWidget(changePlayer, 8, 1, 1, 1);

        againstAndroid = new QPushButton(StartMenu);
        againstAndroid->setObjectName(QStringLiteral("againstAndroid"));
        againstAndroid->setStyleSheet(QLatin1String("QPushButton {		    \n"
"             color: white;\n"
"             background-color: rgb(0, 120, 150);\n"
"             border-radius: 20px;	\n"
"             border-top: 20px transparent;\n"
"             border-bottom: 20px transparent;\n"
"             border-right: 100px transparent;\n"
"             border-left: 100px transparent;\n"
"             min-height: 1.5em;\n"
"             min-width: 10em;\n"
"             font: 100 20pt \"System\";\n"
"         }"));
        againstAndroid->setFlat(true);

        gridLayout->addWidget(againstAndroid, 6, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_4, 3, 1, 1, 1);

        startGameButton = new QPushButton(StartMenu);
        startGameButton->setObjectName(QStringLiteral("startGameButton"));
        startGameButton->setStyleSheet(QLatin1String("QPushButton {		    \n"
"             color: white;\n"
"             background-color: rgb(0, 120, 150);\n"
"             border-radius: 20px;	\n"
"             border-top: 20px transparent;\n"
"             border-bottom: 20px transparent;\n"
"             border-right: 100px transparent;\n"
"             border-left: 100px transparent;\n"
"             min-height: 1.5em;\n"
"             min-width: 10em;\n"
"             font: 100 20pt \"System\";\n"
"         }"));
        startGameButton->setIconSize(QSize(100, 100));
        startGameButton->setAutoRepeat(false);
        startGameButton->setAutoDefault(false);
        startGameButton->setDefault(false);
        startGameButton->setFlat(true);

        gridLayout->addWidget(startGameButton, 4, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 10, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 6, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 8, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 10, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 8, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 3, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(100, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 3, 2, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_7, 5, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 0, 1, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_9, 4, 1, 1, 1);


        retranslateUi(StartMenu);

        QMetaObject::connectSlotsByName(StartMenu);
    } // setupUi

    void retranslateUi(QWidget *StartMenu)
    {
        StartMenu->setWindowTitle(QApplication::translate("StartMenu", "Form", 0));
        label->setText(QApplication::translate("StartMenu", "TextLabel", 0));
        exitButton->setText(QApplication::translate("StartMenu", "Exit", 0));
        changePlayer->setText(QApplication::translate("StartMenu", "Change Player", 0));
        againstAndroid->setText(QApplication::translate("StartMenu", "Play Against Android", 0));
        startGameButton->setText(QApplication::translate("StartMenu", "Start Single Game", 0));
    } // retranslateUi

};

namespace Ui {
    class StartMenu: public Ui_StartMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
