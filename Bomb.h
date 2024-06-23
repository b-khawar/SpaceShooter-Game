#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Bomb{
public:
	Texture tex;
	Sprite sprite;
	float speed=0.1;
	int x,y;
	
	Bomb();
};
