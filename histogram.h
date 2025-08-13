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
    QPushButton *button1;
    QPushButton *button2;
};

#endif // HISTOGRAM_H
