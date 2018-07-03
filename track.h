#ifndef TRACK_H
#define TRACK_H
#include "immovable.h"

class Track: public Immovable
{
public:
    Track();
    Track(double x1, double y1,double x2, double y2);
    Point getendpoint();
    Point getstartpoint();
private:
    Point endpoint;
    Point startpoint;
};

#endif // TRACK_H
