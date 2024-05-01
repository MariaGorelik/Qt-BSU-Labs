#include "FlagUAE.h"
#include <QPainter>

FlagUAE::FlagUAE(QWidget *parent): QWidget(parent), prop(2)
{

}

FlagUAE::~FlagUAE()
{

}

void FlagUAE::paintEvent(QPaintEvent* pe)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QBrush brush(Qt::red, Qt::SolidPattern);
    painter.setPen(Qt::NoPen);
    if (prop*height() <= width())
    {
        int x_top = (width() - prop*height()) / 2;
        painter.fillRect(x_top, 0, height()/3, height(), brush);
        brush.setColor(QColor("#33941b"));
        int horizontalWidth = prop*height() - height()/3;
        int horizontalHeight = height()/3;
        int x_horizontal = x_top+height()/3;
        painter.fillRect(x_horizontal, 0, horizontalWidth, horizontalHeight, brush);
        brush.setColor(Qt::white);
        painter.fillRect(x_horizontal, horizontalHeight, horizontalWidth, horizontalHeight, brush);
        brush.setColor(Qt::black);
        painter.fillRect(x_horizontal, 2*horizontalHeight, horizontalWidth, horizontalHeight, brush);
    }
    else
    {
        int y_top = (height() - width()/prop) / 2;
        painter.fillRect(0, y_top, width()/6, width()/2, brush);
        brush.setColor(QColor("#33941b"));
        int horizontalWidth = width() - width()/6;
        int horizontalHeight = width()/6;
        int x_horizontal = width()/6;
        painter.fillRect(x_horizontal, y_top, horizontalWidth, horizontalHeight, brush);
        brush.setColor(Qt::white);
        painter.fillRect(x_horizontal, y_top+horizontalHeight, horizontalWidth, horizontalHeight, brush);
        brush.setColor(Qt::black);
        painter.fillRect(x_horizontal, y_top+2*horizontalHeight, horizontalWidth, horizontalHeight, brush);
    }
}
