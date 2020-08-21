#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class score: public QGraphicsTextItem
{
public:
    score(QGraphicsItem* parent=0);
    int n;
};



#endif // SCORE_H
