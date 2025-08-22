#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QWidget>
#include <QPushButton>
namespace Ui {
   class HistoGram;
}
class HistoGram : public QWidget
{
    Q_OBJECT
public:
   explicit HistoGram(QWidget *parent = nullptr);
    ~HistoGram();
signals:
    void hotKeyPressed();
private slots:
    void OnCheckWindow();
private:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    int  calcNearInteger(int value, bool upperOrLower);
    void DrawX1();
    void drawArrow(QPainter &painter, const QPointF &start, const QPointF &end);
private:
    QPushButton *button1;
    QPushButton *button2;
    QVector<int> bins;
    QVector<QRectF> rects;
    int hitBin;
};

#endif // HISTOGRAM_H
