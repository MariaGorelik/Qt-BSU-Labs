#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cw = new CentralWidget;
    setCentralWidget(cw);
    connect(ui->actionOpen, &QAction::triggered, this->cw, &CentralWidget::slotOpen);
    connect(ui->actionSave, &QAction::triggered, this->cw, &CentralWidget::slotSave);
    connect(ui->actionSave_as, &QAction::triggered, this->cw, &CentralWidget::slotSaveAs);
    connect(ui->actionClose, &QAction::triggered, this->cw, &CentralWidget::slotClose);
    connect(ui->actionPen, &QAction::triggered, this->cw, &CentralWidget::slotChoosePenColor);
    connect(ui->actionBrush, &QAction::triggered, this->cw, &CentralWidget::slotChooseBrushColor);
    connect(cw, SIGNAL(enableOpenOption()), this, SLOT(slotEnableOpenOption()));
    connect(cw, SIGNAL(enableCloseOption()), this, SLOT(slotEnableCloseOption()));
    connect(cw, SIGNAL(enableSaveOption()), this, SLOT(slotEnableSaveOption()));
    contextMenu = new QMenu(this);
    contextMenu->addAction("Change pen width");
    connect(contextMenu, SIGNAL(triggered(QAction*)), cw, SLOT(slotChangePenWidth()) );
    connect(ui->actionExit, &QAction::triggered, this, &QMainWindow::close);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::slotAbout);
    statusBarFilename = new QLabel(this);
    statusBarFilename->setText("untitled");
    statusBarPenWidth = new QLabel(this);
    statusBarPenWidth->setText(QString::number(cw->getPenWidth()) + " px");
    statusBarPenStyle = new QLabel(this);
    statusBarPenStyle->setText("Pen style: SolidLine");
    statusBar()->addWidget(statusBarFilename);
    statusBar()->addWidget(statusBarPenWidth);
    statusBar()->addWidget(statusBarPenStyle);
    connect(cw, &CentralWidget::changeStatusBarInfo, this, slotChangeStatusBarInfo);
}

void MainWindow::slotEnableOpenOption()
{
    ui->actionOpen->setEnabled(true);
}

void MainWindow::slotEnableCloseOption()
{
    ui->actionClose->setEnabled(true);
}

void MainWindow::slotEnableSaveOption()
{
    ui->actionSave->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contextMenuEvent(QContextMenuEvent* pe)
{
    contextMenu->exec(pe->globalPos());
}

void MainWindow::closeEvent(QCloseEvent* ce)
{
    if(!cw->getIsSaved())
    {
        cw->setIsSaved(true);
        cw->slotSaveAs();
    }
}

void MainWindow::slotAbout()
{
    QMessageBox::information(0, "About", "Gorelik Maria, group 13, variant 12");
}

void MainWindow::slotChangeStatusBarInfo(QString name, QString penWidth)
{
    statusBarFilename->setText(name);
    statusBarPenWidth->setText(penWidth + " px");
}


