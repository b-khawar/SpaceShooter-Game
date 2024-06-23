#include "AddOn.h"

class Danger:public AddOn{
public:
	
	Danger();
	
	virtual void fall();
	
	virtual void checkShip(int x, int y, int& health, int& lives, bool& fir);
	
};
