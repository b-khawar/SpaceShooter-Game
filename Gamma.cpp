#include "Gamma.h"

Gamma::Gamma():Invader("img/enemy_2.png"){

	bomb_time = 2.0;   //Gamma bomb falls after 2 seconds
	b->sprite.setPosition(bomb_x,440);
}

void Gamma::fall_bomb(RenderWindow& window){

	if (!bomb_killed){
		b->sprite.setPosition(bomb_x,b->sprite.getPosition().y+0.5);
		window.draw(b->sprite);
	}
}


void Gamma::healthCheck(int& score, int level){
	for (int i=0;i<size;++i){
		if (health[i] <= 0){
			health[i] = 0;
			score += (30*level);
		}
	}
}
