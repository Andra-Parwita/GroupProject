#include "worm.h"

// Constructor
worm::worm(int health, float tileTime, int id, int dmg)
    : virus(100, 4.5, 1, 15) {
        this->isAlive = true;
    }

worm::worm() : virus(100, 4.5, 1, 15) {
    this->isAlive = true;
}

worm::worm(int segId) : virus(100, 4.5, 1, 15){
    this->isAlive = true;
    this->worm::setSegmentid(segId);
}

worm::~worm(){}


bool worm::move(){
    switch (segmentId)
    {
    case 1:
        if (segmentClock.getElapsedTime().asSeconds() <= (tileTime*2)){
            freeze = true;
        }
        break;
    case 2:
        if (segmentClock.getElapsedTime().asSeconds() <= (tileTime*3)){
            freeze = true;
        }
        break;
    default:
        break;
    }

    if (freeze == false){
        if ((virus::checkAlive() == true) && (health > 0)){
            if(internalClock.getElapsedTime().asSeconds() >= ((tileTime)+((rand()%1000)/1000))){
                std::cout << "moved to: " << position_x -85 << "at: " << internalClock.getElapsedTime().asSeconds()  << std::endl;
                virus::setPosX(position_x -85);
                internalClock.restart(); 
                return true;
            }
        }
    } else if (freeze == true){
        return false;
    }
    return false;
}