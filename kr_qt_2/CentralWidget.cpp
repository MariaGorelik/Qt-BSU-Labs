#include "CentralWidget.h"

CentralWidget::CentralWidget(QWidget* parent): QWidget(parent), fileName("untitled"), isSaved(false)
{
    diag = new Diagram();
    dialog = new QDialog();
    dialog->setWindowTitle("Select pen width");
    dialog->resize(400, 400);
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
    QPen pen(diag->penColor, diag->penWidth, Qt::DashLine);
    QBrush brush(diag->brushColor, Qt::SolidPattern);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(brush);
    painter.setPen(pen);

    //круговая

    /*int x_center = this->width() / 2;
    int y_center = this->height() / 2;
    int x_top, y_top, r;
    if(this->height() < this->width())
    {
        y_top = this->height() / 4;
        r = y_top;
        x_top = (this->width() - 2*r) / 2;
    }
    else
    {
        x_top = this->width() / 4;
        r = x_top;
        y_top = (this->height() - 2*r) / 2;
    }
    painter.drawEllipse(QRect(x_top, y_top, 2*r, 2*r));
    if(diag->number > 1)
    {
        int total = 0;
        for(int i = 0; i < diag->number; ++i)
        {
            total += diag->data[i];
        }
        painter.drawLine(QPointF(x_center, y_center), QPointF(x_center, y_center-r));
        qreal angle = 0.0;
        for(int i = 0; i < diag->number - 1; ++i)
        {
            qreal angleAdd = ::qDegreesToRadians(360.0 * diag->data[i] / total);
            angle += angleAdd;
            qreal x = x_center + r * sin(angle);
            qreal y = y_center - r * cos(angle);
            painter.drawLine(QPointF(x_center, y_center), QPointF(x, y));
        }
    }*/

    //гистограмма

    /*int maxValue = diag->data[0];
    for(int i = 1; i < diag->number; ++i)
    {
        if(diag->data[i] > maxValue)
        {
            maxValue = diag->data[i];
        }
    }
    int y_bottom = 5 * height() / 6;
    int padding;
    if(height() < width())
        padding = height() / 6;
    else
        padding = width() / 6;
    int w = (3*width() - 6*padding) / (4*diag->number - 1); //ширина столбика
    int x_rect = padding;
    int y_rect;
    int h; //высота столбика
    for(int i = 0; i < diag->number; ++i)
    {
        h = 2 * height() * diag->data[i] /(3 * maxValue);
        y_rect = y_bottom - h;
        painter.drawRect(QRect(x_rect, y_rect, w, h));
        x_rect += 4 * w / 3;
    }*/

    //линейчатая

    /*int maxValue = diag->data[0];
    for(int i = 1; i < diag->number; ++i)
    {
        if(diag->data[i] > maxValue)
        {
            maxValue = diag->data[i];
        }
    }
    int x_rect = width() / 6;
    int padding;
    if(height() < width())
        padding = height() / 6;
    else
        padding = width() / 6;
    int h = (3*height() - 6*padding) / (4*diag->number - 1); //ширина столбика
    int y_rect = padding;
    int w; //высота столбика
    for(int i = 0; i < diag->number; ++i)
    {
        w = 2 * width() * diag->data[i] /(3 * maxValue);
        painter.drawRect(QRect(x_rect, y_rect, w, h));
        y_rect += 4 * h / 3;
    }*/

    //кольцевая

    /*int x_center = this->width() / 2;
    int y_center = this->height() / 2;
    int x_top, y_top, r;
    if(this->height() < this->width())
    {
        y_top = this->height() / 4;
        r = y_top;
        x_top = (this->width() - 2*r) / 2;
    }
    else
    {
        x_top = this->width() / 4;
        r = x_top;
        y_top = (this->height() - 2*r) / 2;
    }
    painter.drawEllipse(QRect(x_top, y_top, 2*r, 2*r));
    if(diag->number > 1)
    {
        int total = 0;
        for(int i = 0; i < diag->number; ++i)
        {
            total += diag->data[i];
        }
        painter.drawLine(QPointF(x_center, y_center), QPointF(x_center, y_center-r));
        qreal angle = 0.0;
        for(int i = 0; i < diag->number - 1; ++i)
        {
            qreal angleAdd = ::qDegreesToRadians(360.0 * diag->data[i] / total);
            angle += angleAdd;
            qreal x = x_center + r * sin(angle);
            qreal y = y_center - r * cos(angle);
            painter.drawLine(QPointF(x_center, y_center), QPointF(x, y));
        }
    }
    brush.setColor(palette().color(QWidget::backgroundRole()));
    painter.setBrush(brush);
    painter.drawEllipse(QRect(x_top + r/2, y_top + r/2, r, r));*/

    //круговая разрезанная

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
            qreal angleAdd = 360.0 * diag->data[i] / total;
            qreal halfAngleAdd = angleAdd / 2;
            qreal new_x_center = x_center + 0.25*r * cos(::qDegreesToRadians(angle + halfAngleAdd));
            qreal new_y_center = y_center - 0.25*r * sin(::qDegreesToRadians(angle + halfAngleAdd));
            painter.drawPie(QRect(new_x_center - r, new_y_center - r, 2*r, 2*r), 16*angle, 16*angleAdd);
            angle += angleAdd;
            //qreal x = x_center + r * cos(angle);
            //qreal y = y_center - r * sin(angle);
            //painter.drawLine(QPointF(x_center, y_center), QPointF(x, y));
        }
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

    /*QString str = QFileDialog::getSaveFileName(
        0, fileName);
    if (!str.isEmpty())
    {
        fileName = str;
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
    }*/


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
