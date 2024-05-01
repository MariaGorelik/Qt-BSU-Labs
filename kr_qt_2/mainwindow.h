#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenu>
#include <QContextMenuEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QLabel>
#include "CentralWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    CentralWidget* cw;
    QMenu* contextMenu;
    void closeEvent(QCloseEvent*) override;
public slots:
    void slotAbout();
    void slotChangeStatusBarInfo(QString, QString);
protected:
    virtual void contextMenuEvent(QContextMenuEvent* pe);
public slots:
    void slotEnableOpenOption();
    void slotEnableCloseOption();
    void slotEnableSaveOption();
private:
    Ui::MainWindow *ui;
    QLabel* statusBarFilename;
    QLabel* statusBarPenWidth;
    QLabel* statusBarPenStyle;
};

#endif // MAINWINDOW_H
