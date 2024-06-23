#include "Beta.h"

Beta::Beta():Invader("img/enemy_3.png"){

	bomb_time = 3.0;   //Beta bomb falls after 3 seconds
	b->sprite.setPosition(bomb_x,440);	
}

void Beta::fall_bomb(RenderWindow& window){//, float enemy_time){
		if (!bomb_killed){
			b->sprite.setPosition(bomb_x,b->sprite.getPosition().y+0.5);
			window.draw(b->sprite);
		}
}


void Beta::healthCheck(int& score, int level){
	for (int i=0;i<size;++i){
		if (health[i] <= 0){
			health[i] = 0;
			score += (20*level);
		}
	}
}
