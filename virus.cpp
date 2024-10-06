#include "virus.h"

virus::virus() : health(1), tileTime(2), id(0) {}
virus::virus(int health, float tileTime, int id)
    : health(health), tileTime(tileTime), id(id) {}
virus::~virus() {}

// setters
void virus::setId(int id) { this->id = id; }
void virus::setHealth(int health) { this->health = health; }
void virus::setTileTime(float tileTime) { this->tileTime = tileTime; }
void virus::setStatus(bool status) { this->isAlive = status; }

// accessors
int virus::getId() { return this->id; }
int virus::getHealth() { return this->health; }
int virus::getTileTime() { return this->tileTime; }
bool virus::checkAlive() { return this->isAlive; }
