#include "maker.h"

maker::maker()
{
    setPixmap(QPixmap(":/image/ending.png"));
    setPos(0,1000);
    QTimer * timer = new QTimer(this);
    connect(timer,&QTimer::timeout,
            [=]()
    {
        setPos(x(),y()-1);
        if (pos().y() < -1100)
        {
            scene()->removeItem(this);
            delete this;
        }
    });
    timer->start(10);
}
