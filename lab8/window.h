#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QTabWidget

{
    Q_OBJECT

public:
    Window(QTabWidget *parent = nullptr);
    ~Window();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
