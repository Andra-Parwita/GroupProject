#include "fileExplorer.h"

#include <chrono>
#include <iostream>
#include <thread>

// Constructor
fileExplorer::fileExplorer(int health, int cost, int id, int dmg,
                           int attackInterval)
    : application(100, 15, 1),
      dmg(dmg),
      attackInterval(attackInterval){}
fileExplorer::fileExplorer() : application(100,15,1), dmg(1), attackInterval(3){}


// Simulate shooting (dealing damage)
void fileExplorer::shoot() {
  std::cout << "fileExplorer shoots" << std::endl;
  std::cout << this->AppPosition.x << " " << this->AppPosition.y << std::endl;
  projectiles.push_back(sf::CircleShape());
  projectiles.back().setRadius(5);
  projectiles.back().setOrigin(5,5);
  projectiles.back().setPosition(this->AppPosition);
  projectiles.back().setFillColor(sf::Color::Cyan);
}

// Update timer and trigger attacks if the interval has passed
 std::vector<sf::CircleShape>  fileExplorer::update() {
  if (internalClock.getElapsedTime().asSeconds() >= attackInterval) {
    shoot();
    internalClock.restart();
  }
  return projectiles;
}
