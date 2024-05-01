#include "CentralWidget.h"

CentralWidget::CentralWidget(QWidget* parent): QWidget(parent), fileName("untitled"), isSaved(false)
{
    diag = new Diagram();
    dialog = new QDialog();
    dialog->setWindowTitle("Pen width");
    dialog->resize(230, 200);
    QVBoxLayout* layout = new QVBoxLayout;
    button1 = new QRadioButton("1 px", dialog);
    button2 = new QRadioButton("2 px", dialog);
    button3 = new QRadioButton("5 px", dialog);
    buttonOk = new QPushButton("Ok", dialog);
    button1->setChecked(true);
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(buttonOk);
    dialog->setLayout(layout);
    connect(this, SIGNAL(changeDiagramPicture()), this, SLOT(drawPicture()));
    connect(buttonOk, SIGNAL(clicked()), this, SLOT(slotButtonOkClicked()));
}

void CentralWidget::paintEvent(QPaintEvent* pe)
{
    emit changeDiagramPicture();
}

void CentralWidget::drawPicture()
{
    if(diag->data.size() == 0)
        return;

    QPainter painter(this);
    QPen pen(diag->penColor, diag->penWidth, Qt::SolidLine);
    QBrush brush(diag->brushColor, Qt::SolidPattern);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(brush);
    painter.setPen(pen);

    //кольцевая разрезанная

    int x_center = this->width() / 2;
    int y_center = this->height() / 2;
    int r;
    if(this->height() < this->width())
    {
        r = this->height() / 4;
    }
    else
    {
        r = this->width() / 4;
    }
    if(diag->number == 1)
        painter.drawEllipse(QRect(x_center-r, y_center-r, 2*r, 2*r));
    else
    {
        int total = 0;
        for(int i = 0; i < diag->number; ++i)
        {
            total += diag->data[i];
        }
        qreal angle = 0.0;
        for(int i = 0; i < diag->number; ++i)
        {
            brush.setColor(diag->brushColor);
            painter.setBrush(brush);
            qreal angleAdd = 360.0 * diag->data[i] / total;
            qreal halfAngleAdd = angleAdd / 2;
            qreal new_x_center = x_center + 0.25*r * cos(::qDegreesToRadians(angle + halfAngleAdd));
            qreal new_y_center = y_center - 0.25*r * sin(::qDegreesToRadians(angle + halfAngleAdd));
            painter.drawPie(QRect(new_x_center - r, new_y_center - r, 2*r, 2*r), 16*angle, 16*angleAdd);

            brush.setColor(palette().color(QWidget::backgroundRole()));
            painter.setBrush(brush);
            pen.setColor(palette().color(QWidget::backgroundRole()));
            painter.setPen(pen);
            painter.drawPie(QRect(new_x_center - 0.25*r, new_y_center - 0.25*r, 0.5*r, 0.5*r), 0, 360*16);

            angle += angleAdd;

            pen.setColor(diag->penColor);
            painter.setPen(pen);
            painter.setFont(QFont("Arial", 12));
            qreal x_text = new_x_center+1.3*r*cos(::qDegreesToRadians(angle - angleAdd/2));
            qreal y_text = new_y_center-1.3*r*sin(::qDegreesToRadians(angle - angleAdd/2));
            painter.drawText(QRect(x_text, y_text, 20, 20), Qt::AlignCenter, QString::number(diag->data[i]));

        }
        //brush.setColor(palette().color(QWidget::backgroundRole()));
        //painter.setBrush(brush);
        //painter.drawEllipse(QRect(x_center - r/2, y_center - r/2, r, r));
    }
}


void CentralWidget::slotOpen()
{
    QString str = QFileDialog::getOpenFileName(0, fileName);
    if (str.isEmpty())
        return;
    QFile file(str);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        fileName = str;
        stream >> diag->number;
        diag->data.clear();
        for(int i = 0; i < diag->number; ++i)
        {
            int n;
            stream >> n;
            diag->data.push_back(n);
        }
        QString str;
        stream >> str;
        diag->penColor.setNamedColor(str);
        int pw;
        stream >> pw;
        diag->penWidth = pw;
        stream >> str;
        diag->brushColor.setNamedColor(str);
        file.close();
        emit changeDiagramPicture();
        emit changeStatusBarInfo(fileName, QString::number(diag->penWidth));
    }
}

void CentralWidget::slotSave()
{
    if (fileName.isEmpty())
    {
        slotSaveAs();
        return;
    }
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream << diag->number << "\n";
        for(int i = 0; i < diag->number; ++i)
        {
            stream << diag->data[i] << "\n";
        }
        stream << diag->penColor.name() << "\n";
        stream << diag->penWidth << "\n";
        stream << diag->brushColor.name();
        file.close();
        isSaved = true;
        emit changeDiagramPicture();
    }
}

void CentralWidget::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(
        0, fileName);
    if (!str.isEmpty())
    {
        fileName = str;
        slotSave();
        emit enableOpenOption();
        emit enableCloseOption();
        emit enableSaveOption();
    }
}

void CentralWidget::slotClose()
{
    diag->data.clear();
    this->update();
    isSaved = false;
    fileName = "untitled";
    emit changeStatusBarInfo(fileName, QString::number(diag->penWidth));
}

void CentralWidget::slotChoosePenColor()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid())
    {
        this->diag->penColor = color;
        isSaved = false;
        emit changeDiagramPicture();
    }
}

void CentralWidget::slotChooseBrushColor()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid())
    {
        this->diag->brushColor = color;
        isSaved = false;
        emit changeDiagramPicture();
    }
}

void CentralWidget::slotChangePenWidth()
{
    dialog->exec();
}

void CentralWidget::slotButtonOkClicked()
{
    if(button1->isChecked())
    {
        diag->penWidth = 1;
    }
    else if(button2->isChecked())
    {
        diag->penWidth = 2;
    }
    else
    {
        diag->penWidth = 5;
    }
    dialog->close();
    isSaved = false;
    emit changeDiagramPicture();
    emit changeStatusBarInfo(fileName, QString::number(diag->penWidth));
}

void CentralWidget::setIsSaved(bool s)
{
    isSaved = s;
}

bool CentralWidget::getIsSaved()
{
    return isSaved;
}

QString CentralWidget::getFileName()
{
    return fileName;
}

int CentralWidget::getPenWidth()
{
    return diag->penWidth;
}

