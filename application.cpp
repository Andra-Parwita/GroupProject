#include "application.h"

application::application() : health(1), cost(0), id(0){}
application::application(int health, int cost, int id) : health(health), cost(cost), id(id){}
application::~application(){}

//setters
void application::setId(int id){this->id = id;}
void application::setHealth(int health){this->health = health;}
void application::setCost(int price){this->cost = price;}
void application::setStatus(bool status){this->isAlive = status;}

//accessors
int application::getId(){return this->id;}
int application::getHealth(){return this->health;}
int application::getCost(){return this->cost;}
bool application::checkAlive(){return this->isAlive;}