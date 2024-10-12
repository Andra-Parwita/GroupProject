#include "application.h"


application::application() : health(0), cost(0), id(99), isAlive(false){Desc = "Default App";}
application::application(int health, int cost, int id) : health(health), cost(cost), id(id), isAlive(true){Desc = "Default App";}
application::~application(){}

//setters
void application::setId(int id){this->id = id;}
void application::setHealth(int health){this->health = health;}
void application::setCost(int price){this->cost = price;}
void application::setStatus(bool status){this->isAlive = status;}
void application::setAppPosition(sf::Vector2f pos) {
    //std::cout << "set pos at: " << pos.x << " " << pos.y << std::endl;
    this->AppPosition = pos;}
void application::setDmg(int dmg){this->dmg = dmg;}

//accessors
int application::getId(){return this->id;}
int application::getHealth(){return this->health;}
int application::getCost(){return this->cost;}
bool application::checkAlive(){return this->isAlive;}
int application::getDmg(){return this->dmg;}
sf::Vector2f application::getAppPosition(){return this->AppPosition;}
std::string application::getDesc(){return Desc;}

//std function
std::vector<sf::CircleShape>* application::update(sf::FloatRect pos){
    std::cout << "default application update" << std::endl;
    return proj;
}
