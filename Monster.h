#include "Enemy.h"
#include "Spaceship.cpp"

class Monster:public Enemy{

public:
	Sprite sprite;
	Texture tex;
	Bullet bul[300];
	int bullet_x;
	int bul_no;
	bool killed;
	float delta_x;
	
	Monster();
	void attack(RenderWindow& win);
	void checkShip(Spaceship& player);
	void move(int level);
};
