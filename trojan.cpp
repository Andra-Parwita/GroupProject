#include "trojan.h"

// Constructor
trojan::trojan(int health, float tileTime, int id, int dmg)
    : virus(300, 3.0, 0, 10) {}

trojan::trojan() : virus(300, 3.0, 0, 10) {}