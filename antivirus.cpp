#include "antivirus.h"

#include <iostream>

// Constructor with default high health (500) and low cost (10)
antivirus::antivirus(int health, int cost, int id) : application(500, 10, 2) {}
