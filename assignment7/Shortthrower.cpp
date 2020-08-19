#include "Shortthrower.h"
#include <vector>
#include "Insect.h"


void Shortthrower::turn(vector<vector<Insect*> > & board, int turn, int &food){
		bool attacked = true;
		for (int i = 0; i < 10; ++i)
		{
			
		for (int j = 0; j < board[i].size(); ++j)
		{
			if(board[i][j]->get_name() == "Bee" && attacked && (((i - turn) <= 2 || (i - turn) >= -2))) {
				board[i][j]->set_mod_health(-1);
				attacked = false;
			}
			else{
				continue;
			}
		}
	}

}

Shortthrower::Shortthrower(){
	name = "Shortthrower";
	damage = 1;
	food = 3;
	health = 1;

}