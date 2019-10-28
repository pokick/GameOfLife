#ifndef BOARD_H
#define BOARD_H

#include <tile.h>
#include <QTimer>

class board : public QObject
{

    Q_OBJECT

public:
    board();


    QTimer gameTimer;
    tile tileBoard[300][200];


    tile * getTile(int,int);

    void setTile(int x,int y);
    void clearBoard(void);
public slots :

      void checkBoard();


};

#endif // BOARD_H
