#include "logicBomb.h"

// Constructor
logicBomb::logicBomb(int health, float tileTime, int id, int dmg)
    : virus(75, 1.0, 3, 10) {
        this->isAlive = true;
    }

logicBomb::logicBomb() : virus(75, 1.0, 3, 10) {
    this->isAlive = true;
}

void explode();
