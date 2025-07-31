#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoadImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
    m_image.load(fileName);
    ui->label_showImage->setPixmap(QPixmap::fromImage(m_image));
    ui->label_showImage->resize(m_image.size());
}


void MainWindow::on_Histogram_clicked()
{

}

void MainWindow::on_HistogramAvr_clicked()
{

}
