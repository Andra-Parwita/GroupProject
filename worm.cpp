#include "worm.h"

// Constructor
worm::worm(int health, float tileTime, int id, int dmg)
    : virus(50, 4.0, 0, 15) {}

worm::worm() : virus(50, 4.0, 0, 15) {}