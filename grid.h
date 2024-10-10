#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp> 
#include "tile.h"
#include "fileExplorer.h"
#include "virus.h"

class grid
{
private:
    tile** tiles; //tile data
    std::vector<sf::CircleShape>** projectileContainers;

public:
    //constructors
    grid();
    ~grid();

    //functions
    bool addApplication(int x, int y, int appId);
    void removeApplication(int x, int y);

    //accessor
    bool checkOccupancy(int x, int y);
    int checkNumOfTileIDs(int iD);
    void checkAppsStatus();
    int getNumShootingTiles();
    void getAppDamage(int id){};

    //functions
    std::vector<sf::CircleShape>** getProjectiles(sf::FloatRect pos);
    bool takeAppDamage(int x, int y, int dmgTaken);
};


#endif