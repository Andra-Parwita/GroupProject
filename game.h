#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp> 
#include <iostream>
#include "grid.h"
#include "gameController.h"
#include <string>

class Game
{
private:
    //Variables
    sf::RenderWindow* window; //window
    sf::VideoMode videoMode; //window size params
    sf::Event ev; //gets curent input events on the window (continuous)

    //gameObject
    sf::RectangleShape** dispTiles;
    sf::RectangleShape** appSpriteHolders;

    sf::RectangleShape* taskBar;
    sf::RectangleShape* taskBarSprites;
    grid* gridMap; //actual map data
    int currentSelectionId;

    //fonts and text
    sf::Font font; 
    sf::Text timerText;
    sf::Text resourceText;

    //gameController
    gameController* gameManager;

    //clock
    sf::Clock clock;

    //init functions
    void initVariables(); //initalises variables
    void initWindow(); //starts the window
    void initMap();
    void initBar();
    void initText();

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

    bool taskBarChecker(int i);
    bool gridMapChecker(int x, int y);

};

#endif