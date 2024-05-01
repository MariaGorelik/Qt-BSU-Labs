#include "FlagIceland.h"
#include <QPainter>

FlagIceland::FlagIceland(QWidget *parent): QWidget(parent), w(25), h(18)
{

}

FlagIceland::~FlagIceland()
{

}

void FlagIceland::paintEvent(QPaintEvent* pe)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QBrush brush(Qt::blue, Qt::SolidPattern);
    painter.setPen(Qt::NoPen);
    if (w*height()/h <= width())
    {
        int flagWidth = w*height()/h;
        int x_top = (width() - w*height()/h) / 2;
        painter.fillRect(x_top, 0, flagWidth, height(), brush);
        brush.setColor(Qt::white);
        int whiteWidth = 2*flagWidth/9;
        int y_horizontal = (height() - whiteWidth) / 2;
        int x_vertical = y_horizontal;
        painter.fillRect(x_top+x_vertical, 0, whiteWidth, height(), brush);
        painter.fillRect(x_top, y_horizontal, flagWidth, whiteWidth, brush);
        brush.setColor(Qt::red);
        int redWidth = whiteWidth / 2;
        painter.fillRect(x_top+x_vertical+redWidth/2, 0, redWidth, height(), brush);
        painter.fillRect(x_top, y_horizontal+redWidth/2, flagWidth, redWidth, brush);
    }
    else
    {
        int flagHeight = h*width()/w;
        int y_top = (height() - h*width()/w) / 2;
        painter.fillRect(0, y_top, width(), flagHeight, brush);
        brush.setColor(Qt::white);
        int whiteWidth = 2*width()/9;
        int y_horizontal = (flagHeight - whiteWidth) / 2 + y_top;
        int x_vertical = y_horizontal - y_top;
        painter.fillRect(x_vertical, y_top, whiteWidth, flagHeight, brush);
        painter.fillRect(0, y_horizontal, width(), whiteWidth, brush);
        brush.setColor(Qt::red);
        int redWidth = whiteWidth / 2;
        painter.fillRect(x_vertical+redWidth/2, y_top, redWidth, flagHeight, brush);
        painter.fillRect(0, y_horizontal+redWidth/2, width(), redWidth, brush);
    }
}
