#include "vscode.h"

// Constructor
vscode::vscode(int health, int cost, int id, int memoryProductionRate,
               int productionInterval)
    : application(health, cost, id),
      memoryProduction(memoryProduction),
      productionInterval(productionInterval),
      elapsedTime(0) {}

// Produce memory every productionInterval seconds
int vscode::produceMemory() {
  return memoryProduction;  // Return the memory produced
}

// Update the timer and check for memory production
void vscode::updateTimer(int deltaTime) {
  elapsedTime += deltaTime;  // Increment elapsed time by deltaTime
  if (elapsedTime >= productionInterval) {
    // Reset elapsed time and produce memory
    elapsedTime = 0;
    // You might want to do something with the produced memory, like adding it
    // to a total
    produceMemory();
  }
}
