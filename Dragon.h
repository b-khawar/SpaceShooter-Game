#include "Enemy.h"
#include "Bullet.cpp"
#include "Spaceship.cpp"

class Dragon:public Enemy{

public:
	Sprite sprite;
	Texture tex;
	int bullet_x;
	Bullet bull[340];
	bool killed;
	
	Dragon();
	void attack(RenderWindow& win, Spaceship& player);
	void checkShip(Spaceship& player);
};
