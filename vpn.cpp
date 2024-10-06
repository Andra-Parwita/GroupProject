#include "vpn.h"

#include <iostream>

// Constructor with default high health (500) and low cost (10)
vpn::vpn(int health, int cost, int id) : application(500, 10, 2) {}
vpn::vpn() : application (500, 10, 2){}
