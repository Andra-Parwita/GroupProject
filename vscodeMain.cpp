#include "vscode.h"
using namespace std;

int main() {
  vscode Obj;
  cout << Obj.getDesc() << endl;
  cout << "DMG: " << Obj.getDmg() << endl;
  cout << "HEALTH: " << Obj.getHealth() << endl;
  cout << "X: " << Obj.getAppPosition().x << " Y: " << Obj.getAppPosition().y << endl;

  return 0;
}
