#ifndef LOGICBOMB_H
#define LOGICBOMB_H

#include "virus.h"
#include "SFML/Audio.hpp"

class logicBomb : public virus {
 protected:
  //sounds
  sf::Clock internalExClock;
  sf::SoundBuffer soundBuffer;
  sf::Sound explosionSound;
  bool once; //plays sound once when explodes
 public:
  // constructors
  logicBomb();
  logicBomb(int health, float tileTime, int id, int dmg);
  ~logicBomb();
  
  bool move();
};

#endif