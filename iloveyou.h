#ifndef ILOVEYOU_H
#define ILOVEYOU_H

#include "virus.h"

class iloveyou : public virus {
 protected:
    int rowSwitcher;
 public:
  // constructors
  iloveyou();
  iloveyou(int health, float tileTime, int id, int dmg);
  ~iloveyou();
  bool move();
};

#endif
