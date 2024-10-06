#ifndef ANTIVIRUS_H
#define ANTIVIRUS_H

#include "application.h"

class antivirus : public application {
 public:
  // Constructor
  antivirus(int health, int cost, int id);
};

#endif
