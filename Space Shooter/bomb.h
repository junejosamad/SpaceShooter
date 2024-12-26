#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
#ifndef BOMB_H_
#define BOMB_H_

class bomb {
 
        Texture tex;
        Sprite sprite;
        float speed=0.5;
public:

        bomb(string png_path){
                tex.loadFromFile(png_path);
                sprite.setTexture(tex);

        }

		Sprite& spritee(){
			return sprite;
		}
	
	virtual ~bomb(){}
};

#endif /* BOMB_H_ */
