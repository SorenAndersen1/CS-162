#ifndef NINJA_H
#define NINJA_H

#include "Insect.h"


class Ninja:public Insect{
	
	private:

	public:


	void turn(vector<vector<Insect*> > & board, int turn, int &food);
	Ninja();
};

#endif