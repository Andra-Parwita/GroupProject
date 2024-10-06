#include "tile.h"
#include "grid.h"
#include <iostream>

//constructors
grid::grid(){
    tiles = new tile*[5];

    for (int i = 0; i < 5; i++){
        tiles[i] = new tile[20];
    }
}

grid::~grid(){delete tiles;}

//functions
bool grid::addApplication(int x, int y, int appId){
    if ((tiles[x][y].getIsOccupied() == false) && (appId != 5)){
        tiles[x][y].occupy(appId);
        std::cout << "added " << appId << " to " << x << " " <<  y << std::endl;
        return true;
    } else if ((appId == 5) && ((tiles[x][y].getIsOccupied() == true))){
        std::cout << "removed " << tiles[x][y].getApplicationType().getId() << " at " << x << " " <<  y << std::endl;
        tiles[x][y].clear();
        return true;
    }
    
    return false;
}
void grid::removeApplication(int x, int y){
    if (tiles[x][y].getIsOccupied() == true){
        tiles[x][y].clear();
    }
}