#ifndef SPACESHIP_CPP
#define SPACESHIP_CPP

#include "Spaceship.h"

Spaceship::Spaceship(std::string png_path)
{
	tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	health = 2999;
	lives=3;
	fir=0;
	x=340;y=650;
	add=nullptr;
	sprite.setPosition(x,y);
	sprite.setScale(0.75,0.75);
}

void Spaceship::moveBullet(Bullet* n, int direction){
	static int i=1;
	//n->sprite.move(0,-0.1);
	n->sprite.setPosition(n->sprite.getPosition().x + (i*direction*50),n->sprite.getPosition().y-i);
	i++;
	if (i == 640){
		i = 0;
	}
}

void Spaceship::moveFireBullet(Bullet* n, int direction){

	static int i=1;
	//n->sprite.move(0,-0.1);
	n->sprite.setPosition(sprite.getPosition().x+40,sprite.getPosition().y-i);
	i++;
	if (i == 640){
		i = 0;
	}
}

void Spaceship::fire(Bullet* n){
	n->sprite.setPosition(x+30,y-5);
	//n->sprite.move(0,-0.01);
}

void Spaceship::move(std::string s){
	float delta_x=0,delta_y=0;
	if(s=="l")
		delta_x = -1;

	else if(s=="r")
		delta_x = 1;
		
	if(s=="u")
		delta_y=-1;

	else if(s=="d")
		delta_y=1;
		
	//SETUP FOR ANOMALY
	x += delta_x;
	y += delta_y;
	
	if (x + delta_x < 0){
		x = 740;
		delta_x = 0;
	}
	if (x + delta_x > 740){
		x = 0;
		delta_x = 0;
	}
	if(y + delta_y < 0){
		y = 650;
		delta_y = 0;
	}
	if(y + delta_y > 650){
		y = 0;
		delta_y = 0;
	}
	
	sprite.setPosition(x,y);
	
	delta_x*=speed;
	delta_y*=speed;


	sprite.move(delta_x, delta_y);
	
}

#endif
