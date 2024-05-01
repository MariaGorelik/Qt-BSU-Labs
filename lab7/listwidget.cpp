#include "listwidget.h"
#include "ui_listwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QInputDialog>

ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListWidget)
{
    ui->setupUi(this);
    setFixedHeight(600);
    QHBoxLayout *hbox = new QHBoxLayout(this);
    lw1 = new QListWidget(this);

    lw1->setDropIndicatorShown(true);
    lw1->setDragEnabled(true);
    lw1->setDragDropOverwriteMode(true);
    lw1->setDragDropMode(QAbstractItemView::DragDrop);
    lw1->setDefaultDropAction(Qt::TargetMoveAction);

    QListWidgetItem* item1 = new QListWidgetItem("a1");
    item1->setIcon(QIcon("notebook.png"));
    lw1->addItem(item1);
    QListWidgetItem* item2 = new QListWidgetItem("a2");
    item2->setIcon(QIcon("notebook.png"));
    lw1->addItem(item2);
    QListWidgetItem* item3 = new QListWidgetItem("a3");
    item3->setIcon(QIcon("notebook.png"));
    lw1->addItem(item3);
    //lw1->addItem("a1");
    //lw1->addItem("b1");
    //lw1->addItem("c1");
    int n1 = lw1->count() - 1;
    lw1->setCurrentRow(n1);
    add1 = new QPushButton("Add", this);
    rename1 = new QPushButton("Rename", this);
    remove1 = new QPushButton("Remove", this);
    removeAll1 = new QPushButton("Remove All", this);
    QVBoxLayout *vbox1 = new QVBoxLayout();
    QGridLayout *grid1 = new QGridLayout();
    //grid1->setSpacing(20); //////
    grid1->addWidget(add1, 0, 0);
    grid1->addWidget(rename1, 0, 1);
    grid1->addWidget(remove1, 1, 0);
    grid1->addWidget(removeAll1, 1, 1);
    vbox1->addWidget(lw1);
    vbox1->addLayout(grid1);
    selectionMode1 = new QPushButton("Enable multiselection", this);
    vbox1->addWidget(selectionMode1);
    sort1 = new QPushButton("Sort", this);
    vbox1->addWidget(sort1);

    lw2 = new QListWidget(this);
    QListWidgetItem* item4 = new QListWidgetItem("b1");
    item4->setIcon(QIcon("notebook.png"));
    lw2->addItem(item4);
    QListWidgetItem* item5 = new QListWidgetItem("b2");
    item5->setIcon(QIcon("notebook.png"));
    lw2->addItem(item5);
    QListWidgetItem* item6 = new QListWidgetItem("b3");
    item6->setIcon(QIcon("notebook.png"));
    lw2->addItem(item6);
    //lw2->addItem("a2");
    //lw2->addItem("b2");
    //lw2->addItem("c2");
    int n2 = lw2->count() - 1;
    lw2->setCurrentRow(n2);
    add2 = new QPushButton("Add", this);
    rename2 = new QPushButton("Rename", this);
    remove2 = new QPushButton("Remove", this);
    removeAll2 = new QPushButton("Remove All", this);
    QVBoxLayout *vbox2 = new QVBoxLayout();
    QGridLayout *grid2 = new QGridLayout();
    grid2->addWidget(add2, 0, 0);
    grid2->addWidget(rename2, 0, 1);
    grid2->addWidget(remove2, 1, 0);
    grid2->addWidget(removeAll2, 1, 1);
    vbox2->addWidget(lw2);
    vbox2->addLayout(grid2);
    selectionMode2 = new QPushButton("Enable multyselection", this);
    vbox2->addWidget(selectionMode2);
    sort2 = new QPushButton("Sort", this);
    vbox2->addWidget(sort2);

    lw2->setDropIndicatorShown(true);
    lw2->setDragEnabled(true);
    lw2->setDragDropOverwriteMode(true);
    lw2->setDragDropMode(QAbstractItemView::DragDrop);
    lw2->setDefaultDropAction(Qt::TargetMoveAction);

    QVBoxLayout *vbox = new QVBoxLayout();
    moveToRight = new QPushButton(">", this);
    moveToLeft = new QPushButton("<", this);
    iconMode = new QPushButton("icons", this);
    vbox->addWidget(moveToRight, Qt::AlignTop, Qt::AlignHCenter); ///
    vbox->addWidget(iconMode);
    vbox->addWidget(moveToLeft, Qt::AlignBottom, Qt::AlignHCenter);

    hbox->addLayout(vbox1);
    hbox->addLayout(vbox);
    hbox->addLayout(vbox2);

    connect(add1, &QPushButton::clicked, this, &ListWidget::addItem);
    connect(add2, &QPushButton::clicked, this, &ListWidget::addItem);
    connect(rename1, &QPushButton::clicked, this, &ListWidget::renameItems);
    connect(rename2, &QPushButton::clicked, this, &ListWidget::renameItems);
    connect(remove1, &QPushButton::clicked, this, &ListWidget::removeItems);
    connect(remove2, &QPushButton::clicked, this, &ListWidget::removeItems);
    connect(removeAll1, &QPushButton::clicked, this, &ListWidget::clearItems);
    connect(removeAll2, &QPushButton::clicked, this, &ListWidget::clearItems);
    connect(moveToRight, &QPushButton::clicked, this, &ListWidget::movingToRight);
    connect(moveToLeft, &QPushButton::clicked, this, &ListWidget::movingToLeft);
    connect(iconMode, &QPushButton::clicked, this, &ListWidget::changeIconMode);
    connect(sort1, &QPushButton::clicked, this, &ListWidget::sortListWidget1);
    connect(sort2, &QPushButton::clicked, this, &ListWidget::sortListWidget2);
    connect(selectionMode1, &QPushButton::clicked, this, &ListWidget::changeSelectionMode);
    connect(selectionMode2, &QPushButton::clicked, this, &ListWidget::changeSelectionMode);
    connect(lw1, &QListWidget::itemSelectionChanged, this, &ListWidget::disableMovingToRight);
    connect(lw2, &QListWidget::itemSelectionChanged, this, &ListWidget::disableMovingToLeft);

    setLayout(hbox);

    setStyleSheet("background-color: #d9f2ff; font-family: Comic Sans MS");
    moveToRight->setStyleSheet("background-color: #dcb5ff; font-family: Comic Sans MS; font-size: 15pt");
    moveToLeft->setStyleSheet("background-color: #dcb5ff; font-family: Comic Sans MS; font-size: 15pt");
    iconMode->setStyleSheet("background-color: #a5bdfd; font-family: Comic Sans MS; font-size: 15pt");
    add1->setStyleSheet("background-color: #a5bdfd; font-family: Comic Sans MS; font-size: 15pt");
    rename1->setStyleSheet("background-color: #a5bdfd; font-family: Comic Sans MS; font-size: 15pt");
    remove1->setStyleSheet("background-color: #a5bdfd; font-family: Comic Sans MS; font-size: 15pt");
    removeAll1->setStyleSheet("background-color: #a5bdfd; font-family: Comic Sans MS; font-size: 15pt");
    add2->setStyleSheet("background-color: #a5bdfd; font-family: Comic Sans MS; font-size: 15pt");
    rename2->setStyleSheet("background-color: #a5bdfd; font-family: Comic Sans MS; font-size: 15pt");
    remove2->setStyleSheet("background-color: #a5bdfd; font-family: Comic Sans MS; font-size: 15pt"); //
    removeAll2->setStyleSheet("background-color: #a5bdfd; font-family: Comic Sans MS; font-size: 15pt");
    sort1->setStyleSheet("background-color: #dcb5ff; font-family: Comic Sans MS; font-size: 15pt");
    sort2->setStyleSheet("background-color: #dcb5ff; font-family: Comic Sans MS; font-size: 15pt");
    selectionMode1->setStyleSheet("background-color: #dcb5ff; font-family: Comic Sans MS; font-size: 15pt");
    selectionMode2->setStyleSheet("background-color: #dcb5ff; font-family: Comic Sans MS; font-size: 15pt");
    moveToRight->setMinimumSize(10, 10);
    moveToRight->setMaximumSize(50, 50);
    moveToLeft->setMinimumSize(10, 10);
    moveToLeft->setMaximumSize(50, 50);
    //iconMode->setMaximumWidth(40);
    //add1->setFrameStyle(QFrame::Box | QFrame::Sunken);

}

ListWidget::~ListWidget()
{

}

void ListWidget::addItemPtr(QListWidget* lw)
{
    QString c_text = QInputDialog::getText(this, "Item", "Enter new item");
    QString s_text = c_text.simplified();
    if (!s_text.isEmpty())
    {
        QListWidgetItem* item = new QListWidgetItem(s_text);
        item->setIcon(QIcon("notebook.png"));
        lw->addItem(item);
        int r = lw->count() - 1;
        lw->setCurrentRow(r);
    }
}

void ListWidget::addItem()
{
    if (sender() == add1)
    {
        addItemPtr(lw1);
    }
    else
    {
        addItemPtr(lw2);
    }
}

void ListWidget::renameItemsPtr(QListWidget* lw)
{
    QList <QListWidgetItem*> items = lw->selectedItems();
    if (items.size() > 0)
    {
        int r;
        foreach(QListWidgetItem* it, items)
        {
            r = lw->row(it);
            QString c_text = it->text();
            QString r_text = QInputDialog::getText(this,
                "Item", "Enter new item",
                QLineEdit::Normal, c_text);
            QString s_text = r_text.simplified();
            if (!s_text.isEmpty())
            {
                QListWidgetItem *item = lw->takeItem(r);
                delete item;
                QListWidgetItem* newItem = new QListWidgetItem;
                newItem->setText(s_text);
                newItem->setIcon(QIcon("notebook.png"));
                //item->setText(s_text);
                lw->insertItem(r, newItem);
            }
        }
        lw->setCurrentRow(r);
    }
}

void ListWidget::renameItems()
{
    if (sender() == rename1)
    {
        renameItemsPtr(lw1);
    }
    else
    {
        renameItemsPtr(lw2);
    }
}

void ListWidget::removeItemsPtr(QListWidget* lw)
{
    QList <QListWidgetItem*> items = lw->selectedItems();
    if (items.size() > 0)
    {
        foreach(QListWidgetItem* it, items)
        {
            delete it;
        }
    }
}

void ListWidget::removeItems()
{
    if (sender() == remove1)
    {
        removeItemsPtr(lw1);
    }
    else
    {
        removeItemsPtr(lw2);
    }

    /*if (sender() == remove1)
    {
        int r = lw1->currentRow();
        if (r != -1) {
        QListWidgetItem *item = lw1->takeItem(r);
        delete item;
        }
    }
    else
    {
        int r = lw2->currentRow();
        if (r != -1) {
        QListWidgetItem *item = lw2->takeItem(r);
        delete item;
        }
    }*/
}

void ListWidget::clearItems()
{
    if (sender() == removeAll1)
    {
        if (lw1->count() != 0) {
        lw1->clear();
        }
    }
    else
    {
        if (lw2->count() != 0) {
            lw2->clear();
        }
    }
}

void ListWidget::movingToRight()
{
    if (lw1->count() != 0)
    {
        QList <QListWidgetItem*> items = lw1->selectedItems();
        if (items.size() > 0)
        {
            foreach(QListWidgetItem* it, items)
            {
                QListWidgetItem *curitem = it;
                QListWidgetItem *movedItem = new QListWidgetItem;
                *movedItem = *curitem;
                delete curitem;
                lw2->addItem(movedItem);
            }
        }
    }
}

void ListWidget::movingToLeft() //разрешить для опции выбора одного отменить все выделения
{
    if (lw2->count() != 0)
    {
        QList <QListWidgetItem*> items = lw2->selectedItems();
        if (items.size() > 0)
        {
            foreach(QListWidgetItem* it, items)
            {
                QListWidgetItem *curitem = it;
                QListWidgetItem *movedItem = new QListWidgetItem;
                *movedItem = *curitem;
                delete curitem;
                lw1->addItem(movedItem);
            }
        }
    }
}

void ListWidget::changeIconMode() //удваивается при перетаскивании, надо ли так???
{
    if (lw1->viewMode() == QListWidget::ListMode)
    {
        lw1->setViewMode(QListWidget::IconMode);
        lw2->setViewMode(QListWidget::IconMode);
        iconMode->setText("text");
    }
    else
    {
        lw1->setViewMode(QListWidget::ListMode);
        lw2->setViewMode(QListWidget::ListMode);
        iconMode->setText("icons");
    }

    /*QList <QListWidgetItem*> items = lw1->selectedItems();
    if (items.size() > 0)
    {
        foreach(QListWidgetItem* it, items)
        {
            it->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled );
        }
    }*/

    /*for (int i = 0; i < lw1->count()-1; ++i)
    {
        lw1->takeItem(i)->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled );
        lw2->takeItem(i)->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled );
    }*/
}

void ListWidget::sortListWidget1()
{
    lw1->sortItems(Qt::AscendingOrder);
}

void ListWidget::sortListWidget2()
{
    lw2->sortItems(Qt::DescendingOrder);
}

void ListWidget::changeSelectionMode()
{
    if (sender() == selectionMode1)
    {
        if (lw1->selectionMode() == QAbstractItemView::SingleSelection)
        {
            lw1->setSelectionMode(QAbstractItemView::MultiSelection);
            selectionMode1->setText("Disable multiselection");
        }
        else
        {
            lw1->setSelectionMode(QAbstractItemView::SingleSelection);
            selectionMode1->setText("Enable multiselection");
            QList <QListWidgetItem*> items1 = lw1->selectedItems();
            if (items1.size() > 0)
            {
                QListWidgetItem* lastItem = items1.last();
                lw1->setCurrentItem(lastItem);
            }
        }
    }
    else if(sender() == selectionMode2)
    {
        if (lw2->selectionMode() == QAbstractItemView::SingleSelection)
        {
            lw2->setSelectionMode(QAbstractItemView::MultiSelection);
            selectionMode2->setText("Disable multiselection");
        }
        else
        {
            lw2->setSelectionMode(QAbstractItemView::SingleSelection);
            selectionMode2->setText("Enable multiselection");
            QList <QListWidgetItem*> items2 = lw2->selectedItems();
            if (items2.size() > 0)
            {
                QListWidgetItem* lastItem = items2.last();
                lw2->setCurrentItem(lastItem);
            }
        }
    }
}

void ListWidget::disableMovingToRight()
{
    QList <QListWidgetItem*> selecteditems = lw1->selectedItems();
    if (selecteditems.size() > 0)
    {
        moveToRight->setEnabled(true);
    }
    else
    {
        moveToRight->setEnabled(false);
    }
}

void ListWidget::disableMovingToLeft()
{
    QList <QListWidgetItem*> selecteditems = lw2->selectedItems();
    if (selecteditems.size() > 0)
    {
        moveToLeft->setEnabled(true);
    }
    else
    {
        moveToLeft->setEnabled(false);
    }
}
