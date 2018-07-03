#ifndef AGV_H
#define AGV_H

#include "movable.h"

class AGV: public Movable
{
public:
    AGV();
    AGV(double x, double y);
};

#endif // AGV_H
