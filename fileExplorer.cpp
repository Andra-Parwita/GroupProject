#include "fileExplorer.h"

#include <chrono>
#include <iostream>
#include <thread>

// Constructor
fileExplorer::fileExplorer(int health, int cost, int id, int dmg,
                           int attackInterval)
    : application(health, cost, id),
      dmg(dmg),
      attackInterval(attackInterval),
      elapsedTime(0) {}

// Simulate shooting (dealing damage)
void fileExplorer::shoot() {
  std::cout << "fileExplorer shoots dealing " << dmg << " damage!\n";
  // Here you could reduce an enemy's health or manage the attack
}

// Update timer and trigger attacks if the interval has passed
void fileExplorer::updateTimer(int deltaTime) {
  elapsedTime += deltaTime;  // Increment elapsed time
  if (elapsedTime >= attackInterval) {
    // Shoot and reset the elapsed time
    shoot();
    elapsedTime = 0;
    std::this_thread::sleep_for(std::chrono::seconds(attackInterval));
  }
}
