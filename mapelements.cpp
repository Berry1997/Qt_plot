#include "mapelements.h"
#include <iostream>
#include <QPainter>
MapElements::MapElements()
{
    Tlist.clear();
    Alist.clear();
}

int MapElements::getlenT()
{
    return Tlist.length();
}

int MapElements::getlenA()
{
    return Alist.length();
}

double MapElements::getTstartx(int i)
{
    if(i>=Tlist.length()){
        return 9999;
    }
    return Tlist[i].getx();
}
double MapElements::getTstarty(int i)
{
    if(i>=Tlist.length()){
        return 9999;
    }
    return Tlist[i].gety();
}

double MapElements::getTendx(int i)
{
    if(i>=Tlist.length()){
        return 9999;
    }
    return Tlist[i].getendpoint().x;
}

double MapElements::getTendy(int i)
{
    if(i>=Tlist.length()){
        return 9999;
    }
    return Tlist[i].getendpoint().y;
}

double MapElements::getAx(int i)
{
    if(i>=Alist.length()){
        return 9999;
    }
    return Alist[i].getx();
}
double MapElements::getAy(int i)
{
    if(i>=Alist.length()){
        return 9999;
    }
    return Alist[i].gety();
}
void MapElements::setTstart(double x, double y)
{
    start.x = x;
    start.y = y;
}

void MapElements::addTrack(double x, double y)
{
    Track t = Track(start.x,start.y,x,y);
    t.setlocation(start.x,start.y);
    Tlist.push_back(t);

    emit trackChanged();
}

void MapElements::setAGV(int index, double x, double y)
{
    if(index>=Alist.length()){return;}
    Alist[index].setlocation(x,y);
    emit agvChanged();

}

void MapElements::addAGV(double x, double y)
{
    AGV a = AGV(x,y);
    a.setlocation(x,y);
    Alist.push_back(a);
    emit agvChanged();
}

void MapElements::toXml(const QString path)
{
    QDomDocument document;
    QDomElement root = document.createElement("File");
    document.appendChild(root);
    //parse AGV
    for(int i=0;i<Alist.length();i++){
        QDomElement doc = document.createElement("AGV");
        root.appendChild(doc);
        QString a = "X"+QString::number(i+1);
        QString b = "Y"+QString::number(i+1);
        QDomElement doc_child = document.createElement(a);
        QDomText newNodeText = document.createTextNode(QString::number(Alist[i].getx()));
        doc_child.appendChild(newNodeText);
        doc.appendChild(doc_child);
        QDomElement doc_child1 = document.createElement(b);
        newNodeText = document.createTextNode(QString::number(Alist[i].gety()));
        doc_child1.appendChild(newNodeText);
        doc.appendChild(doc_child1);
    }
    //parse Track
    for(int i=0;i<Tlist.length();i++){
        QDomElement doc = document.createElement("Track");
        root.appendChild(doc);
        QString a = "StartX"+QString::number(i+1);
        QString b = "StartY"+QString::number(i+1);
        QDomElement doc_child = document.createElement(a);
        QDomText newNodeText = document.createTextNode(QString::number(Tlist[i].getstartpoint().x));
        doc_child.appendChild(newNodeText);
        doc.appendChild(doc_child);
        doc_child = document.createElement(b);
        newNodeText = document.createTextNode(QString::number(Tlist[i].getstartpoint().y));
        doc_child.appendChild(newNodeText);
        doc.appendChild(doc_child);
        a = "EndX"+QString::number(i+1);
        b = "EndY"+QString::number(i+1);
        doc_child = document.createElement(a);
        newNodeText = document.createTextNode(QString::number(Tlist[i].getendpoint().x));
        doc_child.appendChild(newNodeText);
        doc.appendChild(doc_child);
        doc_child = document.createElement(b);
        newNodeText = document.createTextNode(QString::number(Tlist[i].getendpoint().y));
        doc_child.appendChild(newNodeText);
        doc.appendChild(doc_child);
    }
    //output to file
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        qDebug()<<"fail";
    }else{
        QTextStream stream(&file);
        stream<<document.toString();
        file.close();
    }
}
void MapElements::fromXml(const QString path)
{
    Tlist.clear();
    Alist.clear();
    QDomDocument document;
    QFile file(path);

    //Check if file exists
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)||!document.setContent(&file)){
        qDebug()<<"fail to read";
    }else{
        qDebug()<<"success to read";
        //close file first
        file.close();
        QDomElement root = document.firstChildElement();//File
        QDomNodeList items = root.childNodes();//AGV & Track
        for(int i=0;i<items.count();i++){
            QDomNode itemnode = items.at(i);
            if(itemnode.isElement())
            {
                QDomElement itemelement = itemnode.toElement();
                if(itemelement.nodeName()=="AGV"){ // X, Y
                    QString x,y;
                    QDomNodeList items2 = itemelement.childNodes();
                    for(int j=0;j<2;j++){
                        QDomNode itemnode = items2.at(j);
                        QDomElement itemelement = itemnode.toElement();
                        if(j==0)
                            x=itemelement.text();
                        else
                            y=itemelement.text();
                    }
                    //std::cout<<x.toStdString()<<" "<<y.toStdString()<<" "<<std::endl;
                    addAGV(x.toDouble(),y.toDouble());
                }else if(itemelement.nodeName()=="Track"){
                    QString x1,y1,x2,y2;
                    QDomNodeList items2 = itemelement.childNodes();
                    for(int j=0;j<4;j++){
                        QDomNode itemnode = items2.at(j);
                        QDomElement itemelement = itemnode.toElement();
                        if(j==0)
                            x1=itemelement.text();
                        else if(j==1)
                            y1=itemelement.text();
                        else if(j==2)
                            x2=itemelement.text();
                        else if(j==3)
                            y2=itemelement.text();
                    }
                    setTstart(x1.toDouble(),y1.toDouble());
                    addTrack(x2.toDouble(),y2.toDouble());
                }
            }
        }
    }

}
