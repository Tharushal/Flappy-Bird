#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMouseEvent>

class flappybird: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    flappybird();
    void keyPressEvent(QKeyEvent *event);
    bool gameOver();
    void increaseS();
    void FinPartie();

public slots:
    void move();
};


#endif // FLAPPYBIRD_H
