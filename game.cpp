#include "game.h"

#include <iostream>
#include <string>

#include "grid.h"

// private functions
void Game::initVariables() {
  // window
  this->window = nullptr;
  fiveSec = 0;
  // game controller
  gameManager = new gameController;
  srand(time(NULL));  // seed for random, might change to another seed
  projected = new std::vector<sf::CircleShape>*[100];
  projectileCount = 0;
  slowed = new std::vector<sf::CircleShape>*[100];
  slowCount = 0;
  explosions = new std::vector<sf::CircleShape>*[100];
  explosionCount = 0;
}

void Game::initWindow() {  // creates the window
  this->videoMode.height = 1000;
  this->videoMode.width = 2000;
  this->window = new sf::RenderWindow(this->videoMode, "Firewall");
  this->window->setFramerateLimit(60);
}

const bool Game::getWindowIsOpen() const {  // checks if window is open
  return this->window->isOpen();
}

void Game::initText() {
  // text
  if (!font.loadFromFile("./Sprites/segoeui.ttf")) {
    std::cout << "Font not loaded!" << std::endl;
  }
  timerText.setFont(font);
  timerText.setCharacterSize(30);
  timerText.setPosition(sf::Vector2f(10.0f, 10.0f));
  timerText.setFillColor(sf::Color::Cyan);

  resourceText.setFont(font);
  resourceText.setCharacterSize(30);
  resourceText.setPosition(sf::Vector2f(410.0f, 10.0f));
  resourceText.setFillColor(sf::Color::Cyan);

  PopDisplayText.setFont(font);
  PopDisplayText.setString("");
  PopDisplayText.setCharacterSize(16);
  resourceText.setPosition(sf::Vector2f(200.0f, 10.0f));
  PopDisplayText.setFillColor(sf::Color::Cyan);
}

void Game::initBar() {  // task bar
  taskBar = new sf::RectangleShape[6];
  for (int i = 0; i < 6; i++) {
    taskBar[i].setSize(sf::Vector2f(88.f, 150.f));
    taskBar[i].setOutlineThickness(1.f);
    taskBar[i].setOutlineColor(sf::Color::Cyan);
    taskBar[i].setPosition(600 + i * (88.f), 10.f);
    taskBar[i].setFillColor(sf::Color::Transparent);
  }

  taskBarSprites = new sf::RectangleShape[6];
  for (int i = 0; i < 6; i++) {
    taskBarSprites[i].setSize(sf::Vector2f(50.f, 50.f));
    taskBarSprites[i].setPosition(620 + i * (88.f), 60.f);
  }
  taskBarSprites[0].setFillColor(sf::Color::Blue);
  taskBarSprites[1].setFillColor(sf::Color::Cyan);
  taskBarSprites[2].setFillColor(sf::Color::Red);
  taskBarSprites[3].setFillColor(sf::Color::Green);
  taskBarSprites[4].setFillColor(sf::Color::Magenta);
  taskBarSprites[5].setFillColor(sf::Color::Transparent);
}

void Game::initMap() {
  gridMap = new grid;  // making mapdata

  dispTiles = new sf::RectangleShape*[5];  // making display tiles

  for (int i = 0; i < 5; i++) {
    dispTiles[i] = new sf::RectangleShape[20];
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      dispTiles[i][j].setSize(sf::Vector2f(85.f, 150.f));
      dispTiles[i][j].setOutlineThickness(1.f);
      dispTiles[i][j].setOutlineColor(sf::Color::Cyan);
      dispTiles[i][j].setPosition(j * (85.f) + 10, i * (150.f) + 200);
      dispTiles[i][j].setFillColor(sf::Color::Transparent);
    }
  }
  std::cout << "made map" << std::endl;

  appSpriteHolders = new sf::RectangleShape*[5];
  for (int i = 0; i < 5; i++) {
    appSpriteHolders[i] = new sf::RectangleShape[20];
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      appSpriteHolders[i][j].setSize(sf::Vector2f(50.f, 50.f));
      appSpriteHolders[i][j].setPosition(j * (85.f) + 30, i * (150.f) + 250);
      appSpriteHolders[i][j].setFillColor(sf::Color::Transparent);
    }
  }

  std::cout << "made sprite holders" << std::endl;
}

void Game::initVirus() {
  maxVirusSpritesSpace = 100;
  virusSprites = new sf::RectangleShape[maxVirusSpritesSpace];
  virusManager = new virus*[100];
}

// constuctors and destructors
Game::Game() : currentSelectionId(0) {
  this->initVariables();
  this->initWindow();
  this->initMap();
  this->initBar();
  this->initText();
  this->initVirus();
}
Game::~Game() {
  delete this->window;

  if (virusManager != nullptr) {
    for (int i = 0; i < gameManager->getVirusCount(); i++) {
      if (virusManager[i] != nullptr) {
        delete[] this->virusManager[i];
      }
    }
    delete[] this->virusManager;
  }

  delete[] this->virusSprites;

  if (dispTiles != nullptr) {
    for (int i = 0; i < 5; i++) {
      if (dispTiles[i] != nullptr) {
        delete[] this->dispTiles[i];
      }
    }
    delete[] this->dispTiles;
  }

  delete[] this->taskBarSprites;

  if (appSpriteHolders != nullptr) {
    for (int i = 0; i < 5; i++) {
      if (appSpriteHolders[i] != nullptr) {
        delete[] this->appSpriteHolders[i];
      }
    }
    delete[] this->appSpriteHolders;
  }

  delete this->gridMap;
  delete this->gameManager;
}

// Public Functions
bool Game::taskBarChecker(int i) {
  if (taskBar[i].getGlobalBounds().contains(
          window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))) {
    return true;
  }
  return false;
}

bool Game::gridMapChecker(int x, int y) {
  if (dispTiles[x][y].getGlobalBounds().contains(
          window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))) {
    return true;
  }
  return false;
}

void Game::cleanUpDeadVirusesSprites() {
  int newCount = 0;
  for (int i = 0; i < gameManager->getVirusCount(); i++) {
    if (virusManager[i]->checkAlive() == false) {
      virusSprites[newCount++] = virusSprites[i];
    }
  }
}

void Game::spawnEnemy(int id) {
  int type = id;  // for debug - setting to only bug spawn

  // random row spawn
  // int rowSpawn = rand()%5;
  int rowSpawn = (int)(5.0 * (rand() / (RAND_MAX + 1.0)));
  std::cout << "rowChosen: " << rowSpawn << std::endl;

  virusManager = gameManager->spawnVirus(virusManager, type, rowSpawn);
  std::cout << "spawning ended \n" << std::endl;

  // resizing the number of rectangle shapes
  if ((gameManager->getVirusCount() + 2) >= maxVirusSpritesSpace) {
    int oldSize = maxVirusSpritesSpace;
    int newSize = maxVirusSpritesSpace * 2;
    std::cout << "old:" << oldSize << "new:" << newSize << std::endl;

    sf::RectangleShape* temp = new sf::RectangleShape[newSize];
    std::cout << "new temp Virus sprites" << std::endl;
    if (virusSprites != nullptr) {
      std::copy(virusSprites, virusSprites + oldSize, temp);
      std::cout << "copied Virus sprites" << std::endl;

      delete[] virusSprites;
      std::cout << "deleted Virus sprites" << std::endl;
    }
    virusSprites = temp;
    maxVirusSpritesSpace = newSize;
    std::cout << "made Virus sprites to temp" << std::endl;
  }

  // setting the sprite
  switch (virusManager[gameManager->getVirusCount() - 1]->getId()) {
    case 0:  // for bug
      virusSprites[gameManager->getVirusCount() - 1].setSize(
          sf::Vector2f(50.f, 50.f));  // bug
      virusSprites[gameManager->getVirusCount() - 1].setFillColor(
          sf::Color::Red);
      break;
    case 1:
      if (gameManager->getVirusCount() >= 3) {
        virusSprites[gameManager->getVirusCount() - 3].setSize(
            sf::Vector2f(60.f, 55.f));  // worm
        virusSprites[gameManager->getVirusCount() - 3].setFillColor(
            sf::Color::White);
        std::cout << "head sprite set" << std::endl;

        virusSprites[gameManager->getVirusCount() - 2].setSize(
            sf::Vector2f(60.f, 65.f));
        virusSprites[gameManager->getVirusCount() - 2].setFillColor(
            sf::Color::White);
        std::cout << "middle sprite set" << std::endl;

        virusSprites[gameManager->getVirusCount() - 1].setSize(
            sf::Vector2f(60.f, 55.f));
        virusSprites[gameManager->getVirusCount() - 1].setFillColor(
            sf::Color::White);
        std::cout << "end sprite set" << std::endl;
      }
      break;
    case 2:
      virusSprites[gameManager->getVirusCount() - 1].setSize(
          sf::Vector2f(50.f, 55.f));  // trojan
      virusSprites[gameManager->getVirusCount() - 1].setFillColor(
          sf::Color::Green);
      break;
    case 3:
      virusSprites[gameManager->getVirusCount() - 1].setSize(
          sf::Vector2f(50.f, 50.f));  // logicbomb
      virusSprites[gameManager->getVirusCount() - 1].setFillColor(
          sf::Color::Yellow);
      break;
    case 4:
      virusSprites[gameManager->getVirusCount() - 1].setSize(
          sf::Vector2f(50.f, 50.f));  // Iloveyou
      virusSprites[gameManager->getVirusCount() - 1].setOutlineColor(
          sf::Color::White);
      break;
    default:
      std::cout << "No valid ID for sprite type!" << std::endl;
      break;
  }

  // spawn position for sprite
  sf::Vector2f endOfCurrentRow = dispTiles[rowSpawn][19].getPosition();
  endOfCurrentRow.x = endOfCurrentRow.x + 15;
  endOfCurrentRow.y = endOfCurrentRow.y + 50;
  switch (type) {
    case 1:
      virusSprites[gameManager->getVirusCount() - 3].setPosition(
          endOfCurrentRow.x, endOfCurrentRow.y);  // set spritePosition
      virusManager[gameManager->getVirusCount() - 3]->setPosXY(
          endOfCurrentRow.x, endOfCurrentRow.y);  // set Data Position
      virusSprites[gameManager->getVirusCount() - 2].setPosition(
          endOfCurrentRow.x, endOfCurrentRow.y - 5);  // set spritePosition
      virusManager[gameManager->getVirusCount() - 2]->setPosXY(
          endOfCurrentRow.x, endOfCurrentRow.y - 5);  // set Data Position
      virusSprites[gameManager->getVirusCount() - 1].setPosition(
          endOfCurrentRow.x, endOfCurrentRow.y);  // set spritePosition
      virusManager[gameManager->getVirusCount() - 1]->setPosXY(
          endOfCurrentRow.x, endOfCurrentRow.y);  // set Data Position

      std::cout << virusManager[gameManager->getVirusCount() - 1]->getPosX()
                << " "
                << virusManager[gameManager->getVirusCount() - 1]->getPosY()
                << std::endl;
      std::cout << "spawning worm sprites ended \n" << std::endl;
      break;
    case 2:
      virusSprites[gameManager->getVirusCount() - 1].setPosition(
          endOfCurrentRow);  // set spritePosition
      virusManager[gameManager->getVirusCount() - 1]->setPosXY(
          endOfCurrentRow.x, endOfCurrentRow.y - 2.5);  // set Data Position

      std::cout << virusManager[gameManager->getVirusCount() - 1]->getPosX()
                << " "
                << virusManager[gameManager->getVirusCount() - 1]->getPosY()
                << std::endl;
      std::cout << "spawning sprites ended \n" << std::endl;
      break;

    default:
      virusSprites[gameManager->getVirusCount() - 1].setPosition(
          endOfCurrentRow);  // set spritePosition
      virusManager[gameManager->getVirusCount() - 1]->setPosXY(
          endOfCurrentRow.x, endOfCurrentRow.y);  // set Data Position

      std::cout << virusManager[gameManager->getVirusCount() - 1]->getPosX()
                << " "
                << virusManager[gameManager->getVirusCount() - 1]->getPosY()
                << std::endl;
      std::cout << "spawning sprites ended \n" << std::endl;
      break;
  }
}

void Game::pollEvents() {  // game ui inputs
  while (this->window->pollEvent(this->ev)) {
    // windowclose
    if (this->ev.type == sf::Event::Closed) {  // close window button
      this->window->close();
    }

    // mouse click
    if (this->ev.type == sf::Event::MouseButtonPressed) {
      std::cout << "button pressed" << std::endl;
      for (int i = 0; i < 6; i++) {
        if (Game::taskBarChecker(i) == true) {
          currentSelectionId = i;
          std::cout << "changed Id to " << currentSelectionId << std::endl;
        }
      }

      // placement
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 20; k++) {
          if (Game::gridMapChecker(j, k) ==
              true) {  // check if mouse is on current tile
            std::cout << "Cost of: " << currentSelectionId << " is "
                      << gameManager->costCheck(currentSelectionId)
                      << std::endl;

            if (gameManager->getResource() >=
                gameManager->costCheck(
                    currentSelectionId)) {  // gets cost of app
              if ((gridMap->checkOccupancy(j, k) == false) ||
                  (currentSelectionId ==
                   5)) {  // checks if remove tool or occupied
                gameManager->addResource(-(gameManager->costCheck(
                    currentSelectionId)));  // takes currency
                switch (currentSelectionId) {
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

                gridMap->addApplication(
                    j, k, currentSelectionId);  // adds selection id to
                std::cout << gridMap->checkOccupancy(j, k) << std::endl;
              }
            }
          }
        }
      }
    }
  }
}

void Game::update() {  // game updates
  this->pollEvents();  // keyboard

  // checking mouse and output
  inGrid = false;
  inBar = false;
  sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);

  for (int i = 0; i < 6; i++) {
    sf::FloatRect taskBarBounds = taskBar[i].getGlobalBounds();

    if (taskBarBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
      inBar = true;
      taskBar[i].setOutlineColor(sf::Color::White);
      // std::cout << PopupBoxTimer.getElapsedTime().asSeconds() << std::endl;

      if (PopupBoxTimer.getElapsedTime().asSeconds() >= 1.0f) {
        PopDisplayText.setPosition(mousePos.x, mousePos.y + 15);
        PopDisplayText.setString(gameManager->getAppDesc(i));
      }
    } else {
      taskBar[i].setOutlineColor(sf::Color::Cyan);
    }
  }

  // subtext for mouse
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      sf::FloatRect Bounds = dispTiles[i][j].getGlobalBounds();
      if (Bounds.contains(static_cast<sf::Vector2f>(mousePos))) {
        dispTiles[i][j].setOutlineColor(sf::Color::White);
        inGrid = true;

        if (gridIndicatorTimer.getElapsedTime().asSeconds() >= 1.0f) {
          PopDisplayText.setPosition(mousePos.x, mousePos.y + 15);
          int CurrentId = gridMap->checkAppId(i, j);
          std::string appName = "";
          switch (CurrentId) {
            case 0:
              appName = "VsCode \n";
              break;
            case 1:
              appName = "FileExplorer \n";
              break;
            case 2:
              appName = "FireWall \n";
              break;
            case 3:
              appName = "VPN \n";
              break;
            case 4:
              appName = "Chrome \n";
              break;
            default:
              break;
          }
          std::string first = std::to_string(i);
          std::string second = std::to_string(j);
          PopDisplayText.setString(appName);
        }
      } else {
        dispTiles[i][j].setOutlineColor(sf::Color::Cyan);
      }
    }
  }

  if (!inBar && !inGrid) {  // resets the descriptions
    PopupBoxTimer.restart();
    gridIndicatorTimer.restart();
    PopDisplayText.setString("");  // change to name of selected app later!
  }

  // checking tile types for production
  int currentProducers = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      currentProducers = gridMap->checkNumOfTileIDs(0);
    }
  }

  // spawners
  if (gameManager->canSpawnBug() == true) {
    if (gameManager->elapsedTime() >= 15) {
      Game::spawnEnemy(0);
    }
  }
  if (gameManager->canSpawnWorm() == true) {
    if (gameManager->elapsedTime() >= 240) {
      Game::spawnEnemy(1);
    }
  }
  if (gameManager->canSpawnTrojan() == true) {
    if (gameManager->elapsedTime() >= 180) {
      Game::spawnEnemy(2);
    }
  }
  if (gameManager->canSpawnLogicBomb() == true) {
    if (gameManager->elapsedTime() >= 10) {
      Game::spawnEnemy(3);
    }
  } /* if (gameManager->ILOVEYOUSpawnTimeCheck() == true){
      if (gameManager->elapsedTime() >= 400){
              Game::spawnEnemy(4);
      }
  }*/

  // waves spawner
  if ((gameManager->elapsedTime() >= 100) &&
      (gameManager->elapsedTime() <= 100.1)) {  // first wave of enemies
    if (waveTimer.getElapsedTime().asSeconds() >= 1) {
      std::cout << "Wave 1!" << std::endl;
      for (int i = 0; i < 5; i++) {
        Game::spawnEnemy(0);
      }
      waveTimer.restart();
    }
  } else if ((gameManager->elapsedTime() >= 200) &&
             (gameManager->elapsedTime() <= 200.1)) {  // second wave of enemies
    if (waveTimer.getElapsedTime().asSeconds() >= 1) {
      std::cout << "Wave 2!" << std::endl;
      for (int i = 0; i < 5; i++) {
        Game::spawnEnemy(0);
      }
      for (int i = 0; i < 3; i++) {
        Game::spawnEnemy(1);
      }
      waveTimer.restart();
    }
  } else if ((gameManager->elapsedTime() >= 300) &&
             (gameManager->elapsedTime() <= 300.1)) {  // third wave of enemies
    if (waveTimer.getElapsedTime().asSeconds() >= 1) {
      std::cout << "Wave 3!" << std::endl;
      for (int i = 0; i < 8; i++) {
        Game::spawnEnemy(0);
      }
      for (int i = 0; i < 3; i++) {
        Game::spawnEnemy(1);
      }
      for (int i = 0; i < 2; i++) {
        Game::spawnEnemy(2);
      }
      waveTimer.restart();
    }
  }

  // internal one second timer
  if (clock.getElapsedTime().asSeconds() >= 1.0f) {  // one second clock
    fiveSec++;
    if (fiveSec >= 5) {
      fiveSec = 0;
    }
    if (fiveSec == 3) {
      gameManager->addResource(1 + 1 * gridMap->checkNumOfTileIDs(0));
    }
    std::cout << fiveSec << std::endl;
    clock.restart();
  }

  // getting projectiles
  projectileCount = gridMap->getNumShootingTiles(1);
  if (virusSprites != nullptr) {  // get projectiles
    projected = gridMap->getProjectiles(virusSprites->getGlobalBounds());
  }

  slowCount = gridMap->getNumShootingTiles(3);
  if (virusSprites != nullptr) {  // get projectiles
    slowed = gridMap->getSlows(virusSprites->getGlobalBounds());
  }

  explosionCount = gridMap->getNumShootingTiles(4);
  if (virusSprites != nullptr) {  // get explosion
    explosions = gridMap->getExplosions(virusSprites->getGlobalBounds());
  }

  // gameManager->cleanUpDeadViruses(virusManager); //deleting and freeing space
  // Game::cleanUpDeadVirusesSprites();
  ////enemy virus checking
  for (int i = 0; i < gameManager->getVirusCount(); i++) {
    if (virusSprites != nullptr) {
      projected = gridMap->getProjectiles(virusSprites[i].getGlobalBounds());
    }

    for (int j = 0; j < projectileCount; j++) {
      for (int k = 0; k < projected[j]->size();) {
        // std::cout<< "Health is now" << projected[j]->at(k).getPosition().y <<
        // " sprite: " << virusSprites[i].getPosition().y +50 << std::endl;

        if ((projected[j]->at(k).getPosition().x) >=
                (virusSprites[i].getPosition().x - 5) &&
            ((projected[j]->at(k).getPosition().x) <=
             (virusSprites[i].getPosition().x + 50)) &&
            (projected[j]->at(k).getPosition().y) <=
                (virusSprites[i].getPosition().y + 50) &&
            (projected[j]->at(k).getPosition().y) >=
                (virusSprites[i].getPosition().y - 50)) {
          virusManager[i]->setHealth((virusManager[i]->getHealth()) -
                                     (gameManager->appDmgCheck(1)));
          std::cout << "Health is now" << virusManager[i]->getHealth()
                    << " Dmg taken is: " << gameManager->appDmgCheck(1)
                    << std::endl;
          projected[j]->erase(projected[j]->begin() + k);
        } else {
          k++;
        }
      }
    }

    if (virusSprites != nullptr) {
      slowed = gridMap->getSlows(virusSprites[i].getGlobalBounds());
    }

    for (int j = 0; j < slowCount; j++) {
      for (int k = 0; k < slowed[j]->size();) {
        // std::cout<< "Health is now" << slowed[j]->at(k).getPosition().y <<
        // " sprite: " << virusSprites[i].getPosition().y +50 << std::endl;

        if ((slowed[j]->at(k).getPosition().x) >=
                (virusSprites[i].getPosition().x - 5) &&
            ((slowed[j]->at(k).getPosition().x) <=
             (virusSprites[i].getPosition().x + 50)) &&
            (slowed[j]->at(k).getPosition().y) <=
                (virusSprites[i].getPosition().y + 50) &&
            (slowed[j]->at(k).getPosition().y) >=
                (virusSprites[i].getPosition().y - 50)) {
          virusManager[i]->setHealth((virusManager[i]->getHealth()) -
                                     (gameManager->appDmgCheck(3)));
          virusManager[i]->setTileTime((virusManager[i]->getTileTime()) * 1.25);
          std::cout << "Health is now" << virusManager[i]->getHealth()
                    << " Dmg taken is: " << gameManager->appDmgCheck(3)
                    << " Enemy is slowed to: " << virusManager[i]->getTileTime()
                    << std::endl;
          slowed[j]->erase(slowed[j]->begin() + k);
        } else {
          k++;
        }
      }
    }

    if (virusSprites != nullptr) {  // get explosion
      explosions = gridMap->getExplosions(virusSprites->getGlobalBounds());
    }

    for (int j = 0; j < explosionCount; j++) {
      for (int k = 0; k < explosions[j]->size();) {
        // std::cout<< "Health is now" << projected[j]->at(k).getPosition().y <<
        // " sprite: " << virusSprites[i].getPosition().y +50 << std::endl;
        if (virusSprites[i].getGlobalBounds().intersects(
                (*explosions[j])[k].getGlobalBounds())) {
          virusManager[i]->setHealth((virusManager[i]->getHealth()) -
                                     (gameManager->appDmgCheck(4)));
          // std::cout<< "Health is now" << virusManager[i]->getHealth() << "
          // Dmg taken is: " << gameManager->appDmgCheck(4) << std::endl;
          explosions[j]->erase(explosions[j]->begin() + k);
        } else {
          k++;
        }
      }
    }

    // virus alive or dead
    if (virusManager[i]->getHealth() <= 0) {
      virusManager[i]->setStatus(false);
      virusSprites[i].setPosition(sf::Vector2f(2300, 1100));
      virusSprites[i].setFillColor(sf::Color::Transparent);
      virusManager[i]->setPosXY(2300, 1100);
    }

    if (virusManager[i]->checkAlive() == true) {
      if (virusManager[i]->move() == true) {
        virusSprites[i].setPosition(
            sf::Vector2f((virusSprites[i].getPosition().x) - 85.f,
                         virusSprites[i].getPosition().y));
        std::cout << "Sprite: " << virusSprites[i].getPosition().x
                  << " Manager: " << virusManager[i]->getPosX() << std::endl;
      }
    }

    // end
    if (virusSprites->getPosition().x <= 0) {
      // game over
    }

    // checking if  virus is on a app
    if (virusManager[i]->getId() == 3) {  // logicBomb ID
      // Only freeze if explosion has already started, not before
      if ((virusManager[i]->getExplosion() == true) &&
          (virusManager[i]->getHealth() <= 0)) {
        virusManager[i]->setFreeze(true);  // Freeze only after explosion
      } else {
        virusManager[i]->setFreeze(false);  // Let it move if not exploding
      }
    } else {
      virusManager[i]->setFreeze(false);  // Handle other virus types
    }
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 20; k++) {
        if ((dispTiles[j][k].getGlobalBounds().contains(
                 virusManager[i]->getPosX(), virusManager[i]->getPosY()) ==
             true) &&
            (gridMap->checkOccupancy(j, k) == true)) {
          // checking if worm segments should all stop
          if (virusManager[i]->getId() == 1) {
            if (virusManager[i + 1] != nullptr) {
              if ((virusManager[i + 1]->getSegmentId() == 1) ||
                  (virusManager[i + 1]->getSegmentId() == 2)) {
                virusManager[i + 1]->setFreeze(true);
              }
            }
            if (virusManager[i + 2] != nullptr) {
              if ((virusManager[i + 2]->getSegmentId() == 1) ||
                  (virusManager[i + 2]->getSegmentId() == 2)) {
                virusManager[i + 2]->setFreeze(true);
              }
            }
          }

          // default stopping to eat app
          virusManager[i]->setFreeze(true);
          if (virusManager[i]->getDmgClock() >= 1.0f) {
            if (gridMap->takeAppDamage(j, k, virusManager[i]->getDmg()) ==
                true) {
              virusManager[i]->setFreeze(true);
            }
            virusManager[i]->restartClock();
          }

          if (virusManager[i]->getId() == 3) {
            // std::cout << "Ex CHecker: " << virusManager[i]->getExplosion()
            // <<std::endl;
            if (virusManager[i]->getExplosion() == true) {
              virusManager[i]->setFreeze(true);
              virusManager[i]->move();
              virusSprites[i].setSize(sf::Vector2f(300.0f, 400.0f));
              virusSprites[i].setPosition(
                  sf::Vector2f(virusSprites[i].getPosition().x,
                               virusSprites[i].getPosition().y - 160));
              gridMap->takeAppDamage(j, k, virusManager[i]->getDmg() * 100);
              gridMap->takeAppDamage(j, k + 1, virusManager[i]->getDmg() * 100);
              gridMap->takeAppDamage(j, k - 1, virusManager[i]->getDmg() * 100);
              gridMap->takeAppDamage(j + 1, k, virusManager[i]->getDmg() * 100);
              gridMap->takeAppDamage(j + 1, k + 1,
                                     virusManager[i]->getDmg() * 100);
              gridMap->takeAppDamage(j + 1, k - 1,
                                     virusManager[i]->getDmg() * 100);
              gridMap->takeAppDamage(j - 1, k, virusManager[i]->getDmg() * 100);
              gridMap->takeAppDamage(j - 1, k + 1,
                                     virusManager[i]->getDmg() * 100);
              gridMap->takeAppDamage(j - 1, k - 1,
                                     virusManager[i]->getDmg() * 100);
            }
          }
        }
      }
    }

    // dispTiles[x][y].getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))){
  }

  // refresh and checks apps statuses
  gridMap->checkAppsStatus();    // checks if any apps are dead and removes them
  for (int i = 0; i < 5; i++) {  // for application sprites
    for (int j = 0; j < 20; j++) {
      if (gridMap->checkOccupancy(i, j) == false) {
        appSpriteHolders[i][j].setFillColor(sf::Color::Transparent);
      }
    }
  }

  // mouse position updates
  // std::cout<<"Mouse pos:  " << sf::Mouse::getPosition(*this->window).x << " "
  // << sf::Mouse::getPosition(*this->window).y << std::endl;
}

void Game::render() {  // renders the game objects

  this->window->clear(sf::Color::Black);  // clearing frame

  // time clock
  std::string currentTime = std::to_string(gameManager->elapsedTime());
  timerText.setString(currentTime);

  std::string currentResource = std::to_string(gameManager->getResource());
  resourceText.setString(currentResource + " Mb");

  // drawing objects
  for (int i = 0; i < 5; i++) {  // grid map display
    for (int j = 0; j < 20; j++) {
      this->window->draw(this->dispTiles[i][j]);
    }
  }

  for (int i = 0; i < 5; i++) {  // for application sprites
    for (int j = 0; j < 20; j++) {
      this->window->draw(this->appSpriteHolders[i][j]);
    }
  }

  for (int i = 0; i < 6; i++) {  // task bar
    this->window->draw(this->taskBar[i]);
  }

  for (int i = 0; i < 6; i++) {  // task bar sprites
    this->window->draw(this->taskBarSprites[i]);
  }

  for (int i = 0; i < gameManager->getVirusCount(); i++) {
    this->window->draw(this->virusSprites[i]);
  }

  for (int i = 0; i < projectileCount; i++) {
    for (int j = 0; j < projected[i]->size(); j++) {
      window->draw((*projected[i])[j]);
    }
  }

  for (int i = 0; i < slowCount; i++) {
    for (int j = 0; j < slowed[i]->size(); j++) {
      window->draw((*projected[i])[j]);
    }
  }

  for (int i = 0; i < explosionCount; i++) {
    if (explosions[i] != nullptr) {
      for (int j = 0; j < explosions[i]->size(); j++) {
        window->draw((*explosions[i])[j]);
      }
    }
  }

  this->window->draw(this->timerText);
  this->window->draw(this->resourceText);
  this->window->draw(this->PopDisplayText);

  this->window->display();  // displays frame
}