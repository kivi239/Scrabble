/********************************************************************************
** Form generated from reading UI file 'scrabble.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scrabble
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *layoutForScores;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *Scrabble)
    {
        if (Scrabble->objectName().isEmpty())
            Scrabble->setObjectName(QStringLiteral("Scrabble"));
        Scrabble->setEnabled(true);
        Scrabble->resize(600, 722);
        Scrabble->setMinimumSize(QSize(324, 576));
        Scrabble->setMaximumSize(QSize(1080, 1920));
        Scrabble->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(Scrabble);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        layoutForScores = new QVBoxLayout();
        layoutForScores->setSpacing(6);
        layoutForScores->setObjectName(QStringLiteral("layoutForScores"));

        verticalLayout_2->addLayout(layoutForScores);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        verticalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));

        verticalLayout_2->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);


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
