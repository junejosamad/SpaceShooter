#include <SFML/Graphics.hpp>
#include<string.h>
#include"Bullet.h"
#include <iostream>
#include"Powerup.h"
#include "Addon.h"
using namespace std;
using namespace sf;
class Player {
    Texture tex;
    Sprite sprite;
    float speed = 0.75;
    int x, y;
public:
    
    Player(string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        x = 340;y = 622;

        sprite.setPosition(x, y);
        sprite.setScale(0.65, 0.65);
    }
    void pbullet(Bullet*& b) {
        b->bspritee().move(0, -0.9);
    }

    void move(string s)
    {
        int rotatec1 = 0, rotatec2 = 0;
        int rotatecr = 0;
        float delta_x = 0, delta_y = 0;
        if (s == "l") {
            delta_x = -1;

        }
        else if (s == "r") {
            delta_x = 1;

        }
        if (s == "u") {
            delta_y = -1;

        }
        else if (s == "d")
            delta_y = 1;
        delta_x *= speed;
        delta_y *= speed;

        sprite.move(delta_x, delta_y);

    }
    void rotatefun(int rotate)
    {
        if (rotate == 1)
            tex.loadFromFile("img/player_ship_left_rotate.png");
        if (rotate == 2)
            tex.loadFromFile("img/player_ship_right_rotate.png");
        if (rotate == 0)
            tex.loadFromFile("img/player_ship.png");
    }
    void rotatemoveL(Bullet*& b)
    {
        b->bspritee().move(-0.9, 0);

    }
    void rotatemoveR(Bullet*& b)
    {
        b->bspritee().move(0.9, 0);

    }
    void powerbullet(Powerup*& b) {
        b->powerimg().move(0, -0.9);
    }
    void protatemoveL(Powerup*& b)
    {
        b->powerimg().move(-0.9, 0);

    }
    void protatemoveR(Powerup*& b)
    {
        b->powerimg().move(0.9, 0);

    }
    Sprite& spritee()
    {
        return this->sprite;
    }

};
