
#include "mainwindow.h"
//#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    vbox = new QVBoxLayout(this);
    grid = new QGridLayout();
    hbox1 = new QHBoxLayout();
    buttons.resize(3);
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            buttons[i].push_back(new QPushButton("", this));
            //buttons[i][j]->setFont(Qt::black);
            buttons[i][j]->setAutoFillBackground(true);
            buttons[i][j]->setFixedSize(std::min(height()*0.3, width()*0.3), std::min(height()*0.3, width()*0.3));
            buttons[i][j]->setContentsMargins(0, 0, 0, 0);
            grid->addWidget(buttons[i][j], i, j);
        }
    }
    hbox1->addLayout(grid);
    vbox->addLayout(hbox1);
    setLayout(vbox);
}

void MainWindow::resizeEvent(QResizeEvent* re)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            buttons[i][j]->setFixedSize(std::min(height()*0.3, width()*0.3), std::min(height()*0.3, width()*0.3));
        }
    }
}
MainWindow::~MainWindow()
{
    //delete ui;
}


