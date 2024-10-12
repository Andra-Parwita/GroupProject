#include "vpn.h"

#include <chrono>
#include <iostream>
#include <thread>

// Constructor
vpn::vpn(int health, int cost, int id, int dmg, float slow, int slowDuration,
         int attackInterval)
    : application(health, cost, id),
      dmg(dmg),
      slow(slow),
      slowDuration(slowDuration),
      attackInterval(attackInterval),
      elapsedTime(0) {}

vpn::vpn()
    : application(100, 25, 3),
      dmg(1),
      slow(1.25),
      slowDuration(3),
      attackInterval(5) {}

void vpn::shootSlow() {
  std::cout << "vpn shoots, dealing " << dmg  // remove later
            << " damage and slowing the enemy by " << slow << "% for "
            << slowDuration << " seconds.\n";
  // Additional logic to deal damage and apply slow effect to an enemy can be
  // added here
}

// Update timer and trigger attacks if the interval has passed
void vpn::updateTimer(int deltaTime) {
  elapsedTime += deltaTime;  // Increment elapsed time
  if (elapsedTime >= attackInterval) {
    std::this_thread::sleep_for(std::chrono::seconds(attackInterval));
    shootSlow();      // Attack and slow the enemy
    elapsedTime = 0;  // Reset elapsed time after attacking
  }
}
