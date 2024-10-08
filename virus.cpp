#include "virus.h"

virus::virus() : health(0), tileTime(0), id(99), dmg(0) {}
virus::virus(int health, float tileTime, int id, int dmg)
    : health(health), tileTime(tileTime), id(id), dmg(dmg) {}
virus::~virus() {}

// setters
void virus::setId(int id) { this->id = id; }
void virus::setHealth(int health) { this->health = health; }
void virus::setTileTime(float tileTime) { this->tileTime = tileTime; }
void virus::setDmg(int dmg) { this->dmg = dmg; }
void virus::setStatus(bool status) { this->isAlive = status; }

// accessors
int virus::getId() { return this->id; }
int virus::getHealth() { return this->health; }
int virus::getTileTime() { return this->tileTime; }
int virus::getDmg() { return this->dmg; }
bool virus::checkAlive() { return this->isAlive; }
