#include "mainwindow.h"
#include"global.h"
#include <QLabel>
#include <QString>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("数据板");
    move(1250,0);
    resize(300,300);
    QLabel *label_1=new QLabel(this);
    QLabel *label_2=new QLabel(this);
    QLabel *label_3=new QLabel(this);
    label_1->setFont(QFont("微软雅黑",36));
    label_2->setFont(QFont("微软雅黑",36));
    label_3->setFont(QFont("微软雅黑",36));
    label_1->resize(300,100);
    label_2->resize(300,100);
    label_3->resize(300,100);
    label_1->move(0,0);
    label_2->move(0,100);
    label_3->move(0,200);
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,
            [=]()
    {
        label_1->setText(QString("剩余血量: ")+QString::number(my_hp));
        label_2->setText(QString("得分: ")+QString::number(score));
        label_3->setText(QString("金币: ")+QString::number(gold));
    });
    timer->start(50);
}

MainWindow::~MainWindow()
{

}
