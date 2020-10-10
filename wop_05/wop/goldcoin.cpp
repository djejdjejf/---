#include "goldcoin.h"

Goldcoin::Goldcoin()
{
    setPixmap(QPixmap(":/image/goldcoin.png"));
    int random_number = rand() % 666;
    setPos(random_number,0);
    QTimer * timer = new QTimer(this);
    connect(timer,&QTimer::timeout,
            [=]()
    {
        setPos(x(),y()+6);
        if (pos().y() >900 )
        {
            scene()->removeItem(this);
            delete this;
        }
    });
    timer->start(10);
}
