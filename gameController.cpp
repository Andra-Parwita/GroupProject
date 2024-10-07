#include "gameController.h"

//constuctors
gameController::gameController() : resource(5){
    gameController::startTimer();
}

gameController::~gameController(){}

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

void gameController::spawnVirus(){}