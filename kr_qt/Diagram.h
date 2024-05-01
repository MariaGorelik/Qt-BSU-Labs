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
    QPen pen;
    QBrush brush;
    QColor penColor;
    int penWidth;
    QColor brushColor;
public:
    Diagram();
};

#endif // DIAGRAM_H
