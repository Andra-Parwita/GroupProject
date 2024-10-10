#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp> 
#include <iostream>
#include "grid.h"
#include "gameController.h"
#include <string>
#include "virus.h"

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

    //mapdata
    grid* gridMap; //actual map data

    //fonts and text
    sf::Font font; 
    sf::Text timerText;
    sf::Text resourceText;

    //gameController
    gameController* gameManager;
    int currentSelectionId;

    //virus handler
    virus** virusManager;
    sf::RectangleShape* virusSprites;
    int maxVirusSpritesSpace;

    //clock
    sf::Clock clock;
    int fiveSec;
    sf::Clock bugSpawner;

    //init functions
    void initVariables(); //initalises variables
    void initWindow(); //starts the window
    void initMap();
    void initBar();
    void initText();
    void initVirus();

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
    void cleanUpDeadVirusesSprites();

    void spawnEnemy(int id);

    bool taskBarChecker(int i);
    bool gridMapChecker(int x, int y);


};

#endif