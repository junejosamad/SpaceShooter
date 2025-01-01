#ifndef ALPHA_H_
#define ALPHA_H_
using namespace std;

#include "Invaders.h"

class Alpha : public Invaders {
public:
	Alpha() {}
	virtual	void setimage(string png_path) {
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);

	}

	Sprite& eneimg() {
		return sprite;
	}
	Texture& entext() {
		return tex;
	}
	virtual ~Alpha() {}
};

#endif /* ALPHA_H_ */
