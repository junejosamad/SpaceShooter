#ifndef BETA_H_
#define BETA_H_
using namespace std;

#include "Invaders.h"

class Beta: public Invaders {
public:
	Beta(){}
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
	virtual ~Beta(){}
};

#endif /* BETA_H_ */

