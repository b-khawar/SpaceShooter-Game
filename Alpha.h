#include "Invader.cpp"

class Alpha:public Invader{

public:
	Alpha();
	
	virtual void fall_bomb(RenderWindow& window);
	
	void healthCheck(int&,int);
};

//Pass123?
