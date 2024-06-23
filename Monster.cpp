#include "Monster.h"

Monster::Monster():Enemy(){
	tex.loadFromFile("img/monster1.png");
	sprite.setTexture(tex);
	sprite.setPosition(140,30);
	sprite.setScale(0.75,0.75);
	bul_no = 0;
	killed = 0;
	delta_x = 0.4;
	
	bullet_x = sprite.getPosition().x+243;
	
	for (int i=0;i<300;++i){
		bul[i].tex.loadFromFile("img/PNG/Effects/fire17.png");
		bul[i].sprite.setTexture(bul[i].tex);
	}
}

void Monster::attack(RenderWindow& win){

	bullet_x = sprite.getPosition().x+243;
	for (int i=0;i<300;++i){
		bul[i].sprite.setPosition(bullet_x,sprite.getPosition().y+350+i);
		win.draw(bul[i].sprite);
	}
}

void Monster::checkShip(Spaceship& player){

	bullet_x = sprite.getPosition().x+243;
	if ((player.sprite.getPosition().x >= bullet_x-60 && player.sprite.getPosition().x <= bullet_x) && (player.sprite.getPosition().y >= sprite.getPosition().y+300)){
		player.health = 0;
		killed = 1;
	}
	
	if (player.sprite.getPosition().x >= sprite.getPosition().x && player.sprite.getPosition().x <= sprite.getPosition().x + 400 && player.sprite.getPosition().y >= sprite.getPosition().y && player.sprite.getPosition().y <= sprite.getPosition().y + 400)
		player.health = 0;
}


void Monster::move(int level){

	if (delta_x == 0.4f)
		delta_x = 0.4 * level;
		
	else if (delta_x == -0.4f)
		delta_x = -0.4 * level;
		
	if (sprite.getPosition().x >= 250)
		delta_x = -0.4 * level;

	else if (sprite.getPosition().x <= 0)
		delta_x = 0.4 * level;

	sprite.move(delta_x,0);
}
