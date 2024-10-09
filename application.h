#ifndef APPLICATION_H
#define APPLICATION_H
#include <SFML/Graphics.hpp>
#include <iostream>

class application
{
protected:
    //variables
    int id;
    int cost;
    int health;
    bool isAlive;
    sf::Vector2f AppPosition;

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

    //accessors
    int getId();
    int getHealth();
    int getCost();
    bool checkAlive();
    sf::Vector2f getAppPosition();

    //actions
    virtual std::vector<sf::CircleShape>  update();
};

#endif