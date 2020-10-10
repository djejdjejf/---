#include "mainwindow.h"
#include "myscene.h"
#include "player.h"
#include "enemy.h"
#include <QApplication>
#include <QTimer>
#include"global.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyScene scene;


    return a.exec();
}
