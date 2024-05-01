#include "Diagram.h"

Diagram::Diagram(): penColor(Qt::black), penWidth(1), brushColor(Qt::green),
    pen(penColor, penWidth, Qt::DashLine), brush(Qt::green, Qt::SolidPattern)
{
    number = rand() % 5 + 1;
    for(int i = 0; i < number; ++i)
    {
        data.push_back(rand() % 101);
    }
}
