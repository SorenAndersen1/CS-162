#ifndef LONGTHROWER_H
#define LONGTHROWER_H

#include "Insect.h"
#include <vector>


class Longthrower:public Insect{
	
	private:

	public:


	void turn(vector<vector<Insect*> > & board, int turn, int &food);
	Longthrower();
};

#endif