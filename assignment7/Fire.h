#ifndef FIRE_H
#define FIRE_H
#include "Insect.h"


class Fire:public Insect{
	
	private:

	public:

 
	void turn(vector<vector<Insect*> > & board, int turn, int &food);
	Fire();
};

#endif