#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <QMainWindow>

namespace Ui {
class GameOfLife;
}

class GameOfLife : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameOfLife(QWidget *parent = 0);
    int getTileWidth(void);
    int getTileHeight(void);
    int tilesWidth;
    int tilesHeight;

    ~GameOfLife();

private:
    Ui::GameOfLife *ui;

public slots:

    void mousePressEvent(QMouseEvent *event);


private slots:
    void on_playButton_clicked();
    void on_pauseButton_clicked();
    void on_spinTimer_valueChanged(double arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};


#endif // GAMEOFLIFE_H
