#ifndef APPLICATION_H
#define APPLICATION_H

class application
{
protected:
    //variables
    int id;
    int cost;
    int health;
    bool isAlive;

public:
    //constructors
    application();
    application(int health, int cost, int id);
    ~application();

    //setters
    void setId(int id);
    void setHealth(int health);
    void setCost(int cost);
    void setStatus(bool status);

    //accessors
    int getId();
    int getHealth();
    int getCost();
    bool checkAlive();
};

#endif