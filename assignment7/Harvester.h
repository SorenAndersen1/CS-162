#ifndef HARVESTER_H
#define HARVESTER_H

#include "Insect.h" 

#include <vector>

class Harvester:public Insect{
	private:

	public:

	Harvester();

	void turn(vector<vector<Insect*> > & board, int turn, int &food); 
};
#endif