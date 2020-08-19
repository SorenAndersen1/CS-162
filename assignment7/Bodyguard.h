#ifndef BODYGUARD_H
#define BODYGUARD_H
#include "Insect.h"
#include <vector>

class Bodyguard:public Insect{
	
	private:

	public:


	void turn(vector<vector<Insect*> > & board, int turn, int &food);
	Bodyguard();
};

#endif