#include "tictactoe.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tictactoe w(nullptr, 3);
    w.move(500, 5);
    w.show();
    return a.exec();
}
