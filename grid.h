#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp> 
#include "tile.h"

class grid
{
private:
    int map[5][20]; //map size
    tile* tiles; //tile data

public:
    //constructors
    grid();
    ~grid();

    void addApplication(int x, int y);
    void removeApplication();
};



#endif