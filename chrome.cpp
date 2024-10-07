#include "chrome.h"

#include <chrono>
#include <iostream>
#include <thread>

// Constructor
chrome::chrome(int health, int cost, int id, int dmg, int explodeTime)
    : application(100, 500, 4),
      dmg(dmg),
      explodeTime(explodeTime),
      elapsedTime(0),
      explodeRadius(3) {}

chrome::chrome() : application(100,500,4), dmg(100), explodeTime(3), elapsedTime(0), explodeRadius(3){}

// Explode funciton
void chrome::explode() {
  // Additional explode functionality.
}

// Update timer and trigger explosion if the time has passed
void chrome::updateTimer(int deltaTime) {
  elapsedTime += deltaTime;  // Increment elapsed time
  if (elapsedTime >= explodeTime) {
    std::this_thread::sleep_for(std::chrono::seconds(explodeTime));
    explode();  // Trigger the explosion
    //
    this->setStatus(false);  // Set the status to 'dead' or destroy
  }
}