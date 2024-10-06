#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp> 
#include "tile.h"

class grid
{
private:
    tile** tiles; //tile data
public:
    //constructors
    grid();
    ~grid();

    //functions
    bool addApplication(int x, int y, int appId);
    void removeApplication(int x, int y);

    //accessor
    bool checkOccupancy(int x, int y);
};


#endif