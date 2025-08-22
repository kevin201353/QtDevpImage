#include "histogram.h"
#include <qlabel.h>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPolygonF>
#include "mainwindow.h"

HistoGram::HistoGram(QWidget *parent) : QWidget(parent)
{
    //this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    /*
    this->setStyleSheet("background-color:rgb(255,150,250)");
    //QLabel *label = new QLabel("This is my custom widget!", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    button1 = new QPushButton("Button 1", this);
    button2 = new QPushButton("Button 2", this);
    // 设置按钮固定大小（宽度，高度）
    button1->setFixedSize(150, 50);  // 宽度150px，高度50px
    button2->setFixedSize(150, 50);
    // 设置按钮间距（像素）
    layout->setSpacing(30);  // 按钮之间的垂直间隔
    // 设置布局边距（左，上，右，下）
    layout->setContentsMargins(5, 20, 20, 20);  // 布局与容器的边距
    layout->setAlignment(Qt::AlignLeft);  // 居中对齐
    layout->addWidget(button1);
    layout->addWidget(button2);
    setLayout(layout);
    connect(button1, &QPushButton::clicked, this, &OnCheckWindow);
    */
}

HistoGram::~HistoGram()
{
}

void HistoGram::OnCheckWindow()
{
    emit hotKeyPressed();
}

void HistoGram::paintEvent(QPaintEvent *event)
{
    DrawX1();
}

void HistoGram::mouseMoveEvent(QMouseEvent *event)
{
    int entered = -1;
    int count = (int)bins.size();
    for (int i = 0; i < count; i++)
    {
        if (rects[i].contains(event->pos()))
        {
            entered = i;
            break;
        }
    }
    if (entered != hitBin)
    {
        setToolTip((entered >= 0) ? QString(u8"值：%1").arg(bins[entered]) : QString());
        hitBin = entered;
        update();
    }
}


void HistoGram::enterEvent(QEvent *event)
{

}

void HistoGram::leaveEvent(QEvent *event)
{

}

int HistoGram::calcNearInteger(int value, bool upperOrLower)
{
    int i = 10;
    while (value / i != 0)
    {
        i *= 10;
    }
    i = qMax(i / 10, 10);
    int x = value / i;
    if (upperOrLower)
    {
        return i * (x + 1);
    }
    return i * x;
}

void HistoGram::DrawX1()
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.drawRect(rect());

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::black);
    const QMargins margin(10, 20, 20, 20);

    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(255,0,0));
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);


    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::Dense6Pattern);
    painter.setBrush(brush);
    painter.drawRect(margin.left(),margin.top(),100,50);
    /*
    painter.setPen(pen);
    painter.drawLine(50,50,150,50);
    painter.drawLine(50,50,50,150);

    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::Dense6Pattern);
    painter.setBrush(brush);
    painter.drawRect(150,150,100,50);

    painter.drawEllipse(250,250,40,40);
    */

    painter.setPen(pen);
    QPointF startPoint(200,200);
    QPointF endPoint(300,200);
    //绘制直线
    painter.drawLine(startPoint,endPoint);
    drawArrow(painter,startPoint,endPoint);
    painter.end();
}

void HistoGram::drawArrow(QPainter &painter, const QPointF &start, const QPointF &end)
{
    //箭头大小
    double arrowSize = 15;
    //计算直线的角度
    double angle = std::atan2(end.y()-start.y(), end.x()-start.x());
    //计算箭头两个点的位置
    QPointF  arrowP1 = end - QPointF(std::cos(angle-M_PI/6)*arrowSize,std::sin(angle - M_PI / 6) * arrowSize);
    QPointF  arrowP2 = end - QPointF(std::cos(angle+M_PI/6)*arrowSize,std::sin(angle + M_PI / 6) * arrowSize);
    //保存当前画笔
  //  QPen savePen = painter.pen();
    //设置箭头填充颜色
  //  QBrush brush(savePen.color(), Qt::SolidPattern);
  //  painter.setBrush(brush);
    //绘制箭头三角形
    QPolygonF  arrowHead;
    arrowHead<<end<<arrowP1<<arrowP2;
    painter.drawPolygon(arrowHead);
    //恢复画笔
    painter.setBrush(Qt::NoBrush);
}
