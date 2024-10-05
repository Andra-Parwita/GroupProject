#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp> 
#include "application.h"

class tile
{
private:
    bool isOccupied;
    application applicationType;
public:
    //constructors
    tile();
    ~tile();

    //public functions
    bool occupy();
    bool clear();
};


#endif