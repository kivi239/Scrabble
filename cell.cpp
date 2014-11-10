#include "cell.h"

Cell::Cell()
{
}

Cell::Cell(int x, int y, char ch) : x(x), y(y), ch(ch)
{
}

int Cell::getX()
{
    return x;
}

int Cell::getY()
{
    return y;
}

char Cell::getCh()
{
    return ch;
}

Cell::~Cell()
{
}
