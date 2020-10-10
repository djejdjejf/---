#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
Player::Player()
{
    type=1;
    damage=1;
    shoot_delay=200;
    setPixmap(QPixmap("D:\\1_Desktop\\1_School\\QT\\MyCode\\wop\\image\\me.png"));

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,
            [=]()
    {
        QList<QGraphicsItem *> colliding_items = collidingItems();
                    for (int i = 0, n = colliding_items.size(); i < n; ++i)
                    {
                        if (typeid(*(colliding_items[i])) == typeid(Enemy))
                        {
                            // remove them both
                            scene()->removeItem(colliding_items[i]);
                            scene()->removeItem(this);
                            // delete them both
                            delete colliding_items[i];
                            delete this;
                            return;
                        }
                    }
        if(type==1)
        {
            Bullet * bullet = new Bullet(1);
            bullet->setPos(x() + 22,y());
            scene()->addItem(bullet);
            shoot_delay=100;
        }
    });
    timer->start(shoot_delay);
}
