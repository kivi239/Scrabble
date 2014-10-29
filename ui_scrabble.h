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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scrabble
{
public:

    void setupUi(QWidget *Scrabble)
    {
        if (Scrabble->objectName().isEmpty())
            Scrabble->setObjectName(QStringLiteral("Scrabble"));
        Scrabble->resize(800, 480);

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
