#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class Player : public QObject,public QGraphicsPixmapItem
{
public:
    int type;
    int hp;
    int damage;
    int shoot_delay;
    QTimer *timer;
    Player();
};

#endif // PLAYER_H
