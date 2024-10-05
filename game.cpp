#include "game.h"
#include <iostream>

//private functions
void Game::initVariables(){
    //window
    this->window = nullptr;
}

void Game::initWindow(){ //creates the window
    this->videoMode.height = 1000;
    this->videoMode.width = 2000;
    this->window = new sf::RenderWindow(this->videoMode, "Firewall");
    this->window->setFramerateLimit(60);
}

const bool Game::getWindowIsOpen() const{ //checks if window is open
    return this->window->isOpen();
}

void Game::initMap(){
    float position_x = 0;
    float position_y = 0;

    dispTiles = new sf::RectangleShape*[5];
    for (int i=0; i < 5; i++){
        dispTiles[i] = new sf::RectangleShape[20];
    }
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 20; j++){
            dispTiles[i][j].setSize(sf::Vector2f(88.f,150.f));
            dispTiles[i][j].setOutlineThickness(1.f);
            dispTiles[i][j].setOutlineColor(sf::Color::Cyan);
            dispTiles[i][j].setPosition(j*(88.f),i*(150.f)+200);
            dispTiles[i][j].setFillColor(sf::Color::Transparent);
        }
    } 
    std::cout << "made map" << std::endl;
}

//constuctors and destructors
Game::Game(){
    this->initVariables();
    this->initWindow();
    this->initMap();
}
Game::~Game(){
    delete this->window;
    delete this->dispTiles;
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

    //mouse position updates
    std::cout<<"Mouse pos:  " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;

}
void Game::render(){ //renders the game objects

    this->window->clear(); //clearing frame

    //drawing objects
    for (int i = 0; i < 5; i ++){
        for (int j = 0; j < 20; j++){
            this->window->draw(this->dispTiles[i][j]);
        }
    } 
    this->window->display(); //displays frame
}