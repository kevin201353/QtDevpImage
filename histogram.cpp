#include "histogram.h"
#include <qlabel.h>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include "mainwindow.h"

HistoGram::HistoGram(QWidget *parent) : QWidget(parent)
{
    //this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
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
}

HistoGram::~HistoGram()
{
}

void HistoGram::OnCheckWindow()
{
    emit hotKeyPressed();
}
