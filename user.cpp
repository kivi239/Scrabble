#include "user.h"

User::User(string name, int lost, int win, string lastGame, int lastUserScore, int lastBotScore)
{
    name = name;
    lostMatches = lost;
    wonMathches = win;
    lastCurrentBotScore = lastBotScore;
    lastCurrentUsersScore = lastUserScore;
    lastMatch = lastGame;
}

string User::getFullName()
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
