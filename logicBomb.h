#ifndef LOGICBOMB_H
#define LOGICBOMB_H

#include "virus.h"

class logicBomb : public virus {
 protected:
  sf::Clock internalExClock;
 public:
  // constructors
  logicBomb();
  logicBomb(int health, float tileTime, int id, int dmg);
  ~logicBomb();

  bool move();
};

#endif