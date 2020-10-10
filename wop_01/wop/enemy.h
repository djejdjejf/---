#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class Enemy : public QObject,public QGraphicsPixmapItem
{
public:
    int hp;
    Enemy();
};

#endif // ENEMY_H
