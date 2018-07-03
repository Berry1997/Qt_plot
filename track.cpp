#include "track.h"

Track::Track()
{
    Immovable();
}
Track::Track(double x1, double y1, double x2, double y2)
{
    Immovable(x1,y1);
    startpoint.x = x1;
    startpoint.y = y1;
    endpoint.x = x2;
    endpoint.y = y2;
}

Point Track::getendpoint()
{
    return endpoint;
}
Point Track::getstartpoint()
{
    return startpoint;
}
