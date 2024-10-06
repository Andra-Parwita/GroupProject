#ifndef VPN_H
#define VPN_H

#include "application.h"

class vpn : public application {
 public:
  // Constructor
  vpn(int health, int cost, int id);
  vpn();
};

#endif
