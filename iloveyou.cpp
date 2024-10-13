#include "iloveyou.h"

// Constructor
iloveyou::iloveyou(int health, float tileTime, int id, int dmg)
    : virus(120, 2.0, 4, 15) {
        this->isAlive = true;//movement in seconds
        this->rowSwitcher = 0;
    }

iloveyou::iloveyou() : virus(120, 2.0, 4, 15) {
    this->isAlive = true; //movement in seconds
    this->rowSwitcher = 0;
}  

iloveyou::~iloveyou(){};

bool iloveyou::move(){
    if (freeze == false){
        if ((virus::checkAlive() == true) && (health > 0)){
            if(internalClock.getElapsedTime().asSeconds() >= ((tileTime)+((rand()%1000)/1000))){
                std::cout << "moved to: " << position_x -85 << "at: " << internalClock.getElapsedTime().asSeconds()  << std::endl;
                virus::setPosX(position_x -85);
                this->rowSwitcher = rand() %2; //apparently more random
                std::cout << "Row Switcher is: " << rowSwitcher << std::endl;
                switch (rowSwitcher)
                {
                case 1:
                    if ((position_y -150) > 200.0f ){ //up
                        virus::setPosY(position_y -150);
                        this->setRow(this->getRow() - 1);
                        std::cout << "moved y to: " << position_y << std::endl;
                    }
                    break;
                
                default: //case 0
                    if (((position_y +150) < 950.0f  )){ //down
                        virus::setPosY(position_y +150);
                        this->setRow(this->getRow() + 1);
                        std::cout << "moved y to: " << position_y << std::endl;
                    }
                    break;
                }
                internalClock.restart(); 
                return true;
            }
        }
    } else if (freeze == true){
        return false;
    }
    return false;
}
