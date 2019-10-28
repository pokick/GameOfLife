#include "gameoflife.h"
#include "ui_gameoflife.h"
#include "canvas.h"
#include <iostream>
#include <qfile>
#include <QDataStream>
#include <QFileDialog>
#include <QString>
#include <QTextStream>



GameOfLife::GameOfLife(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOfLife)
{

    ui->setupUi(this);

     //tilesWidth = this->width();
//     tilesHeight = this->height();

}


GameOfLife::~GameOfLife()
{
    delete ui;
}






void GameOfLife::mousePressEvent(QMouseEvent *event){

        qsrand(0);

 // int x =(QCursor::pos().x()-GameOfLife::pos().x()-1)/10;
 // int y =(QCursor::pos().y()-GameOfLife::pos().y()-1)/10;
//std::cout<<x<<" "<<y<<std::endl;

    int x = GameOfLife::mapFromGlobal(QCursor::pos()).x();
    int y = GameOfLife::mapFromGlobal(QCursor::pos()).y();

    x/=10;
    y/=10;
    y-=4;



    if((x<300)&&(x>=0)){
        if((y<200)&&(y>=0)){
           // std::cout<<x<<" "<<y<<std::endl;
            Canvas * can = static_cast<Canvas*>(ui->widget);
            can->t.setTile(x,y);
    }

}

}

void GameOfLife::on_playButton_clicked()
{

    Canvas * can = static_cast<Canvas*>(ui->widget);
    ui->label->setText("Running");
    can->t.gameTimer.start();
}

void GameOfLife::on_pauseButton_clicked()
{
    Canvas * can = static_cast<Canvas*>(ui->widget);
    ui->label->setText("Paused");
    can->t.gameTimer.stop();
}

void GameOfLife::on_spinTimer_valueChanged(double arg1)
{
    Canvas * can = static_cast<Canvas*>(ui->widget);
    int time=(int)arg1*1000;
    can->tim1.setInterval(time);

}

void GameOfLife::on_pushButton_clicked()
{
    on_pauseButton_clicked();
    Canvas * can = static_cast<Canvas*>(ui->widget);



  //  can->t.setTile(10,10);
     qDebug("test");

    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open a Living structure"), "",
            tr("Life Database (*.life);;All Files (*)"));

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug("EERRPRPR");


    int offsetx=10;
    int offsety=10;



    QTextStream input(&file);


    int x,y=0;

   while(!input.atEnd()){


       QString line = input.readLine();
        for(x=0;x<line.length();x++){
            if(line[x].toLatin1()=='1')
                can->t.setTile(x+offsetx,y+offsety);

        }

        y++;

}
        can->repaint();
    ui->label->setText("Loaded");

}



void GameOfLife::on_pushButton_2_clicked()
{



    Canvas * can = static_cast<Canvas*>(ui->widget);

    for(int x=0;x<300;x++){

        for(int y=0;y<200;y++){
            can->t.clearBoard();
        }
    }

     can->repaint();

      ui->label->setText("Cleared");
}

void GameOfLife::on_pushButton_3_clicked()
{


    Canvas * can = static_cast<Canvas*>(ui->widget);

    for(int x=0;x<300;x++){
        int rand1=qrand()%100;
        for(int y=0;y<200;y++){
            if(rand1<(int)qrand()%100)
            can->t.setTile(x,y);
        }
    }

     can->repaint();

      ui->label->setText("Random");
}
