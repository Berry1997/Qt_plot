#include "movable.h"

Movable::Movable()
{
    Node();
}
Movable::Movable(double x, double y)
{
    Node(x,y);
}

void Movable::setxy(double x, double y)
{
    setlocation(x,y);
}

double Movable::getx()
{
    return getlocation().x;
}

double Movable::gety()
{
    return getlocation().y;
}
