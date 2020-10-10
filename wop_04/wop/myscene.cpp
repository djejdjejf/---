#include "myscene.h"
#include "player.h"
#include "enemy.h"
#include "bullet_e.h"
#include "goldcoin.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QPushButton>
#include <QDebug>
#include"global.h"
MyScene::MyScene()
{
    is_playing=0;
    is_have_boss=0;

    scene = new QGraphicsScene();
    QGraphicsPixmapItem *wall=new QGraphicsPixmapItem();
    wall->setPixmap(QPixmap(":/image/wall.png"));
    scene->addItem(wall);
    wall->setPos(0,-900);
    QTimer *timer_wall=new QTimer(this);
    connect(timer_wall,&QTimer::timeout,
            [=]()
    {
        if(wall->y()<=0)
            wall->setPos(0,wall->y()+5);
        else
            wall->setPos(0,-900);
    });
    timer_wall->start(10);

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
        normal_n=0;
        charge_n=0;
        float_n=0;
        big_n=0;
        boss_n=0;
        score=0;
        gold=0;
        mydamage_t=1;
        mydamage=1;

        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,700,900);

        QGraphicsPixmapItem *wall=new QGraphicsPixmapItem();
        wall->setPixmap(QPixmap(":/image/wall.png"));
        scene->addItem(wall);
        wall->setPos(0,-900);
        QTimer *timer_wall=new QTimer(this);
        connect(timer_wall,&QTimer::timeout,
                [=]()
        {
            if(wall->y()<=0)
                wall->setPos(0,wall->y()+5);
            else
                wall->setPos(0,-900);
        });
        timer_wall->start(10);

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
            if(boss_n==0)
            {
                if(score>=0&&score<3000)//40 40 10 10 0     10
                {
                    int x=rand()%100+1;
                    if(x>=1&&x<=20)
                    {
                        Goldcoin *goldcoin=new Goldcoin;
                        scene->addItem(goldcoin);
                    }
                    if(x>=1&&x<=40)
                    {
                        Enemy *enemy=new Enemy(1);
                        scene->addItem(enemy);

                        Bullet_e *bullet=new Bullet_e(1);
                        bullet->setPos(enemy->x()+60,enemy->y()+120);
                        scene->addItem(bullet);
                    }
                    else if(x>40&&x<=80)
                    {
                        Enemy *enemy=new Enemy(2);
                        scene->addItem(enemy);
                    }
                    else if(x>80&&x<=90)
                    {
                        Enemy *enemy=new Enemy(4);
                        scene->addItem(enemy);
                    }
                    else
                    {
                        Enemy *enemy=new Enemy(3);
                        scene->addItem(enemy);
                    }
                }
                else if(score>=3000&&score<5000)
                {
                    Enemy *enemy=new Enemy(5);
                    scene->addItem(enemy);
                }
            }

            qDebug()<<normal_n<<" "<<charge_n<<" "<<float_n<<" "<<big_n<<" "<<boss_n<<" "<<gold<<" "<<score<<" "<<rank;
        }
    });

    timer->start(1500);
    //----------------------------------------------
}

