#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp> 
#include "application.h"

class tile
{
private:
    bool isOccupied;
    application* applicationType;
public:
    //constructors
    tile();
    ~tile();

    //public functions
    void occupy(int appId);
    void clear();

    //accessor
    bool getIsOccupied();
    application getApplicationType();
};

#endif