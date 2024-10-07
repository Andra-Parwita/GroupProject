#include <SFML/Graphics.hpp> // g++ main.cpp game.cpp grid.cpp tile.cpp application.cpp fileExplorer.cpp vpn.cpp vscode.cpp antivirus.cpp  -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
#include "game.h"
#include <iostream>

int main(){
    Game game; //creates a game

    while(game.getWindowIsOpen()){
        game.render();
        game.update();
    }
    std::cout << "code finished" << std::endl;
    return 0;
}