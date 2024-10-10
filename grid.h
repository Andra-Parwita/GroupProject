#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp> 
#include "tile.h"
#include "fileExplorer.h"

class grid
{
private:
    tile** tiles; //tile data
    std::vector<sf::CircleShape>* projectileContainers;

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
    void checkForProjectileCollison(sf::FloatRect pos);

    //functions
    std::vector<sf::CircleShape>* getProjectiles();
    bool takeAppDamage(int x, int y, int dmgTaken);
};


#endif