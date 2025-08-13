#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_histogram = new HistoGram(this);
    m_histogram->resize(400,300);
   // m_histogram->move(10,50);
    m_histogram->show();
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->setContentsMargins(0,90,400,300);
    hlayout->addWidget(m_histogram);
    this->setLayout(hlayout);
    connect(m_histogram, &HistoGram::hotKeyPressed, this, &OnCheckWindow);
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
    showHistogram(m_image);
}

void MainWindow::on_HistogramAvr_clicked()
{

}

void MainWindow::showHistogram(QImage grayimage)
{

}

void MainWindow::OnCheckWindow()
{
    QMessageBox message(QMessageBox::NoIcon, "Title","Content with icon 222.");
    message.exec();
}
