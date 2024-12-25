#include <SFML/Graphics.hpp>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include "Enemy.h"
#include "bullet.h"
#include "player.h"

using namespace sf;
const char title[] = "Space Shooter - OOP Project - Fall 24";
class Game{
private:

public:  
  Game(){
    
  }

  void start_game(){
      srand(time(0));
      RenderWindow window(VideoMode(850,780), title);
      Clock clock,clockmove;
      float timermove=0;
      while(window.isOpen()){
        
      }
  }
};
