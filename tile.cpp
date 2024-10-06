#include "tile.h"

//constuctors
tile::tile() : isOccupied(false){applicationType = new application;}
tile::~tile(){delete applicationType;}

//public functions
void tile::occupy(int appId){ //add app ids and connect to new application creation
    switch (appId) {
        case 0:
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
        return;
    }
    isOccupied = true;
}
void tile::clear(){delete applicationType; isOccupied = false; applicationType = new application;}

bool tile::checkAppStatus(){return applicationType->checkAlive();}

//accessors
bool tile::getIsOccupied(){return isOccupied;}
application tile::getApplicationType(){return *applicationType;}