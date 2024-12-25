
#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
using namespace std;
class Bullet {
    Texture btex;
    Sprite bsprite;
public:

    Bullet(string png_path)
    {
        btex.loadFromFile(png_path);
        bsprite.setTexture(btex);

    }
    Sprite& bspritee() {
        return this->bsprite;
    }
    Texture& btexe() {
        return btex;
    }
    ~Bullet() {}
};
#endif 
