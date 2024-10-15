#ifndef VPN_H
#define VPN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "application.h"
#include "shooter.h"
#include "virus.h"

class vpn : public shooter {
 private:
  int attackInterval;  // Time between attacks (in seconds)
  sf::Clock internalClock;
  sf::Clock internalClockMove;

  std::vector<sf::CircleShape> projectiles;  // the container of projectiles
  //sounds
  sf::SoundBuffer buffer;
  sf::Sound sound;

 public:
  // Constructor
  vpn(int health, int cost, int id, int dmg = 1, int attackInterval = 10);
  vpn();
  ~vpn();

  // Function to attack enemies
  void shoot();

  // Update timer for attack
  std::vector<sf::CircleShape>* update(sf::FloatRect pos);
};

#endif
