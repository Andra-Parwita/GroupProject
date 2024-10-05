#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <SFML/Graphics.hpp> 

class gameController
{
private:
    int resource;
public:
    gameController();
    ~gameController();

    void addResource(int amount);
    int getResource();
};



#endif