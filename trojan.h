#ifndef TROJAN_H
#define TROJAN_H

#include "virus.h"

class trojan : public virus {
 protected:
 public:
  // constructors
  trojan();
  trojan(int health, float tileTime, int id, int dmg);
  ~trojan();
};

#endif