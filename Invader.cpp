#ifndef INVADER_CPP
#define INVADER_CPP

#include "Invader.h"

Invader::Invader(string png_path) : Enemy()
{

	path = png_path;
	srand(time(0));
	shape = 1 + rand() % 3;

	bomb_x = (220 + rand() % 240);
	b = new Bomb;
	delta_x = 0.02;
	bomb_killed = 0;
}

void Invader::makeShapes(int level)
{
	if (level == 1)
	{
		if (shape == 1)
		{ // empty triangle

			size = 8;
			health = new int[8];
			tex = new Texture[8];
			sprite = new Sprite[8];
			for (int i = 0; i < 8; ++i)
			{
				tex[i].loadFromFile(path);
				sprite[i].setTexture(tex[i]);
				health[i] = 1000;
			}

			sprite[0].setPosition(340, 340);
			sprite[0].setScale(0.5, 0.5);

			sprite[2].setPosition(400, 280);
			sprite[2].setScale(0.5, 0.5);
			sprite[3].setPosition(280, 280);
			sprite[3].setScale(0.5, 0.5);

			sprite[4].setPosition(340, 220);
			sprite[4].setScale(0.5, 0.5);
			sprite[5].setPosition(400, 220);
			sprite[5].setScale(0.5, 0.5);
			sprite[6].setPosition(460, 220);
			sprite[6].setScale(0.5, 0.5);
			sprite[7].setPosition(280, 220);
			sprite[7].setScale(0.5, 0.5);
			sprite[1].setPosition(220, 220);
			sprite[1].setScale(0.5, 0.5);
		}
		else if (shape == 2)
		{ // cross
			size = 9;
			health = new int[9];
			tex = new Texture[9];
			sprite = new Sprite[9];
			for (int i = 0; i < 9; ++i)
			{
				tex[i].loadFromFile(path);
				sprite[i].setTexture(tex[i]);
				health[i] = 1000;
			}

			sprite[0].setPosition(340, 300);
			sprite[0].setScale(0.5, 0.5);

			sprite[1].setPosition(310, 240);
			sprite[1].setScale(0.5, 0.5);
			sprite[2].setPosition(280, 180);
			sprite[2].setScale(0.5, 0.5);

			sprite[3].setPosition(370, 240);
			sprite[3].setScale(0.5, 0.5);
			sprite[4].setPosition(400, 180);
			sprite[4].setScale(0.5, 0.5);

			sprite[5].setPosition(310, 360);
			sprite[5].setScale(0.5, 0.5);
			sprite[6].setPosition(280, 420);
			sprite[6].setScale(0.5, 0.5);

			sprite[7].setPosition(370, 360);
			sprite[7].setScale(0.5, 0.5);
			sprite[8].setPosition(400, 420);
			sprite[8].setScale(0.5, 0.5);
		}
		else if (shape == 3)
		{ // empty square
			size = 8;
			health = new int[8];
			tex = new Texture[8];
			sprite = new Sprite[8];
			for (int i = 0; i < 8; ++i)
			{
				tex[i].loadFromFile(path);
				sprite[i].setTexture(tex[i]);
				health[i] = 1000;
			}

			sprite[0].setPosition(340, 400);
			sprite[0].setScale(0.5, 0.5);
			sprite[1].setPosition(400, 400);
			sprite[1].setScale(0.5, 0.5);
			sprite[2].setPosition(280, 400);
			sprite[2].setScale(0.5, 0.5);

			sprite[3].setPosition(400, 340);
			sprite[3].setScale(0.5, 0.5);
			sprite[4].setPosition(280, 340);
			sprite[4].setScale(0.5, 0.5);

			sprite[5].setPosition(340, 280);
			sprite[5].setScale(0.5, 0.5);
			sprite[6].setPosition(400, 280);
			sprite[6].setScale(0.5, 0.5);
			sprite[7].setPosition(280, 280);
			sprite[7].setScale(0.5, 0.5);
		}
	}
	else if (level == 2)
	{
		if (shape == 1)
		{ // empty diamond
			size = 8;
			health = new int[8];
			tex = new Texture[8];
			sprite = new Sprite[8];
			for (int i = 0; i < 8; ++i)
			{
				tex[i].loadFromFile(path);
				sprite[i].setTexture(tex[i]);
				health[i] = 1000;
			}

			sprite[0].setPosition(340, 220);
			sprite[0].setScale(0.5, 0.5);
			sprite[1].setPosition(340, 460);
			sprite[1].setScale(0.5, 0.5);

			sprite[2].setPosition(280, 280);
			sprite[2].setScale(0.5, 0.5);
			sprite[3].setPosition(280, 400);
			sprite[3].setScale(0.5, 0.5);

			sprite[4].setPosition(400, 280);
			sprite[4].setScale(0.5, 0.5);
			sprite[5].setPosition(400, 400);
			sprite[5].setScale(0.5, 0.5);

			sprite[6].setPosition(220, 340);
			sprite[6].setScale(0.5, 0.5);
			sprite[7].setPosition(460, 340);
			sprite[7].setScale(0.5, 0.5);
		}
		else if (shape == 2)
		{ // empty circle
			size = 8;
			health = new int[8];
			tex = new Texture[8];
			sprite = new Sprite[8];
			for (int i = 0; i < 8; ++i)
			{
				tex[i].loadFromFile(path);
				sprite[i].setTexture(tex[i]);
				health[i] = 1000;
			}

			sprite[0].setPosition(340, 220);
			sprite[0].setScale(0.5, 0.5);
			sprite[1].setPosition(340, 460);
			sprite[1].setScale(0.5, 0.5);

			sprite[2].setPosition(260, 260);
			sprite[2].setScale(0.5, 0.5);
			sprite[3].setPosition(260, 420);
			sprite[3].setScale(0.5, 0.5);

			sprite[4].setPosition(420, 260);
			sprite[4].setScale(0.5, 0.5);
			sprite[5].setPosition(420, 420);
			sprite[5].setScale(0.5, 0.5);

			sprite[6].setPosition(220, 340);
			sprite[6].setScale(0.5, 0.5);
			sprite[7].setPosition(460, 340);
			sprite[7].setScale(0.5, 0.5);
		}
		else if (shape == 3)
		{ // empty heart
			size = 8;
			health = new int[8];
			tex = new Texture[8];
			sprite = new Sprite[8];
			for (int i = 0; i < 8; ++i)
			{
				tex[i].loadFromFile(path);
				sprite[i].setTexture(tex[i]);
				health[i] = 1000;
			}

			sprite[0].setPosition(400, 220);
			sprite[0].setScale(0.5, 0.5);
			sprite[1].setPosition(400, 340);
			sprite[1].setScale(0.5, 0.5);

			sprite[2].setPosition(320, 260);
			sprite[2].setScale(0.5, 0.5);
			sprite[3].setPosition(240, 340);
			sprite[3].setScale(0.5, 0.5);

			sprite[4].setPosition(480, 260);
			sprite[4].setScale(0.5, 0.5);
			sprite[5].setPosition(320, 420);
			sprite[5].setScale(0.5, 0.5);

			sprite[6].setPosition(240, 220);
			sprite[6].setScale(0.5, 0.5);
			sprite[7].setPosition(160, 260);
			sprite[7].setScale(0.5, 0.5);
		}
	}
	else if (level == 3)
	{
		if (shape == 1)
		{ // filled diamond
			size = 9;
			health = new int[9];
			tex = new Texture[9];
			sprite = new Sprite[9];
			for (int i = 0; i < 9; ++i)
			{
				tex[i].loadFromFile(path);
				sprite[i].setTexture(tex[i]);
				health[i] = 1000;
			}

			sprite[0].setPosition(340, 400);
			sprite[0].setScale(0.5, 0.5);

			sprite[1].setPosition(310, 340);
			sprite[1].setScale(0.5, 0.5);
			sprite[2].setPosition(370, 340);
			sprite[2].setScale(0.5, 0.5);

			sprite[3].setPosition(280, 280);
			sprite[3].setScale(0.5, 0.5);
			sprite[4].setPosition(340, 280);
			sprite[4].setScale(0.5, 0.5);
			sprite[5].setPosition(400, 280);
			sprite[5].setScale(0.5, 0.5);

			sprite[6].setPosition(310, 220);
			sprite[6].setScale(0.5, 0.5);
			sprite[7].setPosition(370, 220);
			sprite[7].setScale(0.5, 0.5);

			sprite[8].setPosition(340, 160);
			sprite[8].setScale(0.5, 0.5);
		}
		else if (shape == 2)
		{ // filled square
			size = 9;
			health = new int[9];
			tex = new Texture[9];
			sprite = new Sprite[9];
			for (int i = 0; i < 9; ++i)
			{
				tex[i].loadFromFile(path);
				sprite[i].setTexture(tex[i]);
				health[i] = 1000;
			}

			sprite[0].setPosition(340, 400);
			sprite[0].setScale(0.5, 0.5);
			sprite[1].setPosition(400, 400);
			sprite[1].setScale(0.5, 0.5);
			sprite[2].setPosition(280, 400);
			sprite[2].setScale(0.5, 0.5);

			sprite[3].setPosition(400, 340);
			sprite[3].setScale(0.5, 0.5);
			sprite[4].setPosition(280, 340);
			sprite[4].setScale(0.5, 0.5);
			sprite[8].setPosition(340, 340);
			sprite[8].setScale(0.5, 0.5);

			sprite[5].setPosition(340, 280);
			sprite[5].setScale(0.5, 0.5);
			sprite[6].setPosition(400, 280);
			sprite[6].setScale(0.5, 0.5);
			sprite[7].setPosition(280, 280);
			sprite[7].setScale(0.5, 0.5);
		}
		else if (shape == 3)
		{ // filled and inverted triangle
			size = 9;
			health = new int[9];
			tex = new Texture[9];
			sprite = new Sprite[9];
			for (int i = 0; i < 9; ++i)
			{
				tex[i].loadFromFile(path);
				sprite[i].setTexture(tex[i]);
				health[i] = 1000;
			}

			sprite[0].setPosition(340, 340);
			sprite[0].setScale(0.5, 0.5);

			sprite[1].setPosition(340, 280);
			sprite[1].setScale(0.5, 0.5);
			sprite[2].setPosition(400, 280);
			sprite[2].setScale(0.5, 0.5);
			sprite[3].setPosition(280, 280);
			sprite[3].setScale(0.5, 0.5);

			sprite[4].setPosition(340, 220);
			sprite[4].setScale(0.5, 0.5);
			sprite[5].setPosition(400, 220);
			sprite[5].setScale(0.5, 0.5);
			sprite[6].setPosition(460, 220);
			sprite[6].setScale(0.5, 0.5);
			sprite[7].setPosition(280, 220);
			sprite[7].setScale(0.5, 0.5);
			sprite[8].setPosition(220, 220);
			sprite[8].setScale(0.5, 0.5);
		}
	}
}

void Invader::checkCollision(Bullet b[20], Spaceship &player)
{

	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (b[i].sprite.getPosition().x >= sprite[j].getPosition().x - 60 && b[i].sprite.getPosition().x <= sprite[j].getPosition().x + 60)
			{
				if (b[i].sprite.getPosition().y > sprite[j].getPosition().y - 60 && b[i].sprite.getPosition().y < sprite[j].getPosition().y + 60)
				{
					if (health[j] <= 0)
					{
						health[j] = 0;
						sprite[j].setPosition(340, 800);
					}
					if (player.fir == 0)
					{
						health[j] -= 5;
					}
					else if (player.fir == 1)
					{
						health[j] = -10;
					}
				}
			}
		}
	}
}

void Invader::move(int level)
{

	if (delta_x == 0.02f)
		delta_x = 0.02 * level;

	else if (delta_x == -0.02f)
		delta_x = -0.02 * level;

	for (int i = 0; i < size; ++i)
	{
		bool out_r = 0;
		for (int j = 0; j < size; ++j)
		{
			if (sprite[j].getPosition().x >= 600)
				out_r = 1;
		}
		bool out_l = 0;
		for (int j = 0; j < size; ++j)
		{
			if (sprite[j].getPosition().x <= 140)
				out_l = 1;
		}

		if (out_r)
		{
			delta_x = -0.02 * level;
		}
		else if (out_l)
		{
			delta_x = 0.02 * level;
		}

		for (int j = 0; j < size; ++j)
			sprite[j].move(delta_x, 0);
	}
}

void Invader::checkShip(Spaceship &player)
{

	for (int i = 0; i < size; ++i)
	{
		if ((player.sprite.getPosition().x <= sprite[i].getPosition().x + 60 && player.sprite.getPosition().x >= sprite[i].getPosition().x - 60) && (player.sprite.getPosition().y <= sprite[i].getPosition().y + 60 && player.sprite.getPosition().y >= sprite[i].getPosition().y - 60))
		{

			player.health -= 1;
		}
	}

	if ((player.sprite.getPosition().x <= b->sprite.getPosition().x + 60 && player.sprite.getPosition().x >= b->sprite.getPosition().x - 60) && (player.sprite.getPosition().y >= b->sprite.getPosition().y - 60 && player.sprite.getPosition().y <= b->sprite.getPosition().y + 60))
	{

		// player.health -= 1;
		bomb_killed = 1;
		b->sprite.setPosition(340, 800);
	}
}

int Invader::get_minX()
{

	int ret = 740;
	for (int i = 0; i < size; ++i)
	{
		if (sprite[i].getPosition().y != 800)
		{
			if (sprite[i].getPosition().x < ret)
				ret = sprite[i].getPosition().x;
		}
	}

	return ret;
}

int Invader::get_maxX()
{

	int ret = 0;
	for (int i = 0; i < size; ++i)
	{
		if (sprite[i].getPosition().y != 800)
		{
			if (sprite[i].getPosition().x > ret)
				ret = sprite[i].getPosition().x;
		}
	}

	return ret;
}

Invader::~Invader()
{
	if (health != nullptr)
		delete[] health;
	if (tex != nullptr)
		delete[] tex;
	if (sprite != nullptr)
		delete[] sprite;
}

#endif
