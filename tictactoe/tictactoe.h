
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class Tictactoe; }
QT_END_NAMESPACE

class Tictactoe : public QWidget

{
    Q_OBJECT

public:
    Tictactoe(QWidget *parent = nullptr, int n = 3);
    ~Tictactoe();

private:
    Ui::Tictactoe *ui;
    int sizeOfField;
    QLabel* playerLabel;
    QLabel* resultTitle;
    QLabel* result;
    QPushButton* clearButton;
    QVector<QVector<QPushButton*>> buttons;
    bool player;
    int game;
    void computerTurn();
    bool checkEndOfGame(int I, int J);
    int counter;
    QVBoxLayout* vbox;
    QHBoxLayout* hbox1;
    QHBoxLayout* hbox2;
    QHBoxLayout* hboxgrid;
    QGridLayout *grid;
private slots:
    void turn();
    void clear();
};

#endif // TICTACTOE_H
