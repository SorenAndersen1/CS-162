#ifndef SHORTHROWER_H
#define SHORTHROWER_H
#include "Insect.h"


class Shortthrower:public Insect{
	
	private:

	public:


	void turn(vector<vector<Insect*> > & board, int turn, int &food);
	Shortthrower();
};

#endif