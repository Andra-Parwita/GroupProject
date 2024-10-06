#include "tile.h"
#include "grid.h"

//constructors
grid::grid(){
    for (int i = 0; i < 5; i++){
        tiles = new tile*[20];
    }
}

grid::~grid(){delete tiles;}

//functions
void grid::addApplication(int x, int y, int appId){
    if (tiles[x][y].getIsOccupied() == false && appId != 0){
        tiles[x][y].occupy(appId);
    }
}
void grid::removeApplication(int x, int y){
    if (tiles[x][y].getIsOccupied() == true){
        tiles[x][y].clear();
    }
}