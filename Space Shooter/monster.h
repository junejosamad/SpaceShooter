#ifndef MONSTER_H_
#define MONSTER_H_
using namespace std;
#include "Enemy.h"

class Monster: public Enemy {
public:
	Monster(){}
	virtual	void setimage(string png_path){
	tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	}
	Sprite &eneimg(){
		return sprite;
	}
	Texture &entext(){
		return tex;
	}
 
	virtual ~Monster(){}

};

#endif /* MONSTER_H_ */
