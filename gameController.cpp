#include "gameController.h"

//constuctors
gameController::gameController() : resource(100){
    gameController::startTimer();
    virusCounter = 0;
    maxVirusSpace = 100;
    bugSpawnTime = 10;
    spawnerClock = new sf::Clock[5];
    appCooldownClocks = new sf::Clock[5];
}

gameController::~gameController(){
    delete spawnerClock;
    delete appCooldownClocks;
    delete costChecker;
    delete dmgChecker;
}

//private function
void gameController::startTimer() {
    timeStart = std::chrono::high_resolution_clock::now();
}

//public functions
float gameController::elapsedTime() const {
    std::chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();
    return (std::chrono::duration<float>(timeEnd - timeStart).count());
}

bool gameController::appCooldownCheck(int id, bool freed){
	switch (id) {
	case 0: //Vs Code cooldown
		if (appCooldownClocks[id].getElapsedTime().asSeconds() >= 2.0f){	
            if (freed == true){
                appCooldownClocks[id].restart();
            }
			return true;
		} else {
			//std::cout << "on cooldown!" << std::endl;
		}
		break;
	case 1: //File Explorer cooldown
		if (appCooldownClocks[id].getElapsedTime().asSeconds() >= 3.0f){	
			if (freed == true){
                appCooldownClocks[id].restart();
            }
			return true;
		} else {
			//std::cout << "on cooldown!" << std::endl;
		}
		break;
	case 2: //FireWall cooldown
		if (appCooldownClocks[id].getElapsedTime().asSeconds() >= 5.0f){	
			if (freed == true){
                appCooldownClocks[id].restart();
            }
			return true;
		} else {
			//std::cout << "on cooldown!" << std::endl;
		}
		break;
	case 3: //VPN cooldown
		if (appCooldownClocks[id].getElapsedTime().asSeconds() >= 3.0f){	
			if (freed == true){
                appCooldownClocks[id].restart();
            }
			return true;
		} else {
			//std::cout << "on cooldown!" << std::endl;
		}
		break;
	case 4: //Chrome cooldown
		if (appCooldownClocks[id].getElapsedTime().asSeconds() >= 5.0f){	
			if (freed == true){
                appCooldownClocks[id].restart();
            }
			return true;
		} else {
			//std::cout << "on cooldown!" << std::endl;
		}
		break;
    case 5: //for remove tool
        return true;
        break;
	default:
		break;
	}
	return false;
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
    if (id == 5){
        totalCost = 0;
    }
    return totalCost;
}


std::string gameController::getAppDesc(int id){
    std::string desc = "";
    switch (id){
    case 0:
        this->descChecker = new vscode();
        break;
    case 1:
        this->descChecker = new fileExplorer();
        break;
    case 2:
        this->descChecker = new antivirus();
        break;
    case 3:
        this->descChecker = new vpn();
        break;
    case 4:
        this->descChecker = new chrome();
        break;
    default:
        break;
    }
    if (id == 5){
        desc = "Remove Tool \n Removes stuff you click on! \n No refunds!!";
    } else {
        desc = descChecker->getDesc();
    }
    return desc;
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
    std::cout << "outputted dmg is: " << dmg << std::endl;
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
    } else if ((gameController::elapsedTime() > 300) && (gameController::elapsedTime() <= 400)){
        this->bugSpawnTime = 10;
    } else if ((gameController::elapsedTime() > 400) && (gameController::elapsedTime() <= 600)){
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

float gameController::wormSpawnTimeCheck(){
    if (gameController::elapsedTime() <= 400){
        this->wormSpawnTime = 40;
    } else if ((gameController::elapsedTime() > 400) && (gameController::elapsedTime() <= 500)){
        this->wormSpawnTime = 30;
    } else if ((gameController::elapsedTime() > 500) && (gameController::elapsedTime() <= 600)){
        this->wormSpawnTime = 25;
    }
    return this->wormSpawnTime;
}

bool gameController::canSpawnWorm(){
    if (spawnerClock[1].getElapsedTime().asSeconds() >= gameController::wormSpawnTimeCheck()){
        spawnerClock[1].restart();
        return true;
    } 
    return false;
}

float gameController::trojanSpawnTimeCheck(){
    if (gameController::elapsedTime() <= 300){
        this->trojanSpawnTime = 21;
    } else if ((gameController::elapsedTime() > 300) && (gameController::elapsedTime() <= 500)){
        this->trojanSpawnTime = 15;
    } else if ((gameController::elapsedTime() > 500) && (gameController::elapsedTime() <= 600)){
        this->trojanSpawnTime = 8;
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


float gameController::logicBombSpawnTimeCheck(){
    if (gameController::elapsedTime() <= 500){
        this->logicBombSpawnTime = 30;
    } else if ((gameController::elapsedTime() > 500) && (gameController::elapsedTime() <= 600)){
        this->logicBombSpawnTime = 25;
    } else if ((gameController::elapsedTime() > 600) && (gameController::elapsedTime() <= 700)){
        this->logicBombSpawnTime = 15;
    }
    return this->logicBombSpawnTime;
}

bool gameController::canSpawnLogicBomb(){
    if (spawnerClock[3].getElapsedTime().asSeconds() >= gameController::logicBombSpawnTimeCheck()){
        spawnerClock[3].restart();
        return true;
    } 
    return false;
}

float gameController::iloveyouTimeCheck(){
    if (gameController::elapsedTime() <= 500){
        this->iloveyouSpawnTime = 25;
    } else if ((gameController::elapsedTime() > 500) && (gameController::elapsedTime() <= 600)){
        this->iloveyouSpawnTime = 18;
    } else if ((gameController::elapsedTime() > 600) && (gameController::elapsedTime() <= 700)){
        this->iloveyouSpawnTime = 10;
    }
    return this->iloveyouSpawnTime;
}

bool gameController::canSpawnIloveyou(){
    if (spawnerClock[4].getElapsedTime().asSeconds() >= gameController::iloveyouTimeCheck()){
        spawnerClock[4].restart();
        return true;
    } 
    return false;
}

virus** gameController::spawnVirus(virus** virusManager, int virusId, int rowId){
    if (gameController::elapsedTime() >= 10){
        this->virusCounter++;
        std::cout << "increased number of viruses by 1, Current: " << virusCounter << std::endl;

        //extends multiplies old array by 2
        if ((virusCounter + 2) >= maxVirusSpace){
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
            std::cout << "bug spawned on row: " << rowId << std::endl;
            break;
        case 1:
            if ((virusCounter+2) < maxVirusSpace){
                if (virusManager[virusCounter-1] == nullptr){
                    virusManager[virusCounter-1] = new worm;
                    virusManager[virusCounter-1]->setRow(rowId);
                    std::cout << "worm head spawned on row: " << rowId << std::endl;
                    virusCounter++;
                }

                if (virusManager[virusCounter-1] == nullptr){
                    virusManager[virusCounter-1] = new worm(1);
                    virusManager[virusCounter-1]->setRow(rowId);
                    virusManager[virusCounter-1]->setSegmentid(1);
                    std::cout << "worm middle spawned" << std::endl;
                    virusCounter++;
                }

                if (virusManager[virusCounter-1] == nullptr){
                    virusManager[virusCounter-1] = new worm(2);
                    virusManager[virusCounter-1]->setRow(rowId);
                    virusManager[virusCounter-1]->setSegmentid(2);
                    std::cout << "worm end spawned" << std::endl;
                }
            }
            break;
        case 2:
            virusManager[virusCounter-1] = new trojan;
            virusManager[virusCounter-1]->setRow(rowId);
            std::cout << "trojan spawned on row: " << rowId << std::endl;
            break;
        case 3:
            virusManager[virusCounter-1] = new logicBomb;
            virusManager[virusCounter-1]->setRow(rowId);
            std::cout << "logicBomb spawned on row: " << rowId << std::endl;
            break;
        case 4:
            virusManager[virusCounter-1] = new iloveyou;
            virusManager[virusCounter-1]->setRow(rowId);
            std::cout << "iloveyou spawned on row: " << rowId << std::endl;
            break;
        default:
            break;
        } 
       std::cout << "finished Internal Spawning" << std::endl;

    }
    return virusManager;
}

virus** gameController::cleanUpDeadViruses(virus** virusManager){
    /* int newCount = 0;
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
    virusCounter = newCount; */
    return virusManager;
}