#include "myscene.h"
#include "player.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QPushButton>

MyScene::MyScene()
{
    is_playing=0;
    is_have_boss=0;

    scene = new QGraphicsScene();
    player = new Player();
    scene->addItem(player);
    view = new QGraphicsView();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->move(500,0);
    view->setFixedSize(700,900);
    scene->setSceneRect(0,0,700,900);
    player->setPos(view->width()/2,view->height() - player->pixmap().height());

    //reload_scene();

    scene_begin = new QGraphicsScene();
    QGraphicsPixmapItem *image_begin=new QGraphicsPixmapItem();
    image_begin->setPixmap(QPixmap("D:\\1_Desktop\\1_School\\QT\\MyCode\\wop\\image\\me.png"));
    scene_begin->addItem(image_begin);
    image_begin->setPos(100,100);
    QPushButton *b1=new QPushButton();
    b1->setText("开始游戏");
    scene_begin->addWidget(b1);
    b1->resize(100,50);
    b1->move(300,500);
    view->setScene(scene_begin);
    view->show();
    scene_begin->setSceneRect(0,0,700,900);
    connect(b1,&QPushButton::clicked,
            [=]()
    {
        view->setScene(scene);
        is_playing=1;
    });

    scene_end = new QGraphicsScene();
    QGraphicsPixmapItem *image_end=new QGraphicsPixmapItem();
    image_end->setPixmap(QPixmap("D:\\1_Desktop\\1_School\\QT\\MyCode\\wop\\image\\me.png"));
    scene_end->addItem(image_end);
    image_end->setPos(0,0);
    QPushButton *b2=new QPushButton();
    b2->setText("重新开始");
    scene_end->addWidget(b2);
    b2->resize(100,50);
    b2->move(300,500);
    scene_end->setSceneRect(0,0,700,900);

    connect(player,&Player::destroyed,
            [=]()
    {
        is_playing=0;
        view->setScene(scene_end);
    });
    connect(b2,&QPushButton::clicked,
            [=]()
    {
        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,700,900);
        player = new Player();
        scene->addItem(player);
        player->setPos(view->width()/2,view->height() - player->pixmap().height());
        view->setScene(scene);
        is_playing=1;

        connect(player,&Player::destroyed,
                [=]()
        {
            is_playing=0;
            view->setScene(scene_end);
        });
    });
    //------刷怪------------------------------------
    QTimer * timer = new QTimer();

    QObject::connect(timer,&QTimer::timeout,
                     [=]()
    {
        if(is_playing==1)
        {
            Enemy *enemy=new Enemy(1,player);
            scene->addItem(enemy);
        }
    });

    timer->start(2000);
    //----------------------------------------------
}

