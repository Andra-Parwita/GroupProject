#ifndef APPLICATION_H
#define APPLICATION_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "virus.h"
#include <string.h>

class application //parent class for placed unit applications
{
protected:
    //variables
    int id; 
    int cost;
    int health;
    bool isAlive;
    int dmg;
    sf::Vector2f AppPosition; //position of the app (should be linked with app sprite)
    std::vector<sf::CircleShape>* proj; //projectiles, should be only used by shooter class or chrome (explosive)
    std::string Desc; //descruption string

public:
    //constructors
    application();
    application(int health, int cost, int id);
    virtual ~application();

    //setters
    void setId(int id);
    void setHealth(int health);
    void setCost(int cost);
    void setStatus(bool status);
    void setAppPosition(sf::Vector2f position);
    void setDmg(int dmg);

    //accessors
    int getId();
    int getHealth();
    int getCost();
    int getDmg();
    bool checkAlive();
    sf::Vector2f getAppPosition();
    virtual std::string getDesc();

    //actions
    virtual std::vector<sf::CircleShape>* update(sf::FloatRect pos); //what the class should do, eg their specialised function
};

#endif