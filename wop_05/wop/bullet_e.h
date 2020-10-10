#ifndef BULLET_E_H
#define BULLET_E_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>

class Bullet_e : public QObject,public QGraphicsPixmapItem
{
public:

    int type;
    int damage;
    Bullet_e();
    Bullet_e(int);
};

#endif // BULLET_E_H
