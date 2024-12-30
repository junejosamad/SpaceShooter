#ifndef DRAGONFIRE_H_
#define DRAGONFIRE_H_

#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
using namespace std;
class dragonfire {
public:
Texture btex;
Sprite bsprite;
dragonfire(std::string png_path)
{
    btex.loadFromFile(png_path);
    bsprite.setTexture(btex);
   
}
~dragonfire(){}
};

#endif /* DRAGONFIRE_H_ */
