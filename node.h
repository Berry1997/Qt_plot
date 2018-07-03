#ifndef NODE_H
#define NODE_H
//#include <QObject>
//#include <vector>
//#include <QVector2D>
struct Point
{
    double x,y;
    Point() {x=0;y=0;}
    Point(double a,double b) {x=a;y=b;}
};
class Node
{
public:
    Node();
    Node(double x, double y);
    Point getlocation();
    void setlocation(double x, double y);
private:
    Point location;
};

#endif // NODE_H
