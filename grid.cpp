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

void grid::checkAppsStatus(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 20; j++){
            tiles[i][j].updateStatus();
        }
    }
}

bool grid::checkOccupancy(int x, int y){return tiles[x][y].getIsOccupied();}

int grid::checkNumOfTileIDs(int wantedId){
    int total = 0;
    for (int i =0; i < 5; i++){
        for(int j = 0; j < 20; j++){
            int current = tiles[i][j].getApplicationType().getId();
            if (current == wantedId){
                total += 1;
            }
        }
    }
    return total;
}

bool grid::takeAppDamage(int x, int y, int dmgTaken){
    if ((tiles[x][y].getIsOccupied() == true) && (tiles[x][y].checkAppStatus() == true) && (tiles[x][y].getApplicationType().getHealth() > 0)){
        int currentHP = tiles[x][y].getApplicationType().getHealth();
        int newHP = currentHP - dmgTaken;
        tiles[x][y].setAppHealth(newHP);
        std::cout << "App health is now: " << tiles[x][y].getApplicationType().getHealth() << std::endl;
        return true;
    }
    return false;
}
 