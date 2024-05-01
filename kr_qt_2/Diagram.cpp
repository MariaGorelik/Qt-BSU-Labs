#include "Diagram.h"

Diagram::Diagram(): penColor("#000000"), penWidth(1), brushColor("#00FF00")
{
    srand(time(0));
    number = rand() % 10 + 1;
    for(int i = 0; i < number; ++i)
    {
        int n = rand() % 20;
        data.push_back(n);
    }
}

Diagram::~Diagram(){}
