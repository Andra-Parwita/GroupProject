#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <SFML/Graphics.hpp> 

#include <chrono>
#include <thread>

#include "application.h"
#include "fileExplorer.h"
#include "vscode.h"
#include "vpn.h"
#include "antivirus.h"
#include "chrome.h"

class gameController
{
private:
    int resource;
    std::chrono::high_resolution_clock::time_point timeStart;

    //init functions
    void startTimer();

    application* costChecker;
public:
    //constructors
    gameController();
    ~gameController();

    //public functions
    void addResource(int amount);
    int getResource();
    int costCheck(int Id);

    float elapsedTime() const;

    void spawnVirus();
};


#endif