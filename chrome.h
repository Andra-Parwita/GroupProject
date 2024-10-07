#ifndef CHROME_H
#define CHROME_H

#include "application.h"

class chrome : public application {
 private:
  int dmg;            // Amount of damage dealt
  int explodeRadius;  // Explosion radius
  int explodeTime;    // Time until boom
  int elapsedTime;    // Time elapsed since placing

 public:
  // Constructor
  chrome(int health, int cost, int id, int dmg = 100, int explodeTime = 3);
  chrome();

  // Function to attack enemies
  void explode();

  // Update timer for attack
  void updateTimer(int deltaTime);
};

#endif