#pragma once
#include "mainHeader.h"

class User
{
public:
    User(string name, int lost, int win, string lastGame, int lastUserScore, int lastBotScore);
    string getFullName();
    int getPlayedGames();
    int getCurrentUsersScore();

private:
    string name;
    int lostMatches;
    int wonMathches;
    string lastMatch;
    int lastCurrentUsersScore;
    int lastCurrentBotScore;
};

