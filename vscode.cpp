#include "vscode.h"

#include <chrono>
#include <iostream>
#include <thread>

// Constructor
vscode::vscode(int health, int cost, int id, int memoryProduction,
               int productionInterval)
    : application(100, 5, 0),
      memoryProduction(memoryProduction),
      productionInterval(productionInterval),
      elapsedTime(0) {}
 vscode::vscode() :  application(100,5,0), memoryProduction(5), productionInterval(3){Desc = "VsCode \n Cost: 5 \n Makes you more RAM?! SOMEHOW? \n +1 mb/s";}