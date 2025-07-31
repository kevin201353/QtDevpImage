#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoadImage_clicked();

    void on_Histogram_clicked();

    void on_HistogramAvr_clicked();

private:
    Ui::MainWindow *ui;
    QImage m_image;
};
#endif // MAINWINDOW_H
