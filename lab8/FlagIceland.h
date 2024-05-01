#ifndef FLAGICELAND_H
#define FLAGICELAND_H

#include <QWidget>

class FlagIceland: public QWidget

{
public:
    FlagIceland(QWidget *parent = nullptr);
    ~FlagIceland();
    void paintEvent(QPaintEvent*) override;
private:
    int w; //proportion
    int h;
};

#endif // FLAGICELAND_H
