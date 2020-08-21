#ifndef JEU_H
#define JEU_H

#include <QGraphicsView>
#include <flappybird.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "tube.h"
#include "score.h"

class Game:public QGraphicsView
{
public:
    Game(QWidget* parent=0);
    QGraphicsScene* scene;
    QGraphicsView* view;
    flappybird* joueur;
    tube tubesH[200];
    tube tubesB[200];
    score *s;

};

#endif // JEU_H
