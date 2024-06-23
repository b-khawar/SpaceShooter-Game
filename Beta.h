#include "Invader.cpp"

class Beta:public Invader{

public:	
	Beta();
	
	virtual void fall_bomb(RenderWindow& window);//, float enemy_time);
	
	void healthCheck(int&,int);
};

