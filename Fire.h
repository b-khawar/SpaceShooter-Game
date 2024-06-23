#include "AddOn.h"
//#include "Spaceship.cpp"

class Fire:public AddOn{
public:
	Fire();
	
	virtual void fall();
	
	virtual void checkShip(int x, int y, int& health, int& lives, bool& fir);
	
};
