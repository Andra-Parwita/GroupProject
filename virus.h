#ifndef VIRUS_H
#define VIRUS_H

class virus {
 protected:
  // variables
  int id;
  float tileTime;  // higher tileTime value = lower speed
  int health;
  int dmg;
  bool isAlive;

 public:
  // constructors
  virus();
  virus(int health, float tileTime, int id, int dmg);
  ~virus();

  // setters
  void setId(int id);
  void setHealth(int health);
  void setTileTime(float tileTime);
  void setDmg(int dmg);
  void setStatus(bool status);

  // accessors
  int getId();
  int getHealth();
  int getTileTime();
  int getDmg();
  bool checkAlive();
};

#endif
