#include "gameover.h"
#include <QFont>
#include <QString>


GameOver::GameOver()
{
    setPlainText(QString("GAME OVER"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",32));
}
