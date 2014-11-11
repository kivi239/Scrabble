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

      //  printField();
    }

    void makeStep()
    {
        vector <Cell> result = bot->nextTurn(3, field, vocabulary);

        int xx = result.back().getX();
        int yy = result.back().getY();
        char ch = result.back().getCh();

        qDebug() << xx << " " << yy << " " << ch << "\n";

        field->setCell(xx, yy, ch);

        field->debugOutput();

        cerr << field->getCell(xx, yy) << endl;
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

