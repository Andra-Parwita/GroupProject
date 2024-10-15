#ifndef CHROME_H
#define CHROME_H

#include "application.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class chrome : public application {
 private:
  int explodeRadius;  // Explosion radius
  int explodeTime;    // Time until boom
  int elapsedTime;    // Time elapsed since placing

  //clocks and projectiles
  sf::Clock internalClock;
  bool once; //to play sound once
  std::vector<sf::CircleShape> explosion; //explosion projectile

  bool explode();

  //sound
  sf::SoundBuffer buffer;
  sf::Sound sound;

  void boomsfx();

 public:
  // Constructor
  chrome(int health, int cost, int id, int dmg, int explodeTime);
  chrome();

  // Function to attack enemies
  std::vector<sf::CircleShape>* update(sf::FloatRect pos);

};

#endif