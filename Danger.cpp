#ifndef DANGER_CPP
#define DANGER_CPP

#include "Danger.h"

Danger::Danger():AddOn(){
	tex.loadFromFile("img/PNG/Power-ups/powerupRed.png");
	sprite.setTexture(tex);
	
	killed = 1;
	sprite.setPosition(x,0);
}

void Danger::fall(){
	sprite.setPosition(x,sprite.getPosition().y+0.3);
}

void Danger::checkShip(int x, int y, int& health, int& lives, bool& fir){

	if ((x <= sprite.getPosition().x + 20 && x >= sprite.getPosition().x - 40) && (y >= sprite.getPosition().y - 20 && y <= sprite.getPosition().y + 20)){
	
		health = 0;
		killed = 2;
		sprite.setPosition(340,800);
	}
}

#endif
