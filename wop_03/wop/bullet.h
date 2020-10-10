#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>


class Bullet : public QObject,public QGraphicsPixmapItem
{
public:
    int type;
    int damage;
    Bullet();
    Bullet(int);

};

#endif // BULLET_H
