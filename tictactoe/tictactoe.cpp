//e7d2fc - фиолетовый x
//f6f7c1 - желтый o
#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QtWidgets>
#include <time.h>
#include <assert.h>


Tictactoe::Tictactoe(QWidget *parent, int n)
    : QWidget(parent), sizeOfField(n), player(1), game(1), counter(0)
    , ui(new Ui::Tictactoe)
{
    ui->setupUi(this);
    if (n < 3 || n > 7)
        assert(false);
    vbox = new QVBoxLayout(this);
    hbox1 = new QHBoxLayout();
    hbox2 = new QHBoxLayout();
    hboxgrid = new QHBoxLayout();
    grid = new QGridLayout();
    grid->setMargin(15);
    grid->setSpacing(0);
    grid->setHorizontalSpacing(0);
    grid->setVerticalSpacing(0);
    playerLabel = new QLabel("Player 1", this);
    playerLabel->setFont(QFont("Bodoni MT Black", 20));
    playerLabel->setStyleSheet("color: #b049c9");
    //hbox1->setMargin(20);
    hbox1->addWidget(playerLabel, 1, Qt::AlignCenter);
    vbox->addLayout(hbox1);
    buttons.resize(sizeOfField);
    QFont lBlackFont("Arial Black", 25);
    hboxgrid->addLayout(grid, Qt::AlignCenter);
    vbox->addLayout(hboxgrid, 1);
    for (int i = 0; i < sizeOfField; i++)
    {

        for (int j = 0; j < sizeOfField; j++)
        {
            buttons[i].push_back(new QPushButton("", this));
            buttons[i][j]->setFont(lBlackFont);
            buttons[i][j]->setAutoFillBackground(true);
            buttons[i][j]->setFixedSize(110, 110);
            buttons[i][j]->setContentsMargins(0, 0, 0, 0);
            grid->addWidget(buttons[i][j], i, j);
        }
    }
    resultTitle = new QLabel("Result:", this);
    resultTitle->setVisible(false);
    resultTitle->setFont(QFont("Bodoni MT Black", 18));
    resultTitle->setStyleSheet("color: #b049c9");
    result = new QLabel("", this);
    result->setFont(QFont("Arial", 12));
    clearButton = new QPushButton("clear", this);
    clearButton->setMinimumWidth(70);
    clearButton->setMinimumHeight(50);
    clearButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QFont clearButtonFont("Arial", 10);
    clearButton->setFont(clearButtonFont);
    vbox->addWidget(resultTitle, 1, Qt::AlignCenter);
    vbox->addWidget(result, 1, Qt::AlignCenter);
    clearButton->setAutoFillBackground(true);
    clearButton->setStyleSheet("background-color: #f7e1be");
    clearButton->setFont(QFont("Bodoni MT", 14));
    hbox2->setMargin(20);
    hbox2->addWidget(clearButton, 1, Qt::AlignCenter);
    vbox->addLayout(hbox2);
    setLayout(vbox);
    for (int i = 0; i < sizeOfField; i++)
    {
        for (int j = 0; j < sizeOfField; j++)
        {
            int name = i*sizeOfField+j;
            buttons[i][j]->setObjectName(QString::number(name));
            connect(buttons[i][j], &QPushButton::clicked, this, &Tictactoe::turn);
        }
    }
    connect(clearButton, &QPushButton::clicked, this, &Tictactoe::clear);
    QPalette backgroundStyle;
    QColor backgroundColor (245, 227, 250);
    backgroundStyle.setColor(this->backgroundRole(), backgroundColor);
    setPalette(backgroundStyle);
    setAutoFillBackground(true);
}

Tictactoe::~Tictactoe()
{
    delete ui;
    delete vbox;
    delete hbox1;
    delete hbox2;
    delete hboxgrid;
    delete grid;
    delete playerLabel;
    for (int i = 0; i < sizeOfField; i++)
    {

        for (int j = 0; j < sizeOfField; j++)
        {
            delete buttons[i][j];
        }
    }
    delete resultTitle;
    delete result;
    delete clearButton;
}

void Tictactoe::turn()
{
    counter++;
    int i, j;
    int val = sender()->objectName().toInt();
    i = val / sizeOfField;
    j = val % sizeOfField;
    if (player)
    {
        buttons[i][j]->setText("X");
        buttons[i][j]->setStyleSheet("background-color: #e7d2fc");
    }
    else
    {
        buttons[i][j]->setText("O");
        buttons[i][j]->setStyleSheet("background-color: #f6f7c1");
    }
    buttons[i][j]->setEnabled(false);
    bool endOfGame = checkEndOfGame(i, j);
    if (!endOfGame)
    {
        computerTurn();
    }
}

void Tictactoe::clear()
{
    for (int i = 0; i < sizeOfField; i++)
    {
        for (int j = 0; j < sizeOfField; j++)
        {
            buttons[i][j]->setText("");
            buttons[i][j]->setEnabled(true);
            buttons[i][j]->setStyleSheet("background-color: Qt::gray");
        }
    }
    player = !player;
    if (player)
    {
        playerLabel->setText("Player 1");
    }
    else
    {
        playerLabel->setText("Player 2");
        computerTurn();
    }
    resultTitle->setVisible(false);
    result->setText("");
    counter = 0;
}

void Tictactoe::computerTurn()
{
    srand(time(NULL));
    int I = -1, J = -1;
    bool flag = 0;
    int i = rand() % sizeOfField;
    int j = rand() % sizeOfField;
    if (buttons[i][j]->isEnabled())
    {
        counter++;
        I = i;
        J = j;
        if (player)
        {
            buttons[i][j]->setText("O");
            buttons[i][j]->setStyleSheet("background-color: #f6f7c1");
        }
        else
        {
            buttons[i][j]->setText("X");
            buttons[i][j]->setStyleSheet("background-color: #e7d2fc");
        }
        buttons[i][j]->setEnabled(false);
    }
    else
    {
    for (int i = 0; i < sizeOfField; i++)
    {
        for (int j = 0; j < sizeOfField; j++)
        {
            if (buttons[i][j]->isEnabled())
            {
                counter++;
                I = i;
                J = j;
                if (player)
                {
                    buttons[i][j]->setText("O");
                    buttons[i][j]->setStyleSheet("background-color: #f6f7c1");
                }
                else
                {
                    buttons[i][j]->setText("X");
                    buttons[i][j]->setStyleSheet("background-color: #e7d2fc");
                }
                buttons[i][j]->setEnabled(false);
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    }
    checkEndOfGame(I, J);
}

bool Tictactoe::checkEndOfGame(int I, int J)
{
    bool endOfGame = 1;
    if ((I == -1 && J == -1) || counter == sizeOfField*sizeOfField)
    {
        endOfGame = 1;
    }
    else
    {
    for (int i = 0; i < sizeOfField; i++)
    {
        if (buttons[i][J]->text() != buttons[I][J]->text())
        {
            endOfGame = 0;
            break;
        }
    }
    if (!endOfGame)
    {
        endOfGame = 1;
        for (int j = 0; j < sizeOfField; j++)
        {
            if (buttons[I][j]->text() != buttons[I][J]->text())
            {
                endOfGame = 0;
                break;
            }
        }
    }
    if (!endOfGame && I == J)
    {
        endOfGame = 1;
        for (int i = 0, j = 0; i < sizeOfField; i++, j++)
        {
            if (buttons[i][j]->text() != buttons[I][J]->text())
            {
                endOfGame = 0;
                break;
            }
        }
    }
    if (!endOfGame && I + J == sizeOfField - 1)
    {
        endOfGame = 1;
        for (int i = 0, j = sizeOfField-1; i < sizeOfField; i++, j--)
        {
            if (buttons[i][j]->text() != buttons[I][J]->text())
            {
                endOfGame = 0;
                break;
            }
        }
    }
    }
    if (endOfGame)
    {
        for (int i = 0; i < sizeOfField; i++)
        {
            for (int j = 0; j < sizeOfField; j++)
            {
                buttons[i][j]->setEnabled(false);
            }
        }
        resultTitle->setVisible(true);
        if ((I == -1 and J == -1) || (counter == sizeOfField*sizeOfField && player))
        {
            result->setText("No winner in this game");
        }
        else if ((player && buttons[I][J]->text() == "X") || (!player && buttons[I][J]->text() == "O"))
        {
            result->setText("Congratulations! You are the winner!");
        }
        else
        {
            result->setText("Unfortunately, you lost. Good luck next time!");
        }
    }
    return endOfGame;
}



