#ifndef BEES_H
#define BEES_H
#include <vector>
#include "Insect.h"

class Bees:public Insect{
	
	private:



	public:



	void turn(vector<vector<Insect*> > & board, int turn, int &food);

	Bees();


};
#endif