#ifndef IMMOVABLE_H
#define IMMOVABLE_H

#include "node.h"

class Immovable: public Node
{
public:
    Immovable();
    Immovable(double x, double y);
    double getx();
    double gety();
};

#endif // IMMOVABLE_H
