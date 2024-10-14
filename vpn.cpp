#include "vpn.h"

#include <iostream>

// Constructor
vpn::vpn(int health, int cost, int id, int dmg, int attackInterval)
    : attackInterval(attackInterval) {
  dmg = 5;
  health = 100;
  cost = 25;
  id = 3;
  Desc =
      "VPN \n Cost: 25 \n Will exponentially slow enemies on impact, \n Deals "
      "very little damage \n 3 Sec Cooldown";
  if (!buffer.loadFromFile("./SFX/FreezeShoot.wav")){ //
		std::cout << "Could not load Freeze Shoot sound" << std::endl;
	}
	sound.setBuffer(buffer);
}
vpn::vpn() : attackInterval(10) {
  dmg = 5;
  health = 100;
  cost = 25;
  id = 3;
  Desc =
      "VPN \n Cost: 25 \n Will exponentially slow enemies on impact, \n Deals "
      "very little damage \n 3 Sec Cooldown";
  if (!buffer.loadFromFile("./SFX/FreezeShoot.wav")){ //
		std::cout << "Could not load Freeze Shoot sound" << std::endl;
	}
	sound.setBuffer(buffer);
}

vpn::~vpn() {}
// Simulate shooting (dealing damage)
void vpn::shoot() {
  if (projectiles.size() >= 10) {  // Adjust 10 as needed
    return;  // Prevent shooting if max projectiles are active
  }

  if (internalClock.getElapsedTime().asSeconds() >= attackInterval) {
    std::cout << "vpn shoots" << std::endl;
    sound.play();

    sf::CircleShape bullet;
    bullet.setRadius(5);
    bullet.setFillColor(sf::Color::Green);
    bullet.setOrigin(5, 5);
    bullet.setPosition(this->AppPosition.x + 10,
                       this->AppPosition.y + 25);  // off setting
    projectiles.push_back(bullet);

    internalClock.restart();
  }
}

// Update timer and trigger attacks if the interval has passed
std::vector<sf::CircleShape>* vpn::update(sf::FloatRect pos) {
  shoot();

  for (int i = 0; i < projectiles.size();) {
    if (internalClockMove.getElapsedTime().asSeconds() >= 0.01) {
      projectiles[i].move(5.f, 0.f);  // Move to the right
      internalClockMove.restart();
    }

    // Remove projectiles that are off-screen
    if ((projectiles[i].getPosition().x > 2000) ||
        (projectiles[i].getGlobalBounds().intersects(pos))) {
      projectiles.erase(projectiles.begin() + i);  // Remove the projectile
    } else {
      i++;  // Only increment if we didn't erase an element
    }
  }
  return &projectiles;
}
