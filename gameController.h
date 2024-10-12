#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <SFML/Graphics.hpp> 
#include <iostream>

#include <chrono>
#include <thread>

#include "application.h"
#include "fileExplorer.h"
#include "vscode.h"
#include "vpn.h"
#include "antivirus.h"
#include "chrome.h"

#include "virus.h"
#include "grid.h"
#include "bug.h"
#include "trojan.h"
#include "worm.h"

class gameController
{
private:
    int resource;
    std::chrono::high_resolution_clock::time_point timeStart;
    application* costChecker;
    application* dmgChecker;

    //init functions
    void startTimer();

    //counters
    int virusCounter;
    int maxVirusSpace;
    int bugSpawnTime;
    int trojanSpawnTime;
    int wormSpawnTime;

    sf::Clock* spawnerClock;
    sf::Clock* appCooldowns;
    sf::Clock wormSpawner;
public:
    //constructors
    gameController();
    ~gameController();

    //public functions
    void addResource(int amount);
    int getResource();
    int getVirusCount();
    int costCheck(int Id);
    int appDmgCheck(int Id);

    float elapsedTime() const;
    
    //spawning functions
    float bugSpawnTimeCheck();
    bool canSpawnBug();

    float trojanSpawnTimeCheck();
    bool canSpawnTrojan();

    float wormSpawnTimeCheck();
    bool canSpawnWorm();

    virus** spawnVirus(virus** virusManager, int virusId, int rowId);
    
    //cleaning
    virus** cleanUpDeadViruses(virus** virusManager);
};


#endif