#include "virus.h"


//constuctors
virus::virus() : health(0), tileTime(0), id(99), dmg(0), isAlive(false), currentRow(99){srand(time(NULL)); segmentId = 0; explosionCheck = false;}
virus::virus(int row) : health(0), tileTime(0), id(99), dmg(0), isAlive(false), currentRow(row){srand(time(NULL)); segmentId = 0; explosionCheck = false;}
virus::virus(int health, float tileTime, int id, int dmg)
    : health(health), tileTime(tileTime), id(id), dmg(dmg), isAlive(false){srand(time(NULL)); segmentId = 0;}
virus::~virus() {}

// setters
void virus::setId(int id) { this->id = id; }
void virus::setHealth(int health) { this->health = health; }
void virus::setTileTime(float tileTime) { this->tileTime = tileTime; }
void virus::setDmg(int dmg) { this->dmg = dmg; }
void virus::setStatus(bool status) { this->isAlive = status; }

void virus::setRow(int row){this->currentRow = row;}
void virus::setPosX(float x){this->position_x = x;}
void virus::setPosY(float y){this->position_y = y;}
void virus::setPosXY(float x, float y){virus::setPosX(x); virus::setPosY(y);}
void virus::setFreeze(bool state){this->freeze = state;}
void virus::restartClock(){dmgClock.restart();}
void virus::setSegmentid(int id){this->segmentId = id;}
void virus::setExplosionCheck(bool check){this->explosionCheck = check;}

// accessors
int virus::getId() { return this->id; }
int virus::getHealth() { return this->health; }
float virus::getTileTime() { return this->tileTime; }
int virus::getDmg() { return this->dmg; }
bool virus::checkAlive() { return this->isAlive; }
float virus::getPosY(){return this->position_y;}
float virus::getPosX(){return this->position_x;}
int virus::getRow(){return this->currentRow;}
int virus::getDmgClock(){return dmgClock.getElapsedTime().asSeconds();}
int virus::getSegmentId(){return this->segmentId;}
bool virus::getExplosion(){return this->explosionCheck;}


//movement
bool virus::move(){
    if (freeze == false){ //checks if frozen (on app tile)
        if ((virus::checkAlive() == true) && (health > 0)){ //checks if the virus is still alive
            if(internalClock.getElapsedTime().asSeconds() >= ((tileTime)+((rand()%1000)/1000))){ //how often it can move
                // std::cout << "moved to: " << position_x -85 << "at: " << internalClock.getElapsedTime().asSeconds()  << std::endl;
                virus::setPosX(position_x -85);
                internalClock.restart(); 
                return true;
            }
        }
    } else if (freeze == true){
        return false;
    }
    return false;
}
