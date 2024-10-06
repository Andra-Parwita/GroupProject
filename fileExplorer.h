#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include "application.h"

class fileExplorer : public application {
 private:
  int dmg;             // Amount of damage dealt
  int attackInterval;  // Time between attacks (in seconds)
  int elapsedTime;     // Time elapsed since the last attack

 public:
  // Constructor
  fileExplorer(int health, int cost, int id, int dmg = 1,
               int attackInterval = 3);
  fileExplorer();

  // Function to attack enemies
  void shoot();

  // Update timer for attack
  void updateTimer(int deltaTime);
};

#endif
