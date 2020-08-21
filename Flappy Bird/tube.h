#ifndef TUBE_H
#define TUBE_H
#include <QGraphicsRectItem>
#include "corpstube.h"
class tube: public QGraphicsPixmapItem
{
public:
    int x;
    int y;
    tubecorps corps[50];
};

#endif // TUBE_H
