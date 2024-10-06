#ifndef VPN_H
#define VPN_H

#include "application.h"

class vpn : public application {
 private:
  int dmg;             // Damage dealt
  float slow;          // Amount of slow
  int slowDuration;    // Duration of slow effect
  int attackInterval;  // Time between attacks (in seconds)
  int elapsedTime;     // Time elapsed since the last attack

 public:
  // Constructor
  vpn(int health, int cost, int id, int dmg = 1, float slow = 1.25,
      int slowDuration = 3, int attackInterval = 5);
  vpn();

  void shootSlow();  // Slow function

  void updateTimer(int deltaTime);
};

#endif
