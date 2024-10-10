#include "tile.h"

//constuctors
tile::tile() : isOccupied(false){applicationType = new application;}
tile::~tile(){delete applicationType;}

//public functions
void tile::occupy(int appId, sf::Vector2f pos){ //add app ids and connect to new application creation
    switch (appId) {
        case 0:
            applicationType = new vscode();
            applicationType->setStatus(true);
            break;
        case 1:
            applicationType = new fileExplorer();
            applicationType->setStatus(true);
            break;
        case 2:
            applicationType = new antivirus(); 
            applicationType->setStatus(true);
            break;
        case 3:
            applicationType = new vpn(); 
            applicationType->setStatus(true);
            break;
        case 4:
            applicationType = new chrome(); 
            applicationType->setStatus(true);
            break;
        default:
        return;
    }
    applicationType->setAppPosition(pos);
    isOccupied = true;
}
void tile::clear(){delete applicationType; isOccupied = false; applicationType = new application;}

void tile::updateStatus(){
    if (applicationType->getId() != 99){ //checks if not placeholder application
        if ((applicationType->getHealth() <= 0)){
            tile::clear();
        }
    }
}

bool tile::checkAppStatus(){return applicationType->checkAlive();}
void tile::setAppHealth(int hp){applicationType->setHealth(hp);}
void tile::setAppPosition(sf::Vector2f pos){
    applicationType->setAppPosition(pos);
}
std::vector<sf::CircleShape> tile::update(){
    std::vector<sf::CircleShape> data = applicationType->update();
    return data;
}

bool tile::checkShootedCollisions(sf::FloatRect pos){
    bool data = applicationType->checkProjCollison(pos);
    return data;
}

//accessors
bool tile::getIsOccupied(){return isOccupied;}
application tile::getApplicationType(){return *applicationType;}
sf::Vector2f tile::getAppPosition(){return applicationType->getAppPosition();}