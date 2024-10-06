#include "game.h"
#include <iostream>
#include "grid.h"

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

void Game::initBar(){  //task bar
    taskBar = new sf::RectangleShape[6];
    for (int i=0; i< 6; i++){
        taskBar[i].setSize(sf::Vector2f(88.f,150.f));
        taskBar[i].setOutlineThickness(1.f);
        taskBar[i].setOutlineColor(sf::Color::Cyan);
        taskBar[i].setPosition(600+i*(88.f),10.f);
        taskBar[i].setFillColor(sf::Color::Transparent);
    }
}

void Game::initMap(){
    gridMap = new grid; //making mapdata

    dispTiles = new sf::RectangleShape*[5]; //making display tiles

    for (int i=0; i < 5; i++){
        dispTiles[i] = new sf::RectangleShape[20];
    }
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 20; j++){
            dispTiles[i][j].setSize(sf::Vector2f(85.f,150.f));
            dispTiles[i][j].setOutlineThickness(1.f);
            dispTiles[i][j].setOutlineColor(sf::Color::Cyan);
            dispTiles[i][j].setPosition(j*(85.f)+10,i*(150.f)+200);
            dispTiles[i][j].setFillColor(sf::Color::Transparent);
        }
    } 
    std::cout << "made map" << std::endl;
}

//constuctors and destructors
Game::Game() : currentSelectionId(0) {
    this->initVariables();
    this->initWindow();
    this->initMap();
    this->initBar();
}
Game::~Game(){
    delete this->window;
    delete this->dispTiles;
    delete this->gridMap;
}

bool Game::taskBarChecker(int i){
    if (taskBar[i].getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))){
        return true;
    } 
    return false;
}

bool Game::gridMapChecker(int x, int y){
    if (dispTiles[x][y].getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))){
        return true;
    } 
    return false;
}

//Public Functions
void Game::pollEvents(){ //game ui inputs
    while (this->window->pollEvent(this->ev)){
        if (this->ev.type == sf::Event::Closed){ //close window button
            this->window->close();
        }
        if (this->ev.type == sf::Event::MouseButtonPressed){
            std::cout << "button pressed" << std::endl;
            for (int i = 0; i < 6; i++){
                if (Game::taskBarChecker(i) == true){
                    currentSelectionId = i;
                    std::cout << "changed Id to " << currentSelectionId << std::endl;
                }
            }
            for (int j = 0; j < 5; j++){
                for (int k = 0; k < 20; k++){
                    if(Game::gridMapChecker(j,k) == true){
                        gridMap->addApplication(j,k,currentSelectionId); //adds selection id to 
                    }
                }
            }
        }
    }
}
void Game::update(){ //game updates
    this->pollEvents();

    //mouse position updates
    // std::cout<<"Mouse pos:  " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;

}
void Game::render(){ //renders the game objects

    this->window->clear(); //clearing frame

    //drawing objects
    for (int i = 0; i < 5; i ++){ //grid map display
        for (int j = 0; j < 20; j++){
            this->window->draw(this->dispTiles[i][j]);
        }
    } 

    for (int i=0; i< 6; i++){ //task bar
        this->window->draw(this->taskBar[i]);
    }

    this->window->display(); //displays frame
}