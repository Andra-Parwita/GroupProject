#include "trojan.h"

// Constructor
trojan::trojan(int health, float tileTime, int id, int dmg)
    : virus(50, 1.0, 2, 20) {
    this->isAlive = true;}

trojan::trojan() : virus(50, 1.0, 2, 20) {
    this->isAlive = true;
}

trojan::~trojan(){};