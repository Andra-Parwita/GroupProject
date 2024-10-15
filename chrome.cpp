#include "chrome.h"

#include <chrono>
#include <iostream>
#include <thread>

// Constructor
chrome::chrome(int health, int cost, int id, int dmg, int explodeTime)
    : application(100, 25, 4),
      explodeTime(explodeTime),
      elapsedTime(0),
      explodeRadius(3) {Desc = "Chrome \n Cost: 25 \n TOO MUCH RAM! MUST BLOW UP \n Explodes 3x3 \n 8 Sec Cooldown"; dmg = 200;
      if (!buffer.loadFromFile("./SFX/ChromExplosion.wav")){ //
		    std::cout << "Could not load Chrome Shoot sound" << std::endl;
	  }
    sound.setBuffer(buffer); //setting sound 
    once = true; //checking to play sound once
  }

chrome::chrome() : application(100,25,4), explodeTime(2), elapsedTime(0), explodeRadius(3){
  Desc = "Chrome \n Cost: 25 \n TOO MUCH RAM! MUST BLOW UP \n Explodes 3x3 \n 8 Sec Cooldown";
  dmg = 200;
  if (!buffer.loadFromFile("./SFX/ChromExplosion.wav")){ //
		std::cout << "Could not load Chrome Shoot sound" << std::endl;
	}
  sound.setBuffer(buffer);
  once = true;
}

// Explode funciton
bool chrome::explode() {
  //std::cout << internalClock.getElapsedTime().asSeconds() << std::endl;
  if(internalClock.getElapsedTime().asSeconds() >= explodeTime){
    //std::cout << "explosion proj created" << std::endl;
    sf::CircleShape boom; //setting the explosion "projectile"
    boom.setRadius(175);
    boom.setFillColor(sf::Color::Red);
    boom.setOrigin(150,150);
    boom.setPosition(this->AppPosition.x + 10, this->AppPosition.y + 25); //off setting
    explosion.push_back(boom);
    chrome::boomsfx();
    return true;
  }
  return false;
}

void chrome::boomsfx(){ //to play the explosion sound effect once
  if(once){
    sound.play();
    std::cout << "sound played" << std::endl;
    once = false;
  }
}

std::vector<sf::CircleShape>* chrome::update(sf::FloatRect pos){
  //std::cout << "calling?!" << std::endl;
  if (chrome::explode() == true){
    if(internalClock.getElapsedTime().asSeconds() >= 2.5f){ //delays the delete so the explosion can stay
      this->setStatus(false);
      this->setHealth(-1);
      explosion.erase(explosion.begin()); // Remove the projectile
    }
  } 
  return &explosion;
}
