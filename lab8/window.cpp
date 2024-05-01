#include "window.h"
#include "ui_window.h"
#include "FlagUAE.h"
#include "FlagIceland.h"

Window::Window(QTabWidget *parent)
    : QTabWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    FlagUAE *f1 = new FlagUAE();
    FlagIceland *f2 = new FlagIceland();
    addTab(f1, "UAE");
    addTab(f2, "Iceland");
    setStyleSheet("background-color: #e3e1e1");
}

Window::~Window()
{
    delete ui;
}


