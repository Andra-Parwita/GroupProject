#include "fileExplorer.h"

int main() {
  fileExplorer f1(100, 50,
                  1);  // Create a fileExplorer with health, cost, and ID
  int gameTime = 0;
  int deltaTime = 1;  // Each loop iteration simulates 1 second of game time

  // Simulate a 10-second game loop
  while (gameTime < 10) {
    f1.updateTimer(deltaTime);  // Update fileExplorer's timer
    gameTime += deltaTime;      // Increment game time
  }

  return 0;
}
