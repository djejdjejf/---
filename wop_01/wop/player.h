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
    int hp;
    Player();
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
