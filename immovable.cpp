#include "immovable.h"

Immovable::Immovable()
{
    Node();
}

Immovable::Immovable(double x, double y)
{
    Node(x,y);
}

double Immovable::getx()
{
    return getlocation().x;
}

double Immovable::gety()
{
    return getlocation().y;
}
