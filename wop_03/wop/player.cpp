#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include"bullet_e.h"
#include"global.h"

Player::Player()
{
    hp=10;
    type=1;
    shoot_delay=200;
    setPixmap(QPixmap(":/image/me.png"));
    setFlag(QGraphicsItem::ItemIsMovable);
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
        }
        else if(type==2)
        {
            Bullet * bullet = new Bullet(1);
            bullet->setPos(x() + 15,y());
            scene()->addItem(bullet);
            Bullet * bullet1 = new Bullet(1);
            bullet1->setPos(x() + 33,y());
            scene()->addItem(bullet1);
        }
    });

    timer->start(shoot_delay);

    QTimer *timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,
            [=]()
    {
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
            if (typeid(*(colliding_items[i])) == typeid(Bullet_e))
            {
                hp-=e_b_damage;
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                if(hp<=0)
                {
                    scene()->removeItem(this);
                    delete this;
                }
                return;
            }
        }
    });
    timer2->start(5);
}
