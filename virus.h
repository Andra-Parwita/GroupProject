#ifndef VIRUS_H
#define VIRUS_H

class virus {
 protected:
  // variables
  int id;
  float tileTime;  // higher tileTime value = lower speed
  int health;
  bool isAlive;

 public:
  // constructors
  virus();
  virus(int health, float tileTime, int id);
  ~virus();

  // setters
  void setId(int id);
  void setHealth(int health);
  void setTileTime(float tileTime);
  void setStatus(bool status);

  // accessors
  int getId();
  int getHealth();
  int getTileTime();
  bool checkAlive();
};

#endif
