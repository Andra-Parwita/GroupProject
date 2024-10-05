#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp> 

class Game
{
private:
    //Variables
    sf::RenderWindow* window; //window
    sf::VideoMode videoMode; //window size params
    sf::Event ev; //gets curent input events on the window (continuous)

    //gameObject
    sf::RectangleShape** dispTiles;

    //init functions
    void initVariables(); //initalises variables
    void initWindow(); //starts the window
    void initMap();
public:
    //constuctors and destructors
    Game();
    ~Game();

    //accessor
    const bool getWindowIsOpen() const;

    //Functions
    void pollEvents();
    void update();
    void render();

};

#endif