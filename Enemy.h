#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include "bomb.h"
using namespace std;
using namespace sf;
#ifndef ENEMY_H_
#define ENEMY_H_


class Enemy{
	protected:
	Texture tex;
	Sprite sprite;
		
public:
 
	Enemy(){
	}
	 virtual void setimage(string png_path)=0;

	void bombmove(bomb* &a){
		a->spritee().move(0,0.9);

	} 
	virtual Sprite &eneimg()=0;
	
	virtual Texture &entext()=0;
	
	


	virtual ~Enemy() {}
	
};
