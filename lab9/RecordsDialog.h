#ifndef RECORDSDIALOG_H
#define RECORDSDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QStringList>
#include <QString>

class RecordsDialog: public QDialog
{
private:
    QTableWidget* table;
    QPushButton* buttonOK;

public:
    RecordsDialog(QDialog* parent = 0);
    void setInfo(QMap<int, QString> info);
};

#endif // RECORDSDIALOG_H
