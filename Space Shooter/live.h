#include <SFML/Graphics.hpp>
#include<string.h> 
#include <iostream>
using namespace std;
using namespace sf;
 

class live{
    	Texture tex;
	Sprite sprite;	
public:
	live(std::string png_path){
    tex.loadFromFile(png_path);
    sprite.setTexture(tex); 
 
	}
	Sprite &powerimg(){
		return sprite;
	}
	Texture &powertext(){
		return tex;
	}
 
 
	virtual ~live(){}
};

 
 
 
 
 