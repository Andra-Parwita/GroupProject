#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include "application.h"
#include "shooter.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "virus.h"

class fileExplorer : public shooter {
 private:
  int attackInterval;  // Time between attacks (in seconds)
  sf::Clock internalClock;
  sf::Clock* internalClockMove;

  std::vector<sf::CircleShape> projectiles; //the container of projectiles
  
  sf::SoundBuffer buffer;
  sf::Sound sound;
 public:
  // Constructor
  fileExplorer(int health, int cost, int id, int dmg = 10,
               int attackInterval = 3);
  fileExplorer();
  ~fileExplorer();

  // Function to attack enemies
  void shoot();

  // Update timer for attack
  std::vector<sf::CircleShape>* update(sf::FloatRect pos);
};

#endif
