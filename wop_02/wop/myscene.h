#ifndef MYSCENE_H
#define MYSCENE_H
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>


class MyScene : public QGraphicsScene
{
public:
    Player *player;

    MyScene();

};

#endif // MYSCENE_H
