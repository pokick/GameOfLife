#include "board.h"

#include <iostream>

board::board()
{
    for(int x=0 ; x<300; x++){
        for(int y=0;y<200;y++){
           tileBoard[x][y]=tile();
        }
    }

       // std::cout<<"asd"<<std::endl;
        gameTimer.setInterval(40);
        QObject::connect(&gameTimer,SIGNAL(timeout()),this,SLOT(checkBoard()));
      //  gameTimer.start();


}


tile * board::getTile(int x,int y){

    return & tileBoard[x][y];

}

void board::setTile(int x,int y){


      //  std::cout<<"set click" << std::endl;
          tileBoard[x][y].setClicked();


}

void board::checkBoard(){

    int aliveNeightbour =0;
    tile tmp[300][200] ;

    for(int x=0;x<300;x++)
        for(int y=0;y<200;y++){
            tmp[x][y]=tileBoard[x][y];
        }

    for(int x=1;x<300;x++)
        for(int y=1;y<200;y++){

            aliveNeightbour =0;

            for(int xi = -1 ;xi<=1;xi++)
                for(int yi =-1;yi<=1;yi++){
                    if(xi!=0||yi!=0){
                        if(tileBoard[x+xi][y+yi].live)
                            aliveNeightbour++;

                    }
                }

            if((aliveNeightbour==3)&&!(tileBoard[x][y].live)){
                tmp[x][y].live=true;
            }else if(((aliveNeightbour==2)||(aliveNeightbour==3))&&(tileBoard[x][y].live)){
               tmp[x][y].live=true;
            }else if ((aliveNeightbour>3)&&( tileBoard[x][y].live)){
                 tmp[x][y].live=false;
            }else if ((aliveNeightbour<2)&&( tileBoard[x][y].live)){
                tmp[x][y].live=false;
           }


        }

    for(int x=0;x<300;x++)
        for(int y=0;y<200;y++){
           tileBoard[x][y]=tmp[x][y];
        }


}
void board::clearBoard(){


    for(int x=0;x<300;x++)
        for(int y=0;y<200;y++)
            tileBoard[x][y].live=false;
}
