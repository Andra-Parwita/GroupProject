#include "grid.h"

#include <iostream>

#include "tile.h"

// constructors
grid::grid() {
  tiles = new tile*[5];

  for (int i = 0; i < 5; i++) {
    tiles[i] = new tile[20];
    for (int j = 0; j < 20; j++) {
      tiles[i][j].setAppPosition(
          sf::Vector2f(j * (85.f) + 30, i * (150.f) + 250));
    }
  }

  projectileContainers = new std::vector<sf::CircleShape>*[100];
  for (int i = 0; i < 100; i++) {
    projectileContainers[i] = new std::vector<sf::CircleShape>;
  }

  slowContainers = new std::vector<sf::CircleShape>*[100];
  for (int i = 0; i < 100; i++) {
    slowContainers[i] = new std::vector<sf::CircleShape>;
  }

  explosionContainers = new std::vector<sf::CircleShape>*[100];
  for (int i = 0; i < 100; i++) {
    explosionContainers[i] = new std::vector<sf::CircleShape>;
  }
}

grid::~grid() {
  if (tiles != nullptr) {
    for (int i = 0; i < 5; i++) {
      if (tiles[i] != nullptr) {
        delete[] this->tiles[i];
      }
    }
    delete[] this->tiles;
    tiles = nullptr;
  }
  std::cout << "Deleted tiles" << std::endl;

  // Delete the projectile containers
  if (projectileContainers != nullptr) {
    for (int i = 0; i < 100; i++) {
      if (projectileContainers[i] != nullptr) {
        delete projectileContainers[i];  // delete the vector at each index
      }
    }
    delete[] this->projectileContainers;  // delete the array of pointers
    projectileContainers = nullptr;
  }
  std::cout << "Deleted Projectiles" << std::endl;

  // Delete the slow containers
  if (slowContainers != nullptr) {
    for (int i = 0; i < 100; i++) {
      if (slowContainers[i] != nullptr) {
        delete slowContainers[i];  // delete the vector at each index
      }
    }
    delete[] this->slowContainers;
    slowContainers = nullptr;
  }
  std::cout << "Deleted Slows" << std::endl;

  // Delete the explosion containers
  if (explosionContainers != nullptr) {
    for (int i = 0; i < 100; i++) {
      if (explosionContainers[i] != nullptr) {
        delete explosionContainers[i];  // delete the vector at each index
      }
    }
    delete[] this->explosionContainers;
    explosionContainers = nullptr;
  }
  std::cout << "Deleted Explosions" << std::endl;
}

// functions
bool grid::addApplication(int x, int y, int appId) { //adding an application to the tile
  if ((tiles[x][y].getIsOccupied() == false) && (appId != 5)) {
    sf::Vector2f pos = sf::Vector2f(y * (85.f) + 30, x * (150.f) + 250);
    tiles[x][y].occupy(appId, pos);
    std::cout << "added " << appId << " to " << x << " " << y << std::endl;
    return true;
  } else if ((appId == 5) && ((tiles[x][y].getIsOccupied() == true))) {
    std::cout << "removed " << tiles[x][y].getApplicationType().getId()
              << " at " << x << " " << y << std::endl;
    tiles[x][y].clear();
    return true;
  }

  return false;
}

void grid::removeApplication(int x, int y) { //removal of application
  if (tiles[x][y].getIsOccupied() == true) {
    tiles[x][y].clear();
  }
}

void grid::checkAppsStatus() { //returning if the tile is dead or alive
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      tiles[i][j].updateStatus();
    }
  }
}

int grid::checkAppId(int x, int y) { //gettingid
  return tiles[x][y].getApplicationType().getId();
}

bool grid::checkOccupancy(int x, int y) { return tiles[x][y].getIsOccupied(); }

int grid::checkNumOfTileIDs(int wantedId) { //checking how many tile ids are of the given type
  int total = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      int current = tiles[i][j].getApplicationType().getId();
      if (current == wantedId) {
        total += 1;
      }
    }
  }
  return total;
}

int grid::getNumShootingTiles(int id) { //get how many shooting ides are of the given type (same as above!! refactor!)
  int numOfProjectileProducers = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      int current = tiles[i][j].getApplicationType().getId();
      if (current == id) {
        numOfProjectileProducers++;
      }
    }
  }
  return numOfProjectileProducers;
}

std::vector<sf::CircleShape>** grid::getProjectiles(sf::FloatRect pos) { //get the projectile arrays from the shooters
  // Clear the container before fetching updated projectiles
  for (int i = 0; i < 100; i++) {
    projectileContainers[i]->clear();
  }
  int numOfProjectileProducers = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      if (tiles[i][j].getApplicationType().getId() == 1) {
        std::vector<sf::CircleShape>* newProjectiles = tiles[i][j].update(pos);
        if (newProjectiles != nullptr) {
          projectileContainers[numOfProjectileProducers]->insert(
              projectileContainers[numOfProjectileProducers]->end(),
              newProjectiles->begin(), newProjectiles->end());
        }
        numOfProjectileProducers++;
      }
    }
  }

  return projectileContainers;
}

std::vector<sf::CircleShape>** grid::getSlows(sf::FloatRect pos) { //get the projectile arrays from vpn
  // Clear the container before fetching updated projectiles
  for (int i = 0; i < 100; i++) {
    slowContainers[i]->clear();
  }
  int numOfSlowProducers = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      if (tiles[i][j].getApplicationType().getId() == 3) {
        std::vector<sf::CircleShape>* newProjectiles = tiles[i][j].update(pos);
        if (newProjectiles != nullptr) {
          slowContainers[numOfSlowProducers]->insert(
              slowContainers[numOfSlowProducers]->end(),
              newProjectiles->begin(), newProjectiles->end());
        }
        numOfSlowProducers++;
      }
    }
  }

  return slowContainers;
}

std::vector<sf::CircleShape>** grid::getExplosions(sf::FloatRect pos) { //get the projectile arrays from chrome
  // Clear the container before fetching updated projectiles
  for (int i = 0; i < 100; i++) {
    explosionContainers[i]->clear();
  }

  int numOfProjectileProducers = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 20; j++) {
      if (tiles[i][j].getApplicationType().getId() == 4) {
        std::vector<sf::CircleShape>* newProjectiles = tiles[i][j].update(pos);
        if (newProjectiles != nullptr) {
          explosionContainers[numOfProjectileProducers]->insert(
              explosionContainers[numOfProjectileProducers]->end(),
              newProjectiles->begin(), newProjectiles->end());
        }
        numOfProjectileProducers++;
      }
    }
  }

  return explosionContainers;
}

bool grid::takeAppDamage(int x, int y, int dmgTaken) { //checks app damage if they can take damage
  if ((x < 5) && (y < 20) && (y >= 0) && (x >= 0)) {
    if ((tiles[x][y].getIsOccupied() == true) &&
        (tiles[x][y].checkAppStatus() == true) &&
        (tiles[x][y].getApplicationType().getHealth() > 0)) {
      int currentHP = tiles[x][y].getApplicationType().getHealth();
      int newHP = currentHP - dmgTaken;
      tiles[x][y].setAppHealth(newHP);
      std::cout << "App health is now: "
                << tiles[x][y].getApplicationType().getHealth() << std::endl;
      return true;
    }
  }
  return false;
}
