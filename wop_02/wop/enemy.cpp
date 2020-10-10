#include "enemy.h"
#include "bullet.h"
#include "bullet_e.h"
#include "player.h"
#include <stdlib.h>
#include <QTimer>

Enemy::Enemy()
{

}

Enemy::Enemy(int type,Player *player)
{
    if(type==1)
    {
        setPixmap(QPixmap("D:\\1_Desktop\\1_School\\QT\\MyCode\\wop\\image\\enemy_1.png"));
        hp=10;
        int random_number = rand() % 700;
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
                                hp-=player->damage;
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
        });
        timer->start(10);
        timer2->start(3000);
        return;
    }
}
