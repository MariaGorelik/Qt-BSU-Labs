#ifndef DIAGRAM_H
#define DIAGRAM_H
#include<QVector>
#include<QPen>
#include<QBrush>
#include<QColor>
#include<QPainter>

class Diagram
{
private:
    int number;
    QVector<int> data;
    QColor penColor;
    int penWidth;
    QColor brushColor;
    //QPen pen;
    //QBrush brush;
public:
    Diagram();
    ~Diagram();
    friend class CentralWidget;
};

#endif // DIAGRAM_H
