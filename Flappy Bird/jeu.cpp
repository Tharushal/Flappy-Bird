#include "jeu.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "tube.h"
#include <QPixmap>
#include <QLabel>
#include <QMovie>
#include <QtPlugin>



Game::Game(QWidget *parent)
{
    // Création de la scène
    scene=new QGraphicsScene();
    setScene(scene);
    setFixedSize(650,420);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //Création et focalisation sur le joueur
    joueur=new flappybird();
    joueur->setFlag(QGraphicsItem::ItemIsFocusable);
    joueur->setFocus();

    //Ajout du joueur à la scène
    scene->addItem(joueur);
    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));





    //Positionnez le joueur
    joueur->setPos(20,100);

    //Tout Premier Tube HAUT
    int i;
    tubesH[0].x=joueur->x()+400;
    tubesH[0].y=100;

    tubesH[0].corps[0].x=tubesH[0].x;
    tubesH[0].corps[0].y=tubesH[0].y-7;
    tubesH[0].corps[0].setPos(tubesH[0].corps[0].x, tubesH[0].corps[0].y);
    tubesH[0].corps[0].setPixmap(QPixmap(":/images/corpTube.png"));
    scene->addItem(tubesH[0].corps);

    for(i=1;i<50;i++)
    {
        tubesH[0].corps[i].x= tubesH[0].corps[i-1].x;
        tubesH[0].corps[i].y= tubesH[0].corps[i-1].y-7;
        tubesH[0].corps[i].setPos(tubesH[0].corps[i].x,tubesH[0].corps[i].y);
        tubesH[0].corps[i].setPixmap(QPixmap(":/images/corpTube.png"));
        scene->addItem(tubesH[0].corps+i);
    }

    tubesH[0].setPos(tubesH[0].x,tubesH[0].y);
    tubesH[0].setPixmap(QPixmap(":/images/TeteTubeH.png"));
    scene->addItem(tubesH);

    // Reste Des Tubes Haut
    for(i=1;i<100;i++)
    {
        tubesH[i].x=tubesH[i-1].x+300;
        tubesH[i].y=rand()%100+50;
        tubesH[i].setPos(tubesH[i].x,tubesH[i].y);
        tubesH[i].setPixmap(QPixmap(":/images/TeteTubeH.png"));
        scene->addItem(tubesH+i);
        tubesH[i].corps[0].x=tubesH[i].x;
        tubesH[i].corps[0].y=tubesH[i].y-7;
        tubesH[i].corps[0].setPos(tubesH[i].corps[0].x,tubesH[i].corps[0].y);
        tubesH[i].corps[0].setPixmap(QPixmap(":/images/corpTube.png"));
        scene->addItem(tubesH[i].corps);
        for(int j=1;j<50;j++)
        {
            tubesH[i].corps[j].x=tubesH[i].corps[j-1].x;
            tubesH[i].corps[j].y=tubesH[i].corps[j-1].y-7;
            tubesH[i].corps[j].setPos(tubesH[i].corps[j].x,tubesH[i].corps[j].y);
            tubesH[i].corps[j].setPixmap(QPixmap(":/images/corpTube.png"));
            scene->addItem(tubesH[i].corps+j);
        }
    }

    // Tout Premier Tube Bas

    tubesB[0].x=tubesH[0].x;
    tubesB[0].y=tubesH[0].y+150;

    tubesB[0].corps[0].x=tubesB[0].x+6;
    tubesB[0].corps[0].y=tubesB[0].y+70;
    tubesB[0].corps[0].setPos(tubesB[0].corps[0].x, tubesB[0].corps[0].y);
    tubesB[0].corps[0].setPixmap(QPixmap(":/images/corpTubeB.png"));
    scene->addItem(tubesB[0].corps);

    for(i=1;i<50;i++)
    {
        tubesB[0].corps[i].x= tubesB[0].corps[i-1].x;
        tubesB[0].corps[i].y= tubesB[0].corps[i-1].y+30;
        tubesB[0].corps[i].setPos(tubesB[0].corps[i].x,tubesB[0].corps[i].y);
        tubesB[0].corps[i].setPixmap(QPixmap(":/images/corpTubeB.png"));
        scene->addItem(tubesB[0].corps+i);
    }

    tubesB[0].setPos(tubesB[0].x,tubesB[0].y);
    tubesB[0].setPixmap(QPixmap(":/images/TeteTubeB.png"));

    scene->addItem(tubesB);

    // Pour Le Reste Des Tubes Bas

    for(i=1;i<100;i++)
    {
        tubesB[i].x=tubesH[i-1].x+300;
        tubesB[i].y=tubesH[i].y+150;
        tubesB[i].setPos(tubesB[i].x,tubesB[i].y);
        tubesB[i].setPixmap(QPixmap(":/images/TeteTubeB.png"));
        scene->addItem(tubesB+i);

        tubesB[i].corps[0].x=tubesB[i].x+6;
        tubesB[i].corps[0].y=tubesB[i].y+70;
        tubesB[i].corps[0].setPos(tubesB[i].corps[0].x,tubesB[i].corps[0].y);
        tubesB[i].corps[0].setPixmap(QPixmap(":/images/corpTubeB.png"));
        scene->addItem(tubesB[i].corps);

        for(int j=1;j<50;j++)
        {
            tubesB[i].corps[j].x=tubesB[i].corps[j-1].x;
            tubesB[i].corps[j].y=tubesB[i].corps[j-1].y+30;
            tubesB[i].corps[j].setPos(tubesB[i].corps[j].x,tubesB[i].corps[j].y);
            tubesB[i].corps[j].setPixmap(QPixmap(":/images/corpTubeB.png"));
            scene->addItem(tubesB[i].corps+j);
        }
    }
    //Initialisation Du score;
    s=new score();
    scene->addItem(s);








}
