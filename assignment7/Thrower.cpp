#include "Thrower.h"

#include "Insect.h"
#include <vector>


void Thrower::turn(vector<vector<Insect*> > & board, int turn, int &food){
	bool attacked = true;
		for (int j = 0; j < board[turn].size(); ++j)
		{
			if(board[turn][j]->get_name() == "Bee" && attacked){
				board[turn][j]->set_mod_health(-1);
				attacked = false;
			}
			else{
				continue;
			}
		}
	}

Thrower::Thrower(){
	name = "Thrower";
	damage = 1;
	food = 4;
	health = 1;

}