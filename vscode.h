#ifndef VSCODE_H
#define VSCODE_H

#include "application.h"

class vscode : public application {
 private:
  int memoryProduction;    // Amount of memory produced
  int productionInterval;  // Time interval for memory production (in seconds)
  int elapsedTime;         // Time elapsed since last memory production

 public:
  // Constructor
  vscode(int health, int cost, int id, int memoryProduction = 5,
         int productionInterval = 3);

  // Function to produce memory
  int produceMemory();

  // Update the timer and check for memory production
  void updateTimer(int deltaTime);
};

#endif
