#include "canvas.h"
#include <board.h>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{



    this->setBaseSize(this->width(),this->height());
        //t = board();


    tim1.setInterval(10);

    connect(&tim1,SIGNAL(timeout()),this,SLOT(repaint()));

    tim1.start();

}

void Canvas::paintEvent(QPaintEvent *event){

    QPainter painter(this);

    for(int x =0;x<this->width()/10;x++)
        for(int y=0;y<this->height()/10;y++){


        painter.drawRect(QRect(x*10,y*10,10,10));
        if(t.getTile(x,y)->live)
            painter.fillRect((QRect(x*10,y*10,10,10)),Qt::SolidPattern);
            painter.drawRect(QRect(x*10,y*10,10,10));
        }



    }



