#include "antivirus.h"

#include <iostream>

// Constructor
antivirus::antivirus(int health, int cost, int id) : application(500, 10, 2) {}
antivirus::antivirus() : application(500, 10, 2) {Desc = "FireWall \n Cost: 10 \n Dummy Thicc FireWall that blocks stuff \n Literally just has lots of health \n 5 Sec Cooldown";}
