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
    QGraphicsScene *scene;
    QGraphicsScene *scene_begin;
    QGraphicsScene *scene_end;
    QGraphicsScene *scene_state;
    QGraphicsView *view;
    bool is_playing;
    bool is_have_boss;

    MyScene();

};

#endif // MYSCENE_H
