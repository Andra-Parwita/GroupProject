#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <SFML/Graphics.hpp> 
#include <iostream>

#include <chrono>
#include <thread>
#include <string.h>

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
#include "logicBomb.h"
#include "iloveyou.h"

class gameController
{
private:
    int resource;
    std::chrono::high_resolution_clock::time_point timeStart;
    application* costChecker;
    application* dmgChecker;
    application* descChecker;

    //init functions
    void startTimer();

    //counters
    int virusCounter;
    int maxVirusSpace;

    int bugSpawnTime;
    int trojanSpawnTime;
    int wormSpawnTime;
    int logicBombSpawnTime;
    int iloveyouSpawnTime;

    sf::Clock* spawnerClock;
    sf::Clock* appCooldownClocks;
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
    bool appCooldownCheck(int Id, bool freed);
    std::string getAppDesc(int Id);

    float elapsedTime() const;
    
    //spawning functions
    float bugSpawnTimeCheck();
    bool canSpawnBug();

    float trojanSpawnTimeCheck();
    bool canSpawnTrojan();

    float wormSpawnTimeCheck();
    bool canSpawnWorm();

    float logicBombSpawnTimeCheck();
    bool canSpawnLogicBomb();

    float iloveyouTimeCheck();
    bool canSpawnIloveyou();


    virus** spawnVirus(virus** virusManager, int virusId, int rowId);
    
    //cleaning
    virus** cleanUpDeadViruses(virus** virusManager);
};


#endif