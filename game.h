
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Alpha.cpp"
#include "Beta.cpp"
#include "Gamma.cpp"
#include "Monster.cpp"
#include "Dragon.cpp"
#include "Danger.cpp"
#include "Lives.cpp"
#include "Fire.cpp"
#include <iostream>
using namespace std;
#include "Spaceship.cpp"


const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
	Sprite background; //Game background sprite
	Texture bg_texture;
	Spaceship* p; //player 
	// add other game attributes
	//Enemy* e   //Enemy
	//Invader* invader;
	int level;
	int score;
	Invader* a;
	Monster* m;
	Dragon* d;
	
	int direction;

	Game();
	void start_game();
	
};

