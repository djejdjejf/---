#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "goldcoin.h"
#include "myscene.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include"bullet_e.h"
#include"global.h"

Player::Player()
{
    hp=20;
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
            music_shoot.setMedia(QUrl("qrc:/music/shoot.mp3"));
            music_shoot.setVolume(50);
            music_shoot.play();
            Bullet * bullet = new Bullet(1);
            bullet->setPos(x() + 43,y());
            scene()->addItem(bullet);
        }
        else if(type==2)
        {
            music_shoot.setMedia(QUrl("qrc:/music/shoot.mp3"));
            music_shoot.setVolume(50);
            music_shoot.play();
            Bullet * bullet = new Bullet(1);
            bullet->setPos(x() + 35,y());
            scene()->addItem(bullet);
            Bullet * bullet1 = new Bullet(1);
            bullet1->setPos(x() + 50,y());
            scene()->addItem(bullet1);
        }
        else if(type==3)
        {
            music_shoot.setMedia(QUrl("qrc:/music/shoot.mp3"));
            music_shoot.setVolume(50);
            music_shoot.play();
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
            music_shoot.setMedia(QUrl("qrc:/music/shoot.mp3"));
            music_shoot.setVolume(50);
            music_shoot.play();
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
                my_hp=hp;
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
                music_chijinbi.setMedia(QUrl("qrc:/music/chijinbi.mp3"));
                music_chijinbi.setVolume(50);
                music_chijinbi.play();
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                gold++;
                if(gold>=4)
                {
                    if(type!=4)
                    {
                        gold-=4;
                        mydamage_t++;
                        if(mydamage_t==2)
                            type=2;
                        else if(mydamage_t==3)
                            type=3;
                        else if(mydamage_t>=4)
                            type=4;
                        music_up.setMedia(QUrl("qrc:/music/update.mp3"));
                        music_up.setVolume(50);
                        music_up.play();
                    }
                    else
                    {
                        hp+=6;
                        my_hp+=6;
                    }
                }
                else if(type==4)
                {
                    hp+=6;
                    my_hp+=6;
                    score+=50;
                }
                return;
            }
        }
    });
    timer2->start(5);
}
