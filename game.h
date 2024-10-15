#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#include "gameController.h"
#include "grid.h"
#include "virus.h"

class Game {
 private:
  // Variables
  sf::RenderWindow* window;  // window
  sf::VideoMode videoMode;   // window size params
  sf::Event ev;  // gets curent input events on the window (continuous)

  // gameObject
  sf::RectangleShape** dispTiles;         // Tile sprites (boxes)
  sf::RectangleShape** appSpriteHolders;  // The sprite holders in

  sf::RectangleShape* taskBar;         // the actual task bar
  sf::RectangleShape* taskBarSprites;  // the sprites within the task bar
  sf::Clock PopupBoxTimer;
  bool inBar;
  sf::Clock gridIndicatorTimer;
  bool inGrid;

  // mapdata
  grid* gridMap;  // actual map data

  // fonts and text
  sf::Font font;       // font
  sf::Text timerText;  //
  sf::Text resourceText;

  sf::Text PopDisplayText;

  // gameController
  gameController* gameManager;  // pointer to game controller
  int currentSelectionId;       // current selected app id

  // virus handler
  virus** virusManager;              // handles all the viruses
  sf::RectangleShape* virusSprites;  // hands the virus sprites
  int maxVirusSpritesSpace;  // max space allocated for virus sprites (remove if
                             // changing to vector)
  sf::Clock virusExplosionClock;

  // projectile
  std::vector<sf::CircleShape>** projected;  // stores all projectile arrays which hold each projectile
  int projectileCount;  // the number of projectile vectors

  std::vector<sf::CircleShape>** slowed;
  int slowCount;

  std::vector<sf::CircleShape>** explosions;
  int explosionCount;

  // clock
  sf::Clock clock;  // internal clock
  int fiveSec;      //
  sf::Clock waveTimer;
  sf::Clock* appCooldownClocks;

  bool gameOver;
  sf::Text GameOverText;

  //sound
  sf::SoundBuffer* soundBuffers;
  sf::Sound enemyhitSound;
  sf::Sound apphitSound;
  sf::Sound selectSound;
  sf::Sound explosionSound;

  // init functions
  void initVariables();  // initalises variables
  void initWindow();     // starts the window
  void initMap();
  void initBar();
  void initText();
  void initVirus();
  void initSound();

  // private functions
  bool taskBarChecker(int i);
  bool gridMapChecker(int x, int y);

 public:
  // constuctors and destructors
  Game();
  ~Game();

  // accessor
  const bool getWindowIsOpen() const;

  // Functions
  void pollEvents();
  void update();
  void render();
  void cleanUpDeadVirusesSprites();

  void spawnEnemy(int id);
};

#endif