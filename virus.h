#ifndef VIRUS_H
#define VIRUS_H

class virus {
 protected:
  // variables
  int id;
  int speed;
  int health;
  bool isAlive;

 public:
  // constructors
  virus();
  virus(int health, int speed, int id);
  ~virus();

  // setters
  void setId(int id);
  void setHealth(int health);
  void setSpeed(int speed);
  void setStatus(bool status);

  // accessors
  int getId();
  int getHealth();
  int getSpeed();
  bool checkAlive();
};

#endif
