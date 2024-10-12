#ifndef CHROME_H
#define CHROME_H

#include "application.h"
#include "SFML/Graphics.hpp"

class chrome : public application {
 private:
  int explodeRadius;  // Explosion radius
  int explodeTime;    // Time until boom
  int elapsedTime;    // Time elapsed since placing

  sf::Clock internalClock;
  std::vector<sf::CircleShape> explosion;

  bool explode();

 public:
  // Constructor
  chrome(int health, int cost, int id, int dmg, int explodeTime);
  chrome();

  // Function to attack enemies
  std::vector<sf::CircleShape>* update(sf::FloatRect pos);

};

#endif