#ifndef THROWER_H
#define THROWER_H

#include "Insect.h"

class Thrower:public Insect{
	
	private:

	public:


	void turn(vector<vector<Insect*> > & board, int turn, int &food);
	Thrower();
};

#endif