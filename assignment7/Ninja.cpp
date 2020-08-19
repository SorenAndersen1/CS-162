#include "Ninja.h"

#include "Insect.h"
#include <vector>


void Ninja::turn(vector<vector<Insect*> > & board, int turn, int &food){
	bool attacked = true;
	    for(int i = 0; i < board[turn].size(); i++){
     if(((board[turn][i]->get_name() == "Bee") && attacked)){
     board[turn][i]->set_mod_health(-1);
     attacked = false;
 	}
 	else{
 		continue;
 	}
}


}

Ninja::Ninja(){
	name = "Ninja";
	damage = 1;
	food = 6;
	health = 1;

}