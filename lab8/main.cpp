
#include "window.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.setWindowTitle("Flags");
    w.show();
    return a.exec();
}
