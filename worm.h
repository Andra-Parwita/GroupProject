#ifndef WORM_H
#define WORM_H

#include "virus.h"

class worm : public virus {
 protected:
  sf::Clock segmentClock;
 public:
  // constructors
  static int segmentCount;
  worm();
  worm(int health, float tileTime, int id, int dmg);
  worm(int segId);
  ~worm();
  bool move();
};

#endif
