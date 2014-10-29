#include "scrabblefunc.h"

ScrabbleFunc::ScrabbleFunc(int count) : countOfGamers(count), gamer(0), field(), newField(field),
                                        scores(new int[countOfGamers]), newWord("") {}
