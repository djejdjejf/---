#include "enemy.h"
#include <stdlib.h>
#include <QTimer>
Enemy::Enemy()
{
    setPixmap(QPixmap("D:\\1_Desktop\\1_School\\QT\\MyCode\\wop\\image\\enemy_1.png"));
    int random_number = rand() % 700;
    setPos(random_number,0);

    QTimer * timer = new QTimer(this);
    connect(timer,&QTimer::timeout,
            [=]()
    {
        setPos(x(),y()+1);
        if (pos().y() + this->pixmap().height() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    });

    timer->start(10);
}
