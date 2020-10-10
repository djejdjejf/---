#ifndef GOLDCOIN_H
#define GOLDCOIN_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class Goldcoin : public QObject,public QGraphicsPixmapItem
{
public:
    Goldcoin();
};

#endif // GOLDCOIN_H
