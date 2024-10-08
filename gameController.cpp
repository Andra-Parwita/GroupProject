#include "gameController.h"

//constuctors
gameController::gameController() : resource(5){
    gameController::startTimer();
    virusCounter = 0;
}

gameController::~gameController(){
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

virus** gameController::spawnVirus(virus** virusManager, int virusId){
    if (gameController::elapsedTime() >= 10){
        srand(time(NULL)); //seed for random
        int rowSpawn = rand()%5;

        //extends old array by 1
        int oldSize = virusCounter;
        virusCounter++;
        std::cout << "old:" << oldSize << "new:" << virusCounter << std::endl;

        virus** temp = new virus*[virusCounter];
        std::cout << "made new temp virus Manager" << std::endl;

        std::copy(virusManager, virusManager + oldSize, temp);
        std::cout << "copied Virus Manager" << std::endl;

        delete[] virusManager; 
        std::cout << "deleted old Virus Manager" << std::endl;


        /* checking ids
        switch (virusId)
        {
        case 0:
            temp[oldSize] = new bug;
            temp[oldSize]->setRow(rowSpawn);
            std::cout << "bug spawned" << std::endl;
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        } */

       virusManager = temp; 
        std::cout << "made Virus Manager to temp" << std::endl;
    }
    return virusManager;
}

