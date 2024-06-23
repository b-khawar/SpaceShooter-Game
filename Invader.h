#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bullet.cpp"
#include "Bomb.cpp"
#include "Spaceship.cpp"
#include <cstdlib>
using namespace std;
using namespace sf;

class Invader:public Enemy{

public:
	string path;
	int* health;
	Texture* tex;
	Sprite* sprite;
	int shape;
	int size;
	float bomb_time;
	Bomb* b;
	int bomb_x;
	float delta_x;
	bool bomb_killed;
	
	
	Invader(string png_path);
	
	void makeShapes(int level);
	
	void checkCollision(Bullet b[20], Spaceship& player);
	
	virtual void healthCheck(int&,int)=0;

	void checkShip(Spaceship& player);
	
	virtual void fall_bomb(RenderWindow& window)=0;
	
	void move(int level);
	
	int get_minX();
	int get_maxX();
	
	~Invader();
	
};
