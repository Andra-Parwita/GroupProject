#include <iostream>

#include "vpn.h"

int main() {
  vpn myVpn(100, 25, 3);  // Initialize VPN with health, cost, and ID
  int gameTime = 0;
  int deltaTime = 1;  // Each loop iteration simulates 1 second of game time

  // Simulate a 10-second game loop
  while (gameTime < 10) {
    std::cout << "Time: " << gameTime << "s\n";
    myVpn.updateTimer(deltaTime);  // Update vpn's timer
    gameTime += deltaTime;  // Increment game time by deltaTime (1 second)
  }

  return 0;
}
