#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
using namespace std;
#ifndef POWERUP_H_
#define POWERUP_H_

#include "Addon.h"

class Powerup : public Addon
{

public:
	Powerup(string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
	}
	Sprite& powerimg()
	{
		return sprite;
	}
	Texture& powertext()
	{
		return tex;
	}
	virtual ~Powerup() {}
};

#endif 

