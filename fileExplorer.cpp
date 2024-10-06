#include "fileExplorer.h"

#include <chrono>
#include <iostream>
#include <thread>

// Constructor
fileExplorer::fileExplorer(int health, int cost, int id, int dmg,
                           int attackInterval)
    : application(100, 15, 1),
      dmg(dmg),
      attackInterval(attackInterval),
      elapsedTime(0) {}
fileExplorer::fileExplorer() : application(100,15,1), dmg(1), attackInterval(3){}


// Simulate shooting (dealing damage)
void fileExplorer::shoot() {
  std::cout << "fileExplorer shoots dealing " << dmg << " damage!\n";
  // Here add shooting implementation
}

// Update timer and trigger attacks if the interval has passed
void fileExplorer::updateTimer(int deltaTime) {
  elapsedTime += deltaTime;  // Increment elapsed time
  if (elapsedTime >= attackInterval) {
    // Shoot and reset the elapsed time
    std::this_thread::sleep_for(std::chrono::seconds(attackInterval));
    shoot();
    elapsedTime = 0;
  }
}
