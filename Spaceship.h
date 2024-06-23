#ifndef SPACESHIP_H
#define SPACESHIP_H


#include <SFML/Graphics.hpp>
#include<string.h>
#include "Bullet.cpp"
#include "AddOn.h"
using namespace sf;

class Spaceship{
public:
	Texture tex;
	Sprite sprite;
	int health;
	int lives;
	bool fir;
	AddOn* add;
	//int level;
	float speed=0.1;
	int x,y;
	Spaceship(std::string png_path);

	void moveBullet(Bullet* n, int direction);

	void moveFireBullet(Bullet* n, int direction);

	void fire(Bullet* n);

	void move(std::string s);

};


#endif
