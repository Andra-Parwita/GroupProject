#include "gameController.h"

//constuctors
gameController::gameController() : resource(10){
    gameController::startTimer();
    virusCounter = 0;
    maxVirusSpace = 10;
    bugSpawnTime = 10;
    spawnerClock = new sf::Clock[5];
}

gameController::~gameController(){
    delete[] spawnerClock;
}

//private function
void gameController::startTimer() {
    timeStart = std::chrono::high_resolution_clock::now();
}

//public functions
float gameController::elapsedTime() const {
    std::chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<float>(timeEnd - timeStart).count();
}

int gameController::costCheck(int Id){
    int totalCost = 0;
    switch (Id){
    case 0:
        costChecker = new vscode();
        totalCost = costChecker->getCost();
        break;
    case 1:
        costChecker = new fileExplorer();
        totalCost = costChecker->getCost();
        break;
    case 2:
        costChecker = new antivirus();
        totalCost = costChecker->getCost();
        break;
    case 3:
        costChecker = new vpn();
        totalCost = costChecker->getCost();
        break;
    case 4:
        costChecker = new chrome();
        totalCost = costChecker->getCost();
        break;
    default:
        break;
    }
    return totalCost;
}

void gameController::addResource(int amount){
    this->resource += amount;
}

int gameController::getResource(){return resource;}

int gameController::getVirusCount(){return virusCounter;}

//spawners
float gameController::bugSpawnTimeCheck(){
    if (gameController::elapsedTime() <= 60){
        bugSpawnTime = 15;
    } else if ((gameController::elapsedTime() > 60) && (gameController::elapsedTime() <= 200)){
        bugSpawnTime = 10;
    } else if ((gameController::elapsedTime() > 60) && (gameController::elapsedTime() <= 500)){
        bugSpawnTime = 5;
    }
    return bugSpawnTime;
}

bool gameController::canSpawnBug(){
    if (spawnerClock[0].getElapsedTime().asSeconds() >= gameController::bugSpawnTimeCheck()){
        spawnerClock[0].restart();
        return true;
    } 
    return false;
}

float gameController::trojanSpawnTimeCheck(){
    if (gameController::elapsedTime() <= 300){
        trojanSpawnTime = 25;
    } else if ((gameController::elapsedTime() > 60) && (gameController::elapsedTime() <= 500)){
        trojanSpawnTime = 18;
    } else if ((gameController::elapsedTime() > 60) && (gameController::elapsedTime() <= 600)){
        trojanSpawnTime = 10;
    }
    return trojanSpawnTime;
}

bool gameController::canSpawnTrojan(){
    if (spawnerClock[2].getElapsedTime().asSeconds() >= gameController::trojanSpawnTimeCheck()){
        spawnerClock[2].restart();
        return true;
    } 
    return false;
}

virus** gameController::spawnVirus(virus** virusManager, int virusId, int rowId){
    if (gameController::elapsedTime() >= 10){
        virusCounter++;
        std::cout << "increased number of viruses by 1, Current: " << virusCounter << std::endl;

        //extends old array by 5
        if (virusCounter >= maxVirusSpace){
            std::cout << "checked size" << std::endl;
            int oldSize = maxVirusSpace;
            int newSize = maxVirusSpace + 10;
            std::cout << "old:" << oldSize << " new:" << newSize << std::endl;

            virus** temp = new virus*[newSize];
            std::cout << "made new temp virus Manager" << std::endl;

            if (virusManager != nullptr){
                std::copy(virusManager, virusManager + oldSize, temp);
                std::cout << "copied Virus Manager" << std::endl;

                delete[] virusManager; 
                std::cout << "deleted old Virus Manager" << std::endl;
            }

            virusManager = temp; 
            maxVirusSpace = newSize;
            std::cout << "made Virus Manager to temp" << std::endl;
        }
    
        //checking ids
        switch (virusId)
        {
        case 0:
            virusManager[virusCounter-1] = new bug;
            virusManager[virusCounter-1]->setRow(rowId);
            std::cout << "bug spawned" << std::endl;
            break;
        case 1:
            break;
        case 2:
            virusManager[virusCounter-1] = new trojan;
            virusManager[virusCounter-1]->setRow(rowId);
            std::cout << "trojan spawned" << std::endl;
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        } 
       std::cout << "finished Internal Spawning" << std::endl;

    }
    return virusManager;
}

//virus interactions
