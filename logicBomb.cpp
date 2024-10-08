#include "logicBomb.h"

// Constructor
logicBomb::logicBomb(int health, float tileTime, int id, int dmg)
    : virus(75, 1.0, 0, 10) {}

logicBomb::logicBomb() : virus(75, 1.0, 0, 10) {}

void explode();