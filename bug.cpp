#include "bug.h"

// Constructor
bug::bug(int health, float tileTime, int id, int dmg)
    : virus(100, 3.0, 0, 15) {
        this->isAlive = true;
    }

bug::bug() : virus(100, 3.0, 0, 15) {
    this->isAlive = true;
}  

bug::~bug(){};