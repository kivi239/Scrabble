#include "user.h"

User::User(QString _name, int lost, int win, string lastGame, int lastUserScore, int lastBotScore)
{
    name = _name;
    lostMatches = lost;
    wonMathches = win;
    lastCurrentBotScore = lastBotScore;
    lastCurrentUsersScore = lastUserScore;
    lastMatch = lastGame;
}

QString User::getFullName()
{
    return name;
}

int User::getPlayedGames()
{
    return lostMatches + wonMathches;
}

int User::getCurrentUsersScore()
{
    return lastCurrentUsersScore;
}
