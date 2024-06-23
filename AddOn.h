#ifndef ADDON_H
#define ADDON_H


#include <SFML/Graphics.hpp>
#include <string.h>
#include <cstdlib>
#include <iostream>

using namespace sf;
using namespace std;

class AddOn{
public:
	Texture tex;
	Sprite sprite;
	int x;
	int killed;   //0 for lives and fire, 1 for danger with no colision, 2 for danger with collision
	
	AddOn(){
		srand(time(0));
		x = 10 + (rand()%720);
	}
	
	virtual void fall()=0;
	
	virtual void checkShip(int x, int y, int& health, int& lives, bool& fir)=0;
};


#endif
