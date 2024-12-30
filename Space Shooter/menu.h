#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
using namespace std;
using namespace sf;
#ifndef MENU_H_
#define MENU_H_

class menu{
 	Texture tex;
	Sprite sprite;
	public:
 
    menu(string png_path){
        tex.loadFromFile(png_path);
        sprite.setTexture(tex); 
		sprite.setScale(0.7, 0.8); 
		  
		            
        }
	Sprite pic(){
		return sprite;
	}	

	virtual ~menu(){}
};

#endif /* MENU_H_ */
