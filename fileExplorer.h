#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include "application.h"
#include <SFML/Graphics.hpp>
#include "virus.h"

class fileExplorer : public application {
 private:
  int attackInterval;  // Time between attacks (in seconds)
  sf::Clock internalClock;

  std::vector<sf::CircleShape> projectiles; //the container of projectiles
  

 public:
  // Constructor
  fileExplorer(int health, int cost, int id, int dmg = 20,
               int attackInterval = 3);
  fileExplorer();

  // Function to attack enemies
  void shoot();

  // Update timer for attack
  std::vector<sf::CircleShape>* update(sf::FloatRect pos);
};

#endif
