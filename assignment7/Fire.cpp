#include "Fire.h"

#include "Insect.h"
#include <vector>


void Fire::turn(vector<vector<Insect*> > & board, int turn, int &food){
		for (int i = 0; i < board[turn].size(); ++i)
		{
			if(board[turn][i]->get_name() == "Bee"){
				cout << "Fire Ant killed a bee" << endl;
				board[turn][i]->set_health(0);

			}
			else{
				continue;
			}
		}
	}
	

Fire::Fire(){
	name = "Fire";
	damage = 1;
	food = 4;
	health = 1;

}