#pragma once
#include "vocabulary.h"
#include "bot.h"
#include <QObject>
#include <QtCore/QObject>
#include <QtTest/QtTest>

class BotTest : public QObject
{
    Q_OBJECT
public:
    explicit BotTest(QObject *parent = 0);
    ~BotTest();

private slots:

    void init()
    {
        bot = new Bot;
    }

    void setStartWord()
    {
        string startWord = vocabulary->getRandomStartWord();
        vocabulary->add(startWord);

        for (int i = 0; i < Size; i++)
            field->setCell(2, i, startWord[i]);

        printField();
    }

    void makeStep()
    {
        vector <Cell> result = bot->nextTurn(3, field, vocabulary);
        for (int i = 0; i < (int)result.size(); i++)
        {
            Cell tmpCell = result[i];
            qDebug() << tmpCell.getX() << " " << tmpCell.getY() << " " << tmpCell.getCh() << "\n";
            field->setCell(tmpCell.getX(), tmpCell.getY(), tmpCell.getCh());
        }

        printField();
    }

    void cleanup()
    {
        delete bot;
    }

private:
    void printField();
    Bot *bot;
    Vocabulary *vocabulary;
    Field *field;
};

