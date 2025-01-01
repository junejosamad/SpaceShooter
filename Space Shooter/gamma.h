#ifndef GAMMA_H_
#define GAMMA_H_
using namespace std;

#include "Invaders.h"

class Gamma: public Invaders {
public:
	Gamma(){}
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
	virtual ~Gamma(){}
};

#endif /* GAMMA_H_ */
