#include <SFML/Graphics.hpp> ///opt/homebrew/Cellar/sfml/2.6.1 (g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system)
#include "game.h"

int main(){
    Game game; //creates a game

    while(game.getWindowIsOpen()){
        game.render();
        game.update();
    }
    return 0;
}