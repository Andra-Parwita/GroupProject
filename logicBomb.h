#ifndef LOGICBOMB_H
#define LOGICBOMB_H

#include "virus.h"

class logicBomb : public virus {
 protected:
 public:
  // constructors
  logicBomb();
  logicBomb(int health, float tileTime, int id, int dmg);
  ~logicBomb();

  void explode();
};

#endif