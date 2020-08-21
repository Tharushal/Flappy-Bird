#include "flappybird.h"
#include <QTimer>
#include <QKeyEvent>
#include "jeu.h"
#include <windows.h>
#include <QPixmap>
#include <QDebug>
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QEvent>
#include <QMouseEvent>
#include "gameover.h"
extern Game* game;



flappybird::flappybird()
{
    setPixmap(QPixmap(":/images/birdy.png"));
    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(0);
}

void flappybird::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space)
    {
        setPos(x(),y()-20);
        setTransformOriginPoint(50,50);
        setRotation(-20);
    }
}

bool flappybird::gameOver()
{
    bool fin=false;
    QList<QGraphicsItem *>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid(*(colliding_items[i]))==typeid(game->tubesH[i])||(typeid(*(colliding_items[i]))==typeid(game->tubesB[i])))
        {
            fin=true;
        }
        for(int j=0,n=colliding_items.size();j<n;j++)
        {
            if(typeid(*(colliding_items[i]))==typeid(game->tubesH[i].corps[j]) || typeid(*(colliding_items[i]))==typeid(game->tubesB[i].corps[j]))
            {
                fin=true;
            }
        }
    }
    if(y()>340)
    {
        fin=true;
    }
    return fin;
}

void flappybird::increaseS()
{
    if(this->x()>game->tubesH[game->s->n].x+100)
    {
        game->s->n++;
        game->s->setPlainText(QString("Score : ")+ QString::number(game->s->n));
    }

}

void flappybird::FinPartie()
{
    for(int i=0;i<100;i++)
    {
        scene()->removeItem(game->tubesH+i);
        scene()->removeItem(game->tubesB+i);
        for(int j=0;j<50;j++)
        {
            scene()->removeItem(game->tubesH[i].corps+j);
            scene()->removeItem(game->tubesB[i].corps+j);
        }
    }
    delete this;
}

void flappybird::move()
{
    setPos(x()+25,y());
    Sleep(80);
    setPos(x(),y()+5);
    scene()->setSceneRect(x()-100,0,1000,1000);
    game->s->setPos(x()-100,380);
    setRotation(0);
    increaseS();
    if(gameOver()==true && game->s->n<100)
    {
        GameOver* g=new GameOver();
        g->setPos(game->joueur->x()+80,160);
        game->s->setFont(QFont("times",20));
        game->s->setPos(game->joueur->x()+165,220);
        scene()->addItem(g);
        FinPartie();
    }
    else if(gameOver()==true && game->s->n==100)
    {
        GameOver* g=new GameOver();
        g->setPos(game->joueur->x()+80,160);
        game->s->setPlainText(QString("YOU WIN !!!!!"));
        game->s->setFont(QFont("times",20));
        game->s->setPos(game->joueur->x()+165,220);
        scene()->addItem(g);
        FinPartie();
    }

}
