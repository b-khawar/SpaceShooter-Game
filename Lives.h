#include "AddOn.h"

class Lives:public AddOn{
public:
	
	Lives();
	
	virtual void fall();
	
	virtual void checkShip(int x, int y, int& health, int& lives, bool& fir);
	
};
