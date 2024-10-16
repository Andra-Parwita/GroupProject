#ifndef VIRUS_H
#define VIRUS_H

#include <SFML/Graphics.hpp>
#include <iostream>

class virus {
 protected:
  // variables
  int id;
  float tileTime;  // higher tileTime value = lower speed
  int health;
  int dmg;
  bool isAlive;
  int currentRow;
  float position_x;
  float position_y;
  bool freeze;  // whether it can move or not
  int segmentId;
  bool explosionCheck;

  sf::Clock internalClock;
  sf::Clock dmgClock;

 public:
  // constructors
  virus();
  virus(int row);
  virus(int health, float tileTime, int id, int dmg);
  ~virus();

  // setters
  void setId(int id);
  void setHealth(int health);
  void setTileTime(float tileTime);
  void setDmg(int dmg);
  void setStatus(bool status);
  void setRow(int row);
  void setPosX(float x);
  void setPosY(float y);
  void setPosXY(float x, float y);
  void setFreeze(bool state);
  void restartClock();
  void setSegmentid(int id);
  void setExplosionCheck(bool check);

  // accessors
  int getId();
  int getHealth();
  float getTileTime();
  int getDmg();
  float getPosX();
  float getPosY();
  bool checkAlive();
  int getRow();
  int getDmgClock();
  int getSegmentId();
  bool getExplosion();

  // movement & specialised functions
  virtual bool move();
};

#endif
