#include "game.h"
#include <iostream>
#include "grid.h"
#include <string>

//private functions
void Game::initVariables(){
    //window
    this->window = nullptr;

    //game controller
    gameManager = new gameController;
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

void Game::initText(){
    //text
    if (!font.loadFromFile("./Sprites/segoeui.ttf")){
        std::cout << "Font not loaded!" << std::endl;
    }
    timerText.setFont(font);
    timerText.setCharacterSize(30);
    timerText.setPosition(sf::Vector2f(10.0f,10.0f));
    timerText.setFillColor(sf::Color::Cyan);

    resourceText.setFont(font);
    resourceText.setCharacterSize(30);
    resourceText.setPosition(sf::Vector2f(410.0f,10.0f));
    resourceText.setFillColor(sf::Color::Cyan);
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
    
    taskBarSprites = new sf::RectangleShape[6];
    for (int i=0; i< 6; i++){
        taskBarSprites[i].setSize(sf::Vector2f(50.f,50.f));
        taskBarSprites[i].setPosition(620+i*(88.f),60.f);
    }
    taskBarSprites[0].setFillColor(sf::Color::Blue);
    taskBarSprites[1].setFillColor(sf::Color::Cyan);
    taskBarSprites[2].setFillColor(sf::Color::Red);
    taskBarSprites[3].setFillColor(sf::Color::Green);
    taskBarSprites[4].setFillColor(sf::Color::Magenta);
    taskBarSprites[5].setFillColor(sf::Color::Transparent);
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

    appSpriteHolders = new sf::RectangleShape*[5];
    for (int i=0; i < 5; i++){
        appSpriteHolders[i] = new sf::RectangleShape[20];
    }
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 20; j++){
            appSpriteHolders[i][j].setSize(sf::Vector2f(50.f,50.f));
            appSpriteHolders[i][j].setPosition(j*(85.f)+30,i*(150.f)+250);
            appSpriteHolders[i][j].setFillColor(sf::Color::Transparent);
        }
    } 

    std::cout << "made sprite holders" << std::endl;
}

//constuctors and destructors
Game::Game() : currentSelectionId(0) {
    this->initVariables();
    this->initWindow();
    this->initMap();
    this->initBar();
    this->initText();
}
Game::~Game(){
    delete this->window;
    delete[] this->dispTiles;
    delete this->gridMap;
    delete[] this->appSpriteHolders;
    delete[] this->taskBarSprites;
    delete this->gameManager;
}

//Public Functions
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

void Game::pollEvents(){ //game ui inputs
    while (this->window->pollEvent(this->ev)){

        // windowclose
        if (this->ev.type == sf::Event::Closed){ //close window button
            this->window->close();
        }

        //mouse click 
        if (this->ev.type == sf::Event::MouseButtonPressed){
            std::cout << "button pressed" << std::endl;
            for (int i = 0; i < 6; i++){
                if (Game::taskBarChecker(i) == true){
                    currentSelectionId = i;
                    std::cout << "changed Id to " << currentSelectionId << std::endl;
                }
            }

            //placement
            for (int j = 0; j < 5; j++){
                for (int k = 0; k < 20; k++){
                    if(Game::gridMapChecker(j,k) == true){ //check if mouse is on current tile

                        std::cout << "Cost of: " << currentSelectionId << " is " << gameManager->costCheck(currentSelectionId) << std::endl;

                        if(gameManager->getResource() >= gameManager->costCheck(currentSelectionId)){ //gets cost of app
                            if((gridMap->checkOccupancy(j,k) == false) || (currentSelectionId == 5)){ //checks if remove tool or occupied
                                gameManager->addResource(-(gameManager->costCheck(currentSelectionId))); //takes currency
                                switch (currentSelectionId){
                                case 0:
                                    appSpriteHolders[j][k].setFillColor(sf::Color::Blue);
                                    break;
                                case 1:
                                    appSpriteHolders[j][k].setFillColor(sf::Color::Cyan);
                                    break;
                                case 2:
                                    appSpriteHolders[j][k].setFillColor(sf::Color::Red);
                                    break;
                                case 3:
                                    appSpriteHolders[j][k].setFillColor(sf::Color::Green);
                                    break;
                                case 4:
                                    appSpriteHolders[j][k].setFillColor(sf::Color::Magenta);
                                    break;
                                default:
                                    appSpriteHolders[j][k].setFillColor(sf::Color::Transparent);
                                    break;
                                }

                                gridMap->addApplication(j,k,currentSelectionId); //adds selection id to
                                std::cout << gridMap->checkOccupancy(j,k) << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::update(){ //game updates
    this->pollEvents(); //keyboard
    int currentProducers = 0;

    //checking tile types for production
    for (int i = 0; i<5; i++){
        for (int j =0; j<20; j++) {
            currentProducers = gridMap->checkNumOfTileIDs(0);
        }
    }


    if (clock.getElapsedTime().asSeconds() >= 1.0f){ //one second clock
        gameManager->addResource(1+ 1*currentProducers);
        clock.restart();
    }

    //mouse position updates
    // std::cout<<"Mouse pos:  " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;

    std::string currentTime = std::to_string(gameManager->elapsedTime());
    timerText.setString(currentTime);

    std::string currentResource = std::to_string(gameManager->getResource());
    resourceText.setString(currentResource + " Mb");

}

void Game::render(){ //renders the game objects

    this->window->clear(); //clearing frame


    //drawing objects
    for (int i = 0; i < 5; i ++){ //grid map display
        for (int j = 0; j < 20; j++){
            this->window->draw(this->dispTiles[i][j]);
        }
    } 

    for (int i = 0; i < 5; i ++){ //for application sprites
        for (int j = 0; j < 20; j++){
            this->window->draw(this->appSpriteHolders[i][j]);
        }
    } 

    for (int i=0; i< 6; i++){ //task bar
        this->window->draw(this->taskBar[i]);
    }

    for (int i=0; i<6; i++){ //task bar sprites
        this->window->draw(this->taskBarSprites[i]);
    }

    this->window->draw(this->timerText);
    this->window->draw(this->resourceText);

    this->window->display(); //displays frame
}