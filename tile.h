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
    void occupy(int appId);
    void clear();
    bool checkAppStatus();
    void updateStatus();

    //accessor
    bool getIsOccupied();
    application getApplicationType();
    void setAppHealth(int hp);

};

#endif