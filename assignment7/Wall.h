#ifndef WALL_H
#define WALL_H
#include "Insect.h"


class Wall:public Insect{
	
	private:

	public:


	void turn(vector<vector<Insect*> > & board, int turn, int &food);
	Wall();
};

#endif