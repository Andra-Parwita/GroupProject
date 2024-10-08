#include "bug.h"

// Constructor
bug::bug(int health, float tileTime, int id, int dmg)
    : virus(100, 2.0, 0, 15) {}

bug::bug() : virus(100, 2.0, 0, 15) {}