#include "vscode.h"

#include <chrono>
#include <iostream>
#include <thread>

// Constructor
vscode::vscode(int health, int cost, int id, int memoryProduction,
               int productionInterval)
    : application(100, 5, 1),
      memoryProduction(memoryProduction),
      productionInterval(productionInterval),
      elapsedTime(0) {}

// Produce memory every productionInterval seconds
int vscode::produceMemory() {
  std::cout << "+ " << memoryProduction << " mB\n";  // remove later
  return memoryProduction;  // Return the memory produced
}

// Update the timer and check for memory production
void vscode::updateTimer(int deltaTime) {
  elapsedTime += deltaTime;  // Increment elapsed time by deltaTime
  if (elapsedTime >= productionInterval) {
    std::this_thread::sleep_for(std::chrono::seconds(productionInterval));
    // Reset elapsed time and produce memory
    elapsedTime = 0;
    // Add memory to total "bank" later
    produceMemory();
  }
}
