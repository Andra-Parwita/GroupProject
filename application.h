#ifndef GAME_H
#define GAME_H

class application
{
private:
    //variables
    int cost;
    int health;
    bool isAlive;

public:
    //constructors
    application();
    application(int health, int cost);
    ~application();
};

#endif