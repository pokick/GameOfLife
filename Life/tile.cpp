#include "tile.h"

tile::tile()
{

    this->live=false;


}



void    tile::setClicked(){

    if(live)
        live = false;
    else
        live = true;
}

