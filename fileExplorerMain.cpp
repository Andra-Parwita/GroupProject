#include "fileExplorer.h"

using namespace std;

int main() {
  sf::Clock clock;

  fileExplorer Obj;
  cout << Obj.getDesc() << endl;
  cout << "DMG: " << Obj.getDmg() << endl;
  cout << "HEALTH: " << Obj.getHealth() << endl;
  cout << "X: " << Obj.getAppPosition().x << " Y: " << Obj.getAppPosition().y << endl;
  sf::RectangleShape shape;
  shape.setSize(sf::Vector2f(100.f,100.f));
  sf::FloatRect g = shape.getGlobalBounds();
  
  while (clock.getElapsedTime().asSeconds() <= 10.0f){
    Obj.update(g); //uncomment all of the couts inside fileExplorer to see internal updates
  }

  return 0;
}
