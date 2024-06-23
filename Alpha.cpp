#include "Alpha.h"

Alpha::Alpha():Invader("img/enemy_1.png"){
	
	bomb_time = 5.0;   //Alpha bomb falls after 5 seconds
	b->sprite.setPosition(bomb_x,440);
}

void Alpha::fall_bomb(RenderWindow& window){//, float enemy_time){
		if (!bomb_killed){
			b->sprite.setPosition(bomb_x,b->sprite.getPosition().y+0.5);
			window.draw(b->sprite);
		}
}


void Alpha::healthCheck(int& score, int level){
	for (int i=0;i<size;++i){
		if (health[i] <= 0){	
			health[i] = 0;
			score += (10*level);
		}
	}
}
