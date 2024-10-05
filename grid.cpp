#include "tile.h"
#include "grid.h"

//constructors
grid::grid(){
    int i,j;
    for (i = 0;i<5;i++){ //setting tiles as empty
        for (j=0;i<20;j++){
            map[i][j] =0;
        }
    }

}

grid::~grid(){delete tiles;}

int grid::getMapSize(){return map[5][20];};
void grid::addApplication(int x, int y){}
void grid::removeApplication(){}
