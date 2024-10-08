#ifndef BUG_H
#define BUG_H

#include "virus.h"

class bug : public virus {
 protected:
 public:
  // constructors
  bug();
  bug(int health, float tileTime, int id, int dmg);
  ~bug();
};

#endif
