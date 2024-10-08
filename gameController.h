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

class gameController
{
private:
    int resource;
    std::chrono::high_resolution_clock::time_point timeStart;
    application* costChecker;

    //init functions
    void startTimer();
    int virusCounter;

public:
    //constructors
    gameController();
    ~gameController();

    //public functions
    void addResource(int amount);
    int getResource();
    int getVirusCount();
    int costCheck(int Id);

    float elapsedTime() const;

    virus** spawnVirus(virus** virusManager, int VirusId);
};


#endif