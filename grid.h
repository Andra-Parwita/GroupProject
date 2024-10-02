#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp> 

class game
{
private:
    bool gameState;
    int time;
    sf::RenderWindow window;
public:
    game(sf::RenderWindow window);
    bool startGame();
    bool endGame();
    ~game();
};


#endif