#include "bug.h" //change to which to test
using namespace std;

int main() {
  bug Obj; //change to type
  cout << Obj.checkAlive() << endl;
  cout << "DMG: " << Obj.getDmg() << endl;
  cout << "HEALTH: " << Obj.getHealth() << endl;
  cout << "TIME: " << Obj.getTileTime() << endl;

  return 0;
}
