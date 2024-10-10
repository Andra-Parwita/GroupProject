#include "gameController.h"

//constuctors
gameController::gameController() : resource(100){
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

int gameController::costCheck(int id){
    int totalCost = 0;
    switch (id){
    case 0:
        this->costChecker = new vscode();
        break;
    case 1:
        this->costChecker = new fileExplorer();
        break;
    case 2:
        this->costChecker = new antivirus();
        break;
    case 3:
        this->costChecker = new vpn();
        break;
    case 4:
        this->costChecker = new chrome();
        break;
    default:
        break;
    }
    totalCost = costChecker->getCost();
    return totalCost;
}


int gameController::appDmgCheck(int id){
    int dmg = 0;
    switch (id){
    case 0:
        this->dmgChecker = new vscode();
        break;
    case 1:
        this->dmgChecker = new fileExplorer();
        break;
    case 2:
        this->dmgChecker = new antivirus();
        break;
    case 3:
        this->dmgChecker = new vpn();
        break;
    case 4:
        this->dmgChecker = new chrome();
        break;
    default:
        break;
    }
    dmg = dmgChecker->getDmg();
    return dmg;
}

void gameController::addResource(int amount){
    this->resource += amount;
}

int gameController::getResource(){return resource;}

int gameController::getVirusCount(){return virusCounter;}

//spawners
float gameController::bugSpawnTimeCheck(){
    if (gameController::elapsedTime() <= 60){
        this->bugSpawnTime = 20;
    } else if ((gameController::elapsedTime() > 60) && (gameController::elapsedTime() <= 200)){
        this->bugSpawnTime = 10;
    } else if ((gameController::elapsedTime() > 60) && (gameController::elapsedTime() <= 500)){
        this->bugSpawnTime = 5;
    }
    return this->bugSpawnTime;
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
        this->trojanSpawnTime = 25;
    } else if ((gameController::elapsedTime() > 60) && (gameController::elapsedTime() <= 500)){
        this->trojanSpawnTime = 18;
    } else if ((gameController::elapsedTime() > 60) && (gameController::elapsedTime() <= 600)){
        this->trojanSpawnTime = 10;
    }
    return this->trojanSpawnTime;
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
        this->virusCounter++;
        std::cout << "increased number of viruses by 1, Current: " << virusCounter << std::endl;

        //extends old array by 5
        if (virusCounter >= maxVirusSpace){
            std::cout << "checked size" << std::endl;
            int oldSize = maxVirusSpace;
            int newSize = maxVirusSpace*2;
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
            this->maxVirusSpace = newSize;
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

virus** gameController::cleanUpDeadViruses(virus** virusManager){
    int newCount = 0;
    for (int i = 0; i < virusCounter; i++) {
        if (virusManager[i]->checkAlive() == false) {
            // Delete the dead enemy object to free its memory
            delete virusManager[i];
        } else {
            // Move the pointer of the living enemy to the new position
            virusManager[newCount++] = virusManager[i];
        }
    }

    // Now set all remaining pointers to nullptr to avoid dangling pointers
    for (int i = newCount; i < virusCounter; i++) {
        virusManager[i] = nullptr;
    }

    // Update the enemy count
    virusCounter = newCount;
    return virusManager;
}