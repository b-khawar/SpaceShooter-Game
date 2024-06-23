#include "Invader.cpp"

class Gamma:public Invader{

public:
	Gamma();
	
	virtual void fall_bomb(RenderWindow& window);//, float enemy_time);
	
	void healthCheck(int&,int);
};

