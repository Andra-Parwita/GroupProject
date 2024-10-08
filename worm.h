#ifndef WROM_H
#define WORM_H

#include "virus.h"

class worm : public virus {
 protected:
 public:
  // constructors
  worm();
  worm(int health, float tileTime, int id, int dmg);
  ~worm();
};

#endif
