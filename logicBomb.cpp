#include "logicBomb.h"

// Constructor
logicBomb::logicBomb(int health, float tileTime, int id, int dmg)
    : virus(50, 2.0, 3, 10) {
        this->isAlive = true;
        this->explosionCheck = false;
    }

logicBomb::logicBomb() : virus(50, 2.0, 3, 10) {
    this->isAlive = true;
    this->explosionCheck = false;
}

logicBomb::~logicBomb(){}

bool logicBomb::move() {
    if ((freeze == true) || (explosionCheck == true)) {
        // std::cout << internalExClock.getElapsedTime().asSeconds() << std::endl;
        if (internalExClock.getElapsedTime().asSeconds() >= 5.0f) {
            std::cout << "exploded" << std::endl;
            this->explosionCheck = true;

            if (internalExClock.getElapsedTime().asSeconds() >= 5.5f) {
                std::cout << "is dead" << std::endl;
                this->health = 0;
                this->setStatus(false);
                return false;
            }
        }
    } else if ((freeze == false) && (explosionCheck == false)) {  // Move only if not frozen or exploding
        internalExClock.restart();
        if (this->explosionCheck == false){
            if ((virus::checkAlive() == true) && (health > 0)) {
                if (internalClock.getElapsedTime().asSeconds() >= ((tileTime))) {
                    std::cout << "moved to: " << position_x - 85 << " at: " << internalClock.getElapsedTime().asSeconds()  << std::endl;
                    virus::setPosX(position_x - 85);
                    internalClock.restart();
                    return true;
                }
             }
        }
    }
    return false;
}

