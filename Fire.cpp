#ifndef FIRE_CPP
#define FIRE_CPP


#include "Fire.h"

Fire::Fire():AddOn(){
	tex.loadFromFile("img/PNG/Power-ups/powerupRed_bolt.png");
	sprite.setTexture(tex);
	killed = 0;
	
	sprite.setPosition(x,0);
}

void Fire::fall(){
	sprite.setPosition(x,sprite.getPosition().y+0.3);
}

void Fire::checkShip(int x, int y, int& health, int& lives, bool& fir){

	if ((x <= sprite.getPosition().x + 20 && x >= sprite.getPosition().x - 40) && (y >= sprite.getPosition().y - 20 && y <= sprite.getPosition().y + 20)){
		fir = 1;
		sprite.setPosition(340,800);
	}
}


#endif
