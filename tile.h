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
    bool checkAppStatus();

    //accessor
    bool getIsOccupied();
    application getApplicationType();
};

#endif