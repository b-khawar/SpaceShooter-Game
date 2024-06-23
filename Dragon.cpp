#include "Dragon.h"

Dragon::Dragon():Enemy(){
	tex.loadFromFile("img/dragon2.png");
	sprite.setTexture(tex);
	sprite.setPosition(160,100);
	sprite.setScale(0.6,0.6);
	killed = 0;
	
	bullet_x = sprite.getPosition().x+170;
	
	for (int i=0;i<340;++i){
		bull[i].tex.loadFromFile("img/PNG/Effects/fire17.png");
		bull[i].sprite.setTexture(bull[i].tex);
	}
}

void Dragon::attack(RenderWindow& win, Spaceship& player){

	if ((player.sprite.getPosition().x >= bullet_x - 60 && player.sprite.getPosition().x <= bullet_x + 60) && (player.sprite.getPosition().y >= sprite.getPosition().y+300)){
	
		for (int i=0;i<340;++i){
			bull[i].sprite.setPosition(bullet_x,sprite.getPosition().y+300+i);
			win.draw(bull[i].sprite);
		}
	}
	
	else if ((player.sprite.getPosition().x >= bullet_x + 60) && (player.sprite.getPosition().y >= sprite.getPosition().y+300)){
	
		for (int i=0;i<340;++i){
			bull[i].sprite.setPosition(bullet_x+i,sprite.getPosition().y+300+i);
			win.draw(bull[i].sprite);
		}
	}
	
	else if ((player.sprite.getPosition().x <= bullet_x - 60) && (player.sprite.getPosition().y >= sprite.getPosition().y+300)){
	
		for (int i=0;i<340;++i){
			bull[i].sprite.setPosition(bullet_x-i,sprite.getPosition().y+300+i);
			win.draw(bull[i].sprite);
		}
	}
}


void Dragon::checkShip(Spaceship& player){

	for (int i=0;i<340;++i){
		if ((player.sprite.getPosition().x >= bull[i].sprite.getPosition().x - 20) && (player.sprite.getPosition().x <= bull[i].sprite.getPosition().x + 20) && (player.sprite.getPosition().y >= bull[i].sprite.getPosition().y - 20) && (player.sprite.getPosition().y <= bull[i].sprite.getPosition().y + 20)){
			player.health = 0;
			killed = 1;
		}
	}
	
	if (player.sprite.getPosition().x >= sprite.getPosition().x && player.sprite.getPosition().x <= sprite.getPosition().x + 400 && player.sprite.getPosition().y >= sprite.getPosition().y && player.sprite.getPosition().y <= sprite.getPosition().y + 300)
	
		player.health = 0;
	
	
}
