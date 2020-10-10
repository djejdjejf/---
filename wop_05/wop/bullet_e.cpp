#include "bullet_e.h"
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QList>
#include"global.h"
Bullet_e::Bullet_e(int type)
{
    if(type==1)//竖直普通子弹
    {
        setPixmap(QPixmap(":/image/bullet_e_1.png"));
        type=1;
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            setPos(x(),y()+8);
            if (pos().y() + pixmap().height() >920||pos().x()<0||pos().x()>700)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(20);
    }
    else if(type==2)
    {
        setPixmap(QPixmap(":/image/bullet_e_1.png"));
        type=2;
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            setPos(x()+1,y()+7);
            if (pos().y() + pixmap().height() >920||pos().x()<0||pos().x()>700)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(20);
    }
    else if(type==3)
    {
        setPixmap(QPixmap(":/image/bullet_e_1.png"));
        type=3;
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            setPos(x()+2,y()+6);
            if (pos().y() + pixmap().height() >920||pos().x()<0||pos().x()>700)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(20);
    }
    else if(type==4)
    {
        setPixmap(QPixmap(":/image/bullet_e_1.png"));
        type=4;
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            setPos(x()+3,y()+5);
            if (pos().y() + pixmap().height() >920||pos().x()<0||pos().x()>700)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(20);
    }
    else if(type==5)
    {
        setPixmap(QPixmap(":/image/bullet_e_1.png"));
        type=5;
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            setPos(x()+4,y()+4);
            if (pos().y() + pixmap().height() >920||pos().x()<0||pos().x()>700)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(20);
    }
    else if(type==6)
    {
        setPixmap(QPixmap(":/image/bullet_e_1.png"));
        type=2;
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            setPos(x()-1,y()+7);
            if (pos().y() + pixmap().height() >920||pos().x()<0||pos().x()>700)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(20);
    }
    else if(type==7)
    {
        setPixmap(QPixmap(":/image/bullet_e_1.png"));
        type=3;
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            setPos(x()-2,y()+6);
            if (pos().y() + pixmap().height() >920||pos().x()<0||pos().x()>700)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(20);
    }
    else if(type==8)
    {
        setPixmap(QPixmap(":/image/bullet_e_1.png"));
        type=4;
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            setPos(x()-3,y()+5);
            if (pos().y() + pixmap().height() >920||pos().x()<0||pos().x()>700)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(20);
    }
    else if(type==9)
    {
        setPixmap(QPixmap(":/image/bullet_e_1.png"));
        type=5;
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            setPos(x()-4,y()+4);
            if (pos().y() + pixmap().height() >920||pos().x()<0||pos().x()>700)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(20);
    }
}

Bullet_e::Bullet_e()
{

}
