#include "virus.h"

virus::virus() : health(1), speed(1), id(0) {}
virus::virus(int health, int speed, int id)
    : health(health), speed(speed), id(id) {}
virus::~virus() {}

// setters
void virus::setId(int id) { this->id = id; }
void virus::setHealth(int health) { this->health = health; }
void virus::setSpeed(int price) { this->speed = price; }
void virus::setStatus(bool status) { this->isAlive = status; }

// accessors
int virus::getId() { return this->id; }
int virus::getHealth() { return this->health; }
int virus::getSpeed() { return this->speed; }
bool virus::checkAlive() { return this->isAlive; }
