#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Bullet{
public:
	Texture tex;
	Sprite sprite;
	
	Bullet();
	
	Bullet(std::string png_path);
	
};

#endif
