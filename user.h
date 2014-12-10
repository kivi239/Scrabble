#pragma once
#include "mainHeader.h"

class User
{
public:
    User(){}
    User(QString name, int lost, int win, string lastGame, int lastUserScore, int lastBotScore);
    QString getFullName();
    int getPlayedGames();
    int getCurrentUsersScore();

private:
    QString name;
    int lostMatches;
    int wonMathches;
    string lastMatch;
    int lastCurrentUsersScore;
    int lastCurrentBotScore;
};

