#ifndef LIVES_CPP
#define LIVES_CPP


#include "Lives.h"

Lives::Lives():AddOn(){
	tex.loadFromFile("img/PNG/Power-ups/pill_green.png");
	sprite.setTexture(tex);
	killed = 0;
	
	sprite.setPosition(x,0);
}

void Lives::fall(){
	sprite.setPosition(x,sprite.getPosition().y+0.3);
}

void Lives::checkShip(int x, int y, int& health, int& lives, bool& fir){

	if ((x <= sprite.getPosition().x + 20 && x >= sprite.getPosition().x - 40) && (y >= sprite.getPosition().y - 20 && y <= sprite.getPosition().y + 20)){
		if (lives < 3)
			lives += 1;
		health = 2999;
		sprite.setPosition(340,800);
	}
}


#endif
