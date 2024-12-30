#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
using namespace std;
class danger {
    	Texture tex;
	Sprite sprite;		
public:
	danger(std::string png_path){
    tex.loadFromFile(png_path);
    sprite.setTexture(tex); 
	}
	Sprite &powerimg(){
		return sprite;
	}
	Texture &powertext(){
		return tex;
	}
	virtual ~danger(){}
};

 
