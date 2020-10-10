#include "myscene.h"
#include "player.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>

MyScene::MyScene()
{
    QGraphicsScene *scene = new QGraphicsScene();

    //生成玩家
    player = new Player();

    //玩家加入场景
    scene->addItem(player);

    //使玩家可以检测键盘
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFlag(QGraphicsItem::ItemIsMovable);
    player->setFocus();

    //承载场景
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //显示
    view->move(500,0);
    view->show();
    view->setFixedSize(700,900);
    scene->setSceneRect(0,0,700,900);

    player->setPos(view->width()/2,view->height() - player->pixmap().height());
    //------刷怪------------------------------------
    QTimer * timer = new QTimer();

    QObject::connect(timer,&QTimer::timeout,
                     [=]()
    {
        Enemy *enemy=new Enemy;
        scene->addItem(enemy);
    });

    timer->start(500);
    //----------------------------------------------
}

