#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "goldcoin.h"
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
            bullet->setPos(x() + 43,y());
            scene()->addItem(bullet);
        }
        else if(type==2)
        {
            Bullet * bullet = new Bullet(1);
            bullet->setPos(x() + 35,y());
            scene()->addItem(bullet);
            Bullet * bullet1 = new Bullet(1);
            bullet1->setPos(x() + 50,y());
            scene()->addItem(bullet1);
        }
        else if(type==3)
        {
            Bullet * bullet = new Bullet(1);
            bullet->setPos(x() + 27,y());
            scene()->addItem(bullet);
            Bullet * bullet1 = new Bullet(1);
            bullet1->setPos(x() + 42,y());
            scene()->addItem(bullet1);
            Bullet * bullet2 = new Bullet(1);
            bullet2->setPos(x() + 57,y());
            scene()->addItem(bullet2);
        }
        else if(type==4)
        {
            Bullet * bullet6 = new Bullet(1);
            bullet6->setPos(x() + 20,y());
            scene()->addItem(bullet6);
            Bullet * bullet7 = new Bullet(1);
            bullet7->setPos(x() + 35,y());
            scene()->addItem(bullet7);
            Bullet * bullet8 = new Bullet(1);
            bullet8->setPos(x() + 50,y());
            scene()->addItem(bullet8);
            Bullet * bullet9 = new Bullet(1);
            bullet9->setPos(x() + 65,y());
            scene()->addItem(bullet9);
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
            if (typeid(*(colliding_items[i])) == typeid(Goldcoin))
            {
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                gold++;
                if(gold>=5)
                {
                    if(type!=4)
                    {
                        gold-=5;
                        mydamage_t++;
                        if(mydamage_t==2)
                            type=2;
                        else if(mydamage_t==3)
                            type=3;
                        else if(mydamage_t>=4)
                            type=4;
                    }
                    else
                    {
                        hp+=10;
                        score+=500;
                    }
                }
                return;
            }
        }
    });
    timer2->start(5);
}
