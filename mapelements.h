#ifndef MAPELEMENTS_H
#define MAPELEMENTS_H
#include <QObject>
#include <QList>
#include <QtXml>
#include <QUrl>
#include <QFileDialog>
#include "track.h"
#include "agv.h"
class MapElements: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lenofTrack READ getlenT NOTIFY trackChanged)
    Q_PROPERTY(int lenofAGV READ getlenA NOTIFY agvChanged)

public:
    MapElements();
signals:
    void trackChanged();
    void agvChanged();
private:
    QList<Track> Tlist;
    QList<AGV> Alist;
    Point start;
public slots:
    int getlenT();
    int getlenA();
    double getTstartx(int i);
    double getTstarty(int i);
    double getTendx(int i);
    double getTendy(int i);
    double getAx(int i);
    double getAy(int i);
    void setTstart(double x,double y);
    void addTrack(double x,double y);
    void setAGV(int index, double x,double y);
    void addAGV(double x,double y);
    void toXml(const QString path);
    void fromXml(const QString path);
};

#endif // MAPELEMENTS_H
