#ifndef FLAGUAE_H
#define FLAGUAE_H

#include <QWidget>

class FlagUAE: public QWidget

{
public:
    FlagUAE(QWidget *parent = nullptr);
    ~FlagUAE();
    void paintEvent(QPaintEvent*) override;
private:
    int prop; //proportion
};

#endif // FLAGUAE_H
