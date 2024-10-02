#include "game.h"

//private functions
void Game::initVariables(){
    this->window = nullptr;
    this->videoMode.height = 800;
    this->videoMode.width = 1800;
}

void Game::initWindow(){ //creates the window
    this->window = new sf::RenderWindow(this->videoMode, "Firewall");
}

const bool Game::getWindowIsOpen() const{ //checks if window is open
    return this->window->isOpen();
}

//constuctors and destructors
Game::Game(){
    this->initVariables();
    this->initWindow();
}
Game::~Game(){
    delete this->window;
}

//Public Functions
void Game::pollEvents(){ //game ui inputs
    while (this->window->pollEvent(this->ev)){
        if (this->ev.type == sf::Event::Closed){ //close window button
            this->window->close();
        }
    }
}
void Game::update(){ //game updates
    this->pollEvents();

}
void Game::render(){ //renders the game objects
    this->window->clear(); //clearing frame

    //drawing objects

    this->window->display(); //displays frame
}