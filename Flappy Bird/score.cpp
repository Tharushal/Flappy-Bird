#include "score.h"
#include <QFont>
#include <QString>
#include "jeu.h"

extern Game* game;

score::score(QGraphicsItem *)
{
    n=0;
    setPlainText(QString("Score : ")+ QString::number(n));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",10));
}
