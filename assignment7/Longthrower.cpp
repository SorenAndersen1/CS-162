#include "Longthrower.h"

#include "Insect.h"
#include <vector>


void Longthrower::turn(vector<vector<Insect*> > & board, int turn, int &food){
		bool attacked = true;
		for (int i = 0; i < 10; ++i)
		{
			
		for (int j = 0; j < board[i].size(); ++j)
		{
			if(board[i][j]->get_name() == "Bee" && attacked && (((i - turn) >= 4 || (i - turn) <= -4))) {
				board[i][j]->set_mod_health(-1);
				attacked = false;
			}
			else{
				continue;
			}
		}
	}
	}


Longthrower::Longthrower(){
	name = "Longthrower";
	damage = 1;
	food = 3;
	health = 1;

}