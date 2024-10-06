#include "vscode.h"

int main() {
  vscode v1(100, 15,
            2);  // Create a vscode with health, cost, and ID
  int gameTime = 0;
  int deltaTime = 1;  // Each loop iteration simulates 1 second of game time

  // Simulate a 10-second game loop
  while (gameTime < 10) {
    v1.updateTimer(deltaTime);  // Update vscode's timer
    gameTime += deltaTime;      // Increment game time
  }

  return 0;
}
