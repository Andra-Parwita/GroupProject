#ifndef SHOOTER_H
#define SHOOTER_H

#include "application.h"

class shooter : public application
{
public:;
    shooter();
    ~shooter();
    virtual std::vector<sf::CircleShape>* update(sf::FloatRect pos) = 0; //virtual
};

#endif