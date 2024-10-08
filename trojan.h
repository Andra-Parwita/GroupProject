#include "trojan.h"

// Constructor
trojan::trojan(int health, float tileTime, int id, int dmg)
    : virus(75, 1.0, 0, 10) {}

trojan::trojan() : virus(75, 1.0, 0, 10) {}