#include "node.h"
Node::Node()
{
    location.x = 0;
    location.y = 0;
}
Node::Node(double x, double y)
{
    location.x = x;
    location.y = y;
}
Point Node::getlocation()
{
    return location;
}
void Node::setlocation(double x, double y)
{
    location.x = x;
    location.y = y;
}
