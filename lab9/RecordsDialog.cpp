#include "RecordsDialog.h"
#include "widget.h"
#include <QVBoxLayout>

RecordsDialog::RecordsDialog(QDialog* parent):
    QDialog(parent)
{
    table = new QTableWidget;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setColumnCount(2);
    buttonOK = new QPushButton("&OK");
    connect(buttonOK, SIGNAL(clicked()), SLOT(accept()));
    QStringList labels;
    labels << "Attempts" << "Name";
    table->setHorizontalHeaderLabels(labels);
    setWindowTitle("Records");
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(table);
    layout->addWidget((buttonOK));
    setLayout(layout);
}

void RecordsDialog::setInfo(QMap<int, QString> info)
{
    int i = 0;
    table->setVisible(true);
    QList<int> keys = info.keys();
    qSort(keys);
    for (int i = 0; i < qMin(keys.count(), 10); i++)
    {
        int key = keys.at(i);
        QString value = info.value(key);
        table->insertRow(i);
        table->setItem(i, 0, new QTableWidgetItem(QString::number(key)));
        table->setItem(i, 1, new QTableWidgetItem(value));
    }
    /*foreach(int key, info.keys())
    {
        table->insertRow(i);
        table->setItem(i, 0, new QTableWidgetItem(QString::number(key)));
        table->setItem(i, 1, new QTableWidgetItem(info.value(key)));
    }*/
}
