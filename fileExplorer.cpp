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
  if (projectiles.size() >= 10) { // Adjust 10 as needed
    return; // Prevent shooting if max projectiles are active
  }

  if(internalClock.getElapsedTime().asSeconds() >= attackInterval){
    std::cout << "fileExplorer shoots" << std::endl;

    sf::CircleShape bullet;
    bullet.setRadius(5);
    bullet.setFillColor(sf::Color::Cyan);
    bullet.setOrigin(5,5);
    bullet.setPosition(this->AppPosition);
    projectiles.push_back(bullet);

    internalClock.restart();
  }
}

// Update timer and trigger attacks if the interval has passed
 std::vector<sf::CircleShape>  fileExplorer::update() {
  std::cout << "size is " << projectiles.size() << std::endl;
  shoot();

  /* for (auto &proj : projectiles){
    proj.move(0.5f,0.f);
  } */
 for (int i = 0; i < projectiles.size(); ) {
        // Move the projectile
        projectiles[i].move(5.f, 0.f); // Move to the right

        // Remove projectiles that are off-screen
        if (projectiles[i].getPosition().x > 2000) {
            projectiles.erase(projectiles.begin() + i); // Remove the projectile
        } else {
            i++; // Only increment if we didn't erase an element
        }
    }
  return projectiles;
}
