#include "myscene.h"
#include "player.h"
#include "enemy.h"
#include "bullet_e.h"
#include "goldcoin.h"
#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QPushButton>
#include <QDebug>
#include <QtMultimedia/QMediaPlayer>
#include"global.h"
#include<maker.h>
MyScene::MyScene()
{
    is_playing=0;
    is_have_boss=0;

    k=0;

    bar=new MainWindow();

    music_shoot.setMedia(QUrl("qrc:/music/shoot.mp3"));
    music_shoot.setVolume(50);
    music_chijinbi.setMedia(QUrl("qrc:/music/chijinbi.mp3"));
    music_chijinbi.setVolume(50);
    music_up.setMedia(QUrl("qrc:/music/update.mp3"));
    music_up.setVolume(50);

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
    image_begin->setPixmap(QPixmap(":/image/begin.png"));
    scene_begin->addItem(image_begin);
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
        bar->show();
        is_playing=1;
        music.setMedia(QUrl("qrc:/music/normal_2.mp3"));
        music.setVolume(50);
        music.play();
    });

    scene_end = new QGraphicsScene();
    QGraphicsPixmapItem *image_end=new QGraphicsPixmapItem();
    image_end->setPixmap(QPixmap(":/image/gameover.png"));
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
        music.stop();
        view->setScene(scene_end);
        bar->hide();
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
        my_hp=20;

        bar->show();

        music.setMedia(QUrl("qrc:/music/normal_2.mp3"));
        music.setVolume(50);
        music.play();

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
            music.stop();
            music_shoot.stop();
            music_chijinbi.stop();
            music_up.stop();
            bar->close();
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
                if(score>=0&&score<2000)//40 40 10 10 0     20
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
                else if(score>=2000&&score<4000)
                {
                    music.setMedia(QUrl("qrc:/music/boss_1.mp3"));
                    music.setVolume(50);
                    music.play();
                    Enemy *enemy=new Enemy(5);
                    scene->addItem(enemy);
                }
                else if(score>=4000&&score<6000)//30 30 20 20 0   20
                {
                    hp_k=3;
                    if(k==0)
                    {
                        music.setMedia(QUrl("qrc:/music/normal_1.mp3"));
                        music.setVolume(50);
                        music.play();
                        k=1;
                    }
                    int x=rand()%100+1;
                    int x2=rand()%100+1;
                    if(x2>=1&&x2<=20)
                    {
                        Goldcoin *goldcoin=new Goldcoin;
                        scene->addItem(goldcoin);
                    }
                    if(x>=1&&x<=30)
                    {
                        Enemy *enemy=new Enemy(1);
                        scene->addItem(enemy);

                        Bullet_e *bullet=new Bullet_e(1);
                        bullet->setPos(enemy->x()+60,enemy->y()+120);
                        scene->addItem(bullet);
                    }
                    else if(x>30&&x<=60)
                    {
                        Enemy *enemy=new Enemy(2);
                        scene->addItem(enemy);
                    }
                    else if(x>60&&x<=80)
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
                else if(score>=6000&&score<8000)
                {
                    music.setMedia(QUrl("qrc:/music/boss_2.mp3"));
                    music.setVolume(50);
                    music.play();
                    Enemy *enemy=new Enemy(5);
                    scene->addItem(enemy);
                }
                else if(score>8000)
                {

                    if(!is_end_show)
                    {
                        maker *m1=new maker;
                        scene->addItem(m1);
                        is_end_show=1;
                        my_hp=9999;
                        player->hp=9999;
                    }
                    hp_k=3;
                    int x=rand()%100+1;
                    if(x>=1&&x<=30)
                    {
                        Enemy *enemy=new Enemy(1);
                        scene->addItem(enemy);

                        Bullet_e *bullet=new Bullet_e(1);
                        bullet->setPos(enemy->x()+60,enemy->y()+120);
                        scene->addItem(bullet);
                    }
                    else if(x>30&&x<=60)
                    {
                        Enemy *enemy=new Enemy(2);
                        scene->addItem(enemy);
                    }
                    else if(x>60&&x<=80)
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
            }
            qDebug()<<normal_n<<" "<<charge_n<<" "<<float_n<<" "<<big_n<<" "<<boss_n<<" "<<my_hp<<" "<<gold<<" "<<score<<" "<<rank;
        }
    });

    timer->start(1500);
    //----------------------------------------------
    connect(this,&MyScene::destroyed,
            [=]()
    {
        music.stop();
        music_shoot.stop();
        music_chijinbi.stop();
        music_up.stop();
        view->close();
        bar->close();
    });
}

