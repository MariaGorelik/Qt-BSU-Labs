#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class ListWidget; }
QT_END_NAMESPACE

class ListWidget : public QWidget
{
    Q_OBJECT

public:
    ListWidget(QWidget *parent = nullptr);
    ~ListWidget();
private slots:
    void addItemPtr(QListWidget*);
    void addItem();
    void renameItemsPtr(QListWidget*);
    void renameItems();
    void removeItemsPtr(QListWidget*);
    void removeItems();
    void clearItems();
    void movingToRight();
    void movingToLeft();
    void changeIconMode();
    void sortListWidget1();
    void sortListWidget2();
    void changeSelectionMode();
    void disableMovingToRight();
    void disableMovingToLeft();
private:
    Ui::ListWidget *ui;
    QListWidget *lw1;
    QListWidget *lw2;
    QPushButton *moveToRight;
    QPushButton *moveToLeft;
    QPushButton *add1;
    QPushButton *rename1;
    QPushButton *remove1;
    QPushButton *removeAll1;
    QPushButton *add2;
    QPushButton *rename2;
    QPushButton *remove2;
    QPushButton *removeAll2;
    QPushButton *iconMode;
    QPushButton *sort1;
    QPushButton *sort2;
    QPushButton *selectionMode1;
    QPushButton *selectionMode2;
};

#endif // LISTWIDGET_H
