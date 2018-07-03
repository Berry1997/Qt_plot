#ifndef MOVABLE_H
#define MOVABLE_H

#include "node.h"

class Movable: public Node
{
public:
    Movable();
    Movable(double x, double y);
    void setxy(double x, double y);
    double getx();
    double gety();
};

#endif // MOVABLE_H
