#include "trojan.h"

// Constructor
trojan::trojan(int health, float tileTime, int id, int dmg)
    : virus(75, 2.0, 2, 10) {
    this->isAlive = true;}

trojan::trojan() : virus(75, 2.0, 2, 10) {
    this->isAlive = true;
}

trojan::~trojan(){};