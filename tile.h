#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp> 
#include "application.h"
#include "fileExplorer.h"
#include "vscode.h"
#include "vpn.h"
#include "antivirus.h"
#include "chrome.h"

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
    void occupy(int appId, sf::Vector2f pos);
    void clear();
    bool checkAppStatus();
    void updateStatus();
    sf::Vector2f getAppPosition();
    std::vector<sf::CircleShape> update();

    //accessor
    bool getIsOccupied();
    application getApplicationType();
    void setAppHealth(int hp);
    void setAppPosition(sf::Vector2f pos);

};

#endif