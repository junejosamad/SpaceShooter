#ifndef DRAGON_H_
#define DRAGON_H_
using namespace std;
#include "Enemy.h"

class Dragon: public Enemy {
public:
	Dragon(){}
	virtual	void setimage( string png_path){
	tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	}
	Sprite &eneimg(){
		return sprite;
	}
	Texture &entext(){
		return tex;
	}
	virtual ~Dragon(){}
};

#endif /* DRAGON_H_ */
