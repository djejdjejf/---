#include "player.h"
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
Player::Player()
{
    setPixmap(QPixmap("D:\\1_Desktop\\1_School\\QT\\MyCode\\wop\\image\\me.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,&QTimer::timeout,
            [=]()
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + 22,y());
        scene()->addItem(bullet);
    });
    timer->start(200);
}
void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + 60,y());
        scene()->addItem(bullet);
    }
}
