/********************************************************************************
** Form generated from reading UI file 'scrabble.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRABBLE_H
#define UI_SCRABBLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scrabble
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layoutForScores;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *Scrabble)
    {
        if (Scrabble->objectName().isEmpty())
            Scrabble->setObjectName(QStringLiteral("Scrabble"));
        Scrabble->resize(1080, 1920);
        Scrabble->setMinimumSize(QSize(1080, 1920));
        Scrabble->setMaximumSize(QSize(1080, 1920));
        verticalLayoutWidget = new QWidget(Scrabble);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(11, 20, 1051, 331));
        layoutForScores = new QVBoxLayout(verticalLayoutWidget);
        layoutForScores->setSpacing(6);
        layoutForScores->setContentsMargins(11, 11, 11, 11);
        layoutForScores->setObjectName(QStringLiteral("layoutForScores"));
        layoutForScores->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(Scrabble);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 420, 1051, 1041));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(Scrabble);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 1540, 1041, 311));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Scrabble);

        QMetaObject::connectSlotsByName(Scrabble);
    } // setupUi

    void retranslateUi(QWidget *Scrabble)
    {
        Scrabble->setWindowTitle(QApplication::translate("Scrabble", "Scrabble", 0));
    } // retranslateUi

};

namespace Ui {
    class Scrabble: public Ui_Scrabble {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRABBLE_H
