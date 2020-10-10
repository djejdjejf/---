#ifndef MAKER_H
#define MAKER_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>


class maker: public QObject,public QGraphicsPixmapItem
{
public:
    maker();
};

#endif // MAKER_H
