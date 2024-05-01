#include "widget.h"
#include "ui_widget.h"
#include <QRegularExpression>
#include <QtWidgets>
#include <QtAlgorithms>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), counter(0), record(-1)
{
    ui->setupUi(this);
    QStringList horizontalLabels;
    horizontalLabels << "Number" << "Result";
    //ui->tableWidget->setHorizontalHeaderLabels(horizontalLabels);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->tableWidget->resizeRowsToContents();
    ui->textEdit->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    //connect(ui->tableWidget, SIGNAL(contentsChanged()), this, SLOT(slot_tableWidget_contentsChanged()));
    setFixedSize(866, 600);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_clicked()
{
    ui->label->setText("");
    QString str = "0123456789";
    QString strNumber;
    do
    {
        std::random_shuffle(str.begin(), str.end());
        strNumber = str.left(4);
    }
    while(strNumber[0] == '0');
    number = strNumber.toInt();

    //number = 1000 + rand() % 9000;
    ui->textEdit->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    counter = 0;
    ui->tableWidget->setRowCount(0);
}


void Widget::on_pushButton_3_clicked() //запретить редактирование таблицы
{
    QString text = ui->textEdit->toPlainText();
    ui->textEdit->setText("");
    QRegularExpression pattern("\\d{4}");
    QRegularExpressionMatch match = pattern.match(text);
    if (text.length() == 4 && match.hasMatch() && text[0] != '0')
    {
        ui->label_3->setText(QString::number(number));
        int userNumber = text.toInt();
        int row = ui->tableWidget->rowCount(); // Получаем количество строк в таблице
        ui->tableWidget->insertRow(row); // Вставляем новую пустую строку в конец таблицы
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(text));
        counter++;
        verticalLabels << QString::number(counter);
        ui->tableWidget->setVerticalHeaderLabels(verticalLabels);
        if(userNumber == number)
        {
            QString info = "Bulls: 4, Cows: 0";
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(info));
            if(counter < record || record == -1)
            {
            bool bOk;
            QString str = QInputDialog::getText(0, "Record!", "Name:",
                          QLineEdit::Normal, "", &bOk);
            if(bOk)
            {
                record = counter;
                records[record] = str;
            }
            }
            else
            {
                QMessageBox::information(0, "You win!", "Congratulations!");
            }
            ui->pushButton_3->setEnabled(false);
            ui->textEdit->setEnabled(false);
        }
        else
        {
        int digitsCounter[10]; //digit - total
        int userDigitsCounter[10];
        for(int i = 0; i < 10; ++i)
        {
            digitsCounter[i] = 0;
            userDigitsCounter[i] = 0;
        }
        int bulls = 0;
        int numberCopy = number;
        for(int i = 0; i < 4; ++i)
        {
            int digit = numberCopy % 10;
            numberCopy /= 10;
            digitsCounter[digit]++;
            int userDigit = userNumber % 10;
            userNumber /= 10;
            userDigitsCounter[userDigit]++;
            if(digit == userDigit)
                bulls++;
        }
        int totalGuessing = 0;
        for(int i = 0 ; i < 10; ++i)
        {
            int add = ((digitsCounter[i] <= userDigitsCounter[i]) ? digitsCounter[i] : userDigitsCounter[i]);
            totalGuessing += add;
        }
        int cows = totalGuessing - bulls;
        QString info = "Bulls: ";
        info += QString::number(bulls);
        info += ", Cows: ";
        info += QString::number(cows);
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(info));
        }
    }
    else
    {
        QMessageBox::information(0, "Warning", "Incorrect data");
    }
}


void Widget::on_pushButton_2_clicked()
{
    RecordsDialog* recDialog = new RecordsDialog;
    recDialog->setInfo(records);
    recDialog->exec();
    /*QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Records");
    QTableWidget* table = new QTableWidget;
    QPushButton* buttonOK = new QPushButton("&OK");
    connect(buttonOK, SIGNAL(clicked()), SLOT(accept()));
    QStringList labels;
    labels << "Attempts" << "Name";
    table->setHorizontalHeaderLabels(labels);*/

}




