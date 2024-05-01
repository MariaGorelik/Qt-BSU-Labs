#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include<QWidget>
#include<QString>
#include<QPainter>
#include<QPointF>
#include<QtMath>
#include<QFileDialog>
#include<QColorDialog>
#include<QFile>
#include<QTextStream>
#include <QVBoxLayout>
#include <QDialog>
#include <QRadioButton>
#include <QPushButton>
#include <QString>
#include <QFont>
#include "Diagram.h"

class CentralWidget: public QWidget
{
    Q_OBJECT
private:
    QString fileName;
    Diagram* diag;
    QDialog* dialog;
    QPushButton* buttonOk;
    QRadioButton* button1;
    QRadioButton* button2;
    QRadioButton* button3;
    bool isSaved;
public:
    CentralWidget(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    void setIsSaved(bool);
    bool getIsSaved();
    QString getFileName();
    int getPenWidth();
public slots:
    void drawPicture();
    void slotOpen();
    void slotSave();
    void slotSaveAs();
    void slotClose();
    void slotChoosePenColor();
    void slotChooseBrushColor();
    void slotChangePenWidth();
    void slotButtonOkClicked();
signals:
    void changeDiagramPicture();
    void changeStatusBarInfo(QString, QString);
    void enableOpenOption();
    void enableCloseOption();
    void enableSaveOption();
};

#endif // CENTRALWIDGET_H
