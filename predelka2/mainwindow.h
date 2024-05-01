
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include<QtWidgets>
#include<QVector>
#include<QWidget>


//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QWidget

{
    Q_OBJECT
protected:
    //void resizeEvent(QResizeEvent* re);
public:
    MainWindow(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent* re);
    ~MainWindow();
    QVBoxLayout* vbox;
    QHBoxLayout* hbox1;
    QGridLayout *grid;
    QVector<QVector<QPushButton*>> buttons;

private:
    //Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
