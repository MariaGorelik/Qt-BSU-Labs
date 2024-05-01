/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(866, 600);
        Widget->setStyleSheet(QString::fromUtf8("background-color: #f5c7f7;\n"
"color: #27296d"));
        gridLayoutWidget = new QWidget(Widget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 871, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(10);
        font.setBold(true);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #a393eb;\n"
"border-radius: 5px;\n"
"margin-left: 50px;\n"
"margin-right: 50px;\n"
"margin-top: 20px;\n"
"margin-bottom: 20px;"));

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("margin-left: 30px;\n"
"margin-right: 30px;\n"
"margin-top: 20px;\n"
"margin-bottom: 20px;"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(16777215, 16777215));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #a393eb;\n"
"border-radius: 5px;\n"
"margin-left: 50px;\n"
"margin-right: 50px;\n"
"margin-top: 20px;\n"
"margin-bottom: 20px;"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setStyleSheet(QString::fromUtf8("margin-left: 30px;\n"
"margin-right: 30px;\n"
"margin-top: 20px;\n"
"margin-bottom: 20px;\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(textEdit, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMaximumSize(QSize(16777215, 16777215));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: #a393eb;\n"
"border-radius: 5px;\n"
"margin-left: 50px;\n"
"margin-right: 50px;\n"
"margin-top: 20px;\n"
"margin-bottom: 20px;"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("margin-left: 30px;\n"
"margin-right: 30px;\n"
"margin-top: 20px;\n"
"margin-bottom: 20px;"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        tableWidget = new QTableWidget(Widget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(40, 180, 791, 351));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Black"));
        font1.setBold(true);
        tableWidget->setFont(font1);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setStretchLastSection(false);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(390, 550, 101, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Bulls and cows", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "Records", nullptr));
        label->setText(QCoreApplication::translate("Widget", "The game has't started", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "New game", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "Check", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Enter number", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "Result", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
