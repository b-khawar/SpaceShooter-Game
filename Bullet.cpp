#ifndef BULLET_CPP
#define BULLET_CPP

#include "Bullet.h"

Bullet::Bullet(){ sprite.setPosition(800,800); }

Bullet::Bullet(std::string png_path)
{
	tex.loadFromFile(png_path);
	sprite.setTexture(tex);
}

#endif
