
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMap>
#include "RecordsDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    friend class RecordsDialog;
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int number; //загаданное число
    int counter;
    QStringList verticalLabels;
    QMap<int, QString> records;
    int record;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
