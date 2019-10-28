#include "gameoflife.h"
#include <QApplication>
#include <QScreen>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameOfLife w;

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int heightMain = screenGeometry.height();
    int widthMain = screenGeometry.width();

    w.setFixedSize(widthMain*0.99,heightMain*0.92);

    w.show();

    return a.exec();
}
