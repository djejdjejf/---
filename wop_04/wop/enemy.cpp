#include "enemy.h"
#include "bullet.h"
#include "bullet_e.h"
#include "player.h"
#include <stdlib.h>
#include <QTimer>
#include"global.h"
Enemy::Enemy()
{

}

Enemy::Enemy(int type)
{
    if(type==1)
    {
        normal_n++;
        setPixmap(QPixmap(":/image/enemy_1.png"));
        hp=5;
        score_=20;
        int random_number = rand() % 580;
        setPos(random_number,0);
        QTimer * timer = new QTimer(this);
        QTimer * timer2 = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            QList<QGraphicsItem *> colliding_items = collidingItems();
                        for (int i = 0, n = colliding_items.size(); i < n; ++i)
                        {
                            if (typeid(*(colliding_items[i])) == typeid(Bullet))
                            {
                                hp-=mydamage;
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
            setPos(x(),y()+1);
            if (pos().y() + this->pixmap().height() < 0)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        connect(timer2,&QTimer::timeout,
                [=]()
        {
            Bullet_e *bullet=new Bullet_e(1);
            bullet->setPos(x()+60,y()+120);
            scene()->addItem(bullet);
            /*Bullet_e *bullet2=new Bullet_e(2);
            bullet2->setPos(x()+60,y()+120);
            scene()->addItem(bullet2);*/
            Bullet_e *bullet3=new Bullet_e(3);
            bullet3->setPos(x()+60,y()+120);
            scene()->addItem(bullet3);
            /*Bullet_e *bullet4=new Bullet_e(4);
            bullet4->setPos(x()+60,y()+120);
            scene()->addItem(bullet4);
            Bullet_e *bullet5=new Bullet_e(5);
            bullet5->setPos(x()+60,y()+120);
            scene()->addItem(bullet5);*/

            /*Bullet_e *bullet6=new Bullet_e(6);
            bullet6->setPos(x()+60,y()+120);
            scene()->addItem(bullet6);*/
            Bullet_e *bullet7=new Bullet_e(7);
            bullet7->setPos(x()+60,y()+120);
            scene()->addItem(bullet7);
            /*Bullet_e *bullet8=new Bullet_e(8);
            bullet8->setPos(x()+60,y()+120);
            scene()->addItem(bullet8);
            Bullet_e *bullet9=new Bullet_e(9);
            bullet9->setPos(x()+60,y()+120);
            scene()->addItem(bullet9);*/
        });
        timer->start(10);
        timer2->start(2500);
        connect(this,&Enemy::destroyed,
                [=]()
        {
            normal_n--;
            score+=score_;
        });
    }
    else if(type==2)
    {
        charge_n++;
        setPixmap(QPixmap(":/image/enemy_1.png"));
        hp=2;
        score_=30;
        int random_number = rand() % 580;
        setPos(random_number,0);
        QTimer * timer = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            QList<QGraphicsItem *> colliding_items = collidingItems();
                        for (int i = 0, n = colliding_items.size(); i < n; ++i)
                        {
                            if (typeid(*(colliding_items[i])) == typeid(Bullet))
                            {
                                hp-=mydamage;
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
            setPos(x(),y()+6);
            if (pos().y() + this->pixmap().height() < 0)
            {
                scene()->removeItem(this);
                delete this;
            }
        });
        timer->start(10);
        connect(this,&Enemy::destroyed,
                [=]()
        {
            charge_n--;
            score+=score_;
        });
    }
    else if(type==3)
    {
        float_n++;
        setPixmap(QPixmap(":/image/enemy_1.png"));
        hp=7;
        score_=50;
        setPos((rand()%2==0?-120:700),rand()%400);
        QTimer * timer = new QTimer(this);
        QTimer * timer2 = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            QList<QGraphicsItem *> colliding_items = collidingItems();
                        for (int i = 0, n = colliding_items.size(); i < n; ++i)
                        {
                            if (typeid(*(colliding_items[i])) == typeid(Bullet))
                            {
                                hp-=mydamage;
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
            if(x()<350&&x()<0)
                setPos(x()+1,y());
            else if(x()>350&&x()>580)
                setPos(x()-1,y());
        });
        connect(timer2,&QTimer::timeout,
                [=]()
        {
            if(x()<350)
            {
                Bullet_e *bullet2=new Bullet_e(2);
                bullet2->setPos(x()+60,y()+120);
                scene()->addItem(bullet2);
                Bullet_e *bullet3=new Bullet_e(3);
                bullet3->setPos(x()+60,y()+120);
                scene()->addItem(bullet3);
                Bullet_e *bullet4=new Bullet_e(4);
                bullet4->setPos(x()+60,y()+120);
                scene()->addItem(bullet4);
                Bullet_e *bullet5=new Bullet_e(5);
                bullet5->setPos(x()+60,y()+120);
                scene()->addItem(bullet5);
            }
            else
            {
                Bullet_e *bullet6=new Bullet_e(6);
                bullet6->setPos(x()+60,y()+120);
                scene()->addItem(bullet6);
                Bullet_e *bullet7=new Bullet_e(7);
                bullet7->setPos(x()+60,y()+120);
                scene()->addItem(bullet7);
                Bullet_e *bullet8=new Bullet_e(8);
                bullet8->setPos(x()+60,y()+120);
                scene()->addItem(bullet8);
                Bullet_e *bullet9=new Bullet_e(9);
                bullet9->setPos(x()+60,y()+120);
                scene()->addItem(bullet9);
            }


        });
        timer->start(10);
        timer2->start(3000);
        connect(this,&Enemy::destroyed,
                [=]()
        {
            float_n--;
            score+=score_;
        });
    }
    else if(type==4)
    {
        big_n++;
        setPixmap(QPixmap(":/image/enemy_1.png"));
        hp=15;
        score_=100;
        int random_number = rand() % 580;
        setPos(random_number,0);
        QTimer * timer = new QTimer(this);
        QTimer * timer2 = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            QList<QGraphicsItem *> colliding_items = collidingItems();
                        for (int i = 0, n = colliding_items.size(); i < n; ++i)
                        {
                            if (typeid(*(colliding_items[i])) == typeid(Bullet))
                            {
                                hp-=mydamage;
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
             setPos(x(),y()+1);
             if (pos().y() + this->pixmap().height() < 0)
             {
             scene()->removeItem(this);
             delete this;
             }
        });
        connect(timer2,&QTimer::timeout,
                [=]()
        {
            Bullet_e *bullet=new Bullet_e(1);
            bullet->setPos(x()+60,y()+120);
            scene()->addItem(bullet);

            Bullet_e *bullet2=new Bullet_e(2);
            bullet2->setPos(x()+60,y()+120);
            scene()->addItem(bullet2);

            Bullet_e *bullet6=new Bullet_e(6);
            bullet6->setPos(x()+60,y()+120);
            scene()->addItem(bullet6);
        });
        timer->start(20);
        timer2->start(3000);
        connect(this,&Enemy::destroyed,
                [=]()
        {
            big_n--;
            score+=score_;
        });
    }
    else if(type==5)
    {
        boss_n++;
        setPixmap(QPixmap(":/image/enemy_1.png"));
        hp=300;
        score_=2000;
        setPos(290,0);
        QTimer * timer = new QTimer(this);
        QTimer * timer2 = new QTimer(this);
        connect(timer,&QTimer::timeout,
                [=]()
        {
            QList<QGraphicsItem *> colliding_items = collidingItems();
                        for (int i = 0, n = colliding_items.size(); i < n; ++i)
                        {
                            if (typeid(*(colliding_items[i])) == typeid(Bullet))
                            {
                                hp-=mydamage;
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
        connect(timer2,&QTimer::timeout,
                [=]()
        {
            int n=rand()%121;
            Bullet_e *bullet=new Bullet_e(1);
            bullet->setPos(x()+n,y()+120);
            scene()->addItem(bullet);
            Bullet_e *bullet2=new Bullet_e(2);
            bullet2->setPos(x()+n,y()+120);
            scene()->addItem(bullet2);
            Bullet_e *bullet3=new Bullet_e(3);
            bullet3->setPos(x()+n,y()+120);
            scene()->addItem(bullet3);
            Bullet_e *bullet4=new Bullet_e(4);
            bullet4->setPos(x()+n,y()+120);
            scene()->addItem(bullet4);
            Bullet_e *bullet5=new Bullet_e(5);
            bullet5->setPos(x()+n,y()+120);
            scene()->addItem(bullet5);

            Bullet_e *bullet6=new Bullet_e(6);
            bullet6->setPos(x()+n,y()+120);
            scene()->addItem(bullet6);
            Bullet_e *bullet7=new Bullet_e(7);
            bullet7->setPos(x()+n,y()+120);
            scene()->addItem(bullet7);
            Bullet_e *bullet8=new Bullet_e(8);
            bullet8->setPos(x()+n,y()+120);
            scene()->addItem(bullet8);
            Bullet_e *bullet9=new Bullet_e(9);
            bullet9->setPos(x()+n,y()+120);
            scene()->addItem(bullet9);
        });
        timer->start(20);
        timer2->start(500);
        connect(this,&Enemy::destroyed,
                [=]()
        {
            boss_n--;
            score+=score_;
        });
    }
}
