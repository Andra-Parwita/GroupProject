#include "logicBomb.h"

// Constructor
logicBomb::logicBomb(int health, float tileTime, int id, int dmg)
    : virus(100, 2.0, 3, 10) {
        this->isAlive = true;
        this->explosionCheck = false;
        if (!soundBuffer.loadFromFile("./SFX/EnemyEx.wav")){ //
		std::cout << "Could not load Explode sound" << std::endl;
	}
	explosionSound.setBuffer(soundBuffer);
    once = false;
    }

logicBomb::logicBomb() : virus(100, 2.0, 3, 10) {
    this->isAlive = true;
    this->explosionCheck = false;
    if (!soundBuffer.loadFromFile("./SFX/EnemyEx.wav")){ //
		std::cout << "Could not load Explode sound" << std::endl;
	}
	explosionSound.setBuffer(soundBuffer);
    once = false;
}

logicBomb::~logicBomb(){}

bool logicBomb::move() {
    if ((freeze == true) || (explosionCheck == true)) { //checks if it can explode
        // std::cout << internalExClock.getElapsedTime().asSeconds() << std::endl;
        if (internalExClock.getElapsedTime().asSeconds() >= 5.0f) { //if it is on an app for 5 secs, explodes
            if (!once){
                explosionSound.play();
            }
            std::cout << "exploded" << std::endl;
            this->explosionCheck = true;

            if (internalExClock.getElapsedTime().asSeconds() >= 5.5f) { //delays death so explosion can render
                std::cout << "is dead" << std::endl;
                this->health = 0;
                this->setStatus(false);
                return false;
            }
        }
    } else if ((freeze == false) && (explosionCheck == false)) {  // Move only if not frozen or exploding
        internalExClock.restart();
        if (this->explosionCheck == false){
            if ((virus::checkAlive() == true) && (health > 0)) {
                if (internalClock.getElapsedTime().asSeconds() >= ((tileTime))) {
                    // std::cout << "moved to: " << position_x - 85 << " at: " << internalClock.getElapsedTime().asSeconds()  << std::endl;
                    virus::setPosX(position_x - 85);
                    internalClock.restart();
                    return true;
                }
             }
        }
    }
    return false;
}

