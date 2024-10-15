#include "fileExplorer.h"

#include <iostream>

// Constructor
fileExplorer::fileExplorer(int health, int cost, int id, int dmg,
                           int attackInterval) :
      attackInterval(attackInterval){
      dmg = 10;
      health = 100;
      cost = 15;
      id = 1;
      Desc = "File Explorer \n Cost: 15 \n Will shoot files \n shoots straight file in a lane \n 3 Sec Cooldown";
      if (!buffer.loadFromFile("./SFX/laserShoot.wav")){ //
		    std::cout << "Could not load Freeze Shoot sound" << std::endl;
	    }
	    sound.setBuffer(buffer);
      internalClockMove = new sf::Clock[11];
  }
fileExplorer::fileExplorer() : attackInterval(3){
    dmg = 10;
    health = 100;
    cost = 15;
    id = 1;
    Desc = "File Explorer \n Cost: 15 \n Will shoot files \n shoots straight file in a lane \n 3 Sec Cooldown";
    if (!buffer.loadFromFile("./SFX/laserShoot.wav")){ 
		  std::cout << "Could not load Freeze Shoot sound" << std::endl;
	  }
	  sound.setBuffer(buffer);
    internalClockMove = new sf::Clock[11];
    
  }

fileExplorer::~fileExplorer(){}
// Simulate shooting (dealing damage)
void fileExplorer::shoot() {
  if (projectiles.size() >= 10) { 
    return; // Prevent shooting if max projectiles are active
  }

  if(internalClock.getElapsedTime().asSeconds() >= attackInterval){
    // std::cout << "fileExplorer shoots" << std::endl;
    sound.play();

    sf::CircleShape bullet; //bullet creation
    bullet.setRadius(5);
    bullet.setFillColor(sf::Color::Cyan);
    bullet.setOrigin(5,5);
    bullet.setPosition(this->AppPosition.x + 10, this->AppPosition.y + 25); //off setting
    projectiles.push_back(bullet);

    internalClock.restart();
  }
}

// Update timer and trigger attacks if the interval has passed
 std::vector<sf::CircleShape>*  fileExplorer::update(sf::FloatRect pos) {
 shoot();
 
 for (int i = 0; i < projectiles.size(); ) {
        
        if(internalClockMove[i].getElapsedTime().asSeconds() >= 0.01){ //checks speed at which projectile moves
          projectiles[i].move(5.f, 0.f); // Move to the right
         internalClockMove[i].restart();
        }

        // Remove projectiles that are off-screen
        if ((projectiles[i].getPosition().x > 2000) || (projectiles[i].getGlobalBounds().intersects(pos))) {
           projectiles.erase(projectiles.begin() + i); // Remove the projectile
        } else {
            i++; // Only increment if we didn't erase an element
        } 
    }
  return &projectiles;
}
