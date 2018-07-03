#ifndef DRAW_H
#define DRAW_H

#include <QWidget>

class Widget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    QLabel *moveLabel;
    QLabel *pressLabel;
    QLabel *doubleClickLabel;
    QLabel *releaseLabel;
    QVBoxLayout *mainLayout;
};

#endif // DRAW_H
