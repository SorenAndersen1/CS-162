#include "Bees.h"
#include "Insect.h"


 


void Bees::turn(vector<vector<Insect*> > & board, int turn, int &food){
    

    int Bodyguard_count = 0;
    for (int i = 0; i < board[turn].size(); ++i)
    {
    	if(board[turn][i]->get_name() == "Wall"){
    		Bodyguard_count++;
    	}
    }

		for (int j = 0; j < board[turn].size(); ++j)
		{
			if(board[turn][j]->get_name() == "Bee" && board[turn][j]->get_health() >= 0 && Bodyguard_count == 0){
		
				// cout << "got here" << endl;
				 board[turn - 1].push_back(board[turn][j]);
				
				// delete [] board[turn][j];
				 board[turn].erase(board[turn].begin() + j);

	
			
		}
		else{
				continue;
			}
	}









    for(int i = 0; i < board[turn].size(); i++){
     if((!(board[turn][i]->get_name() == "Ninja")))
     board[turn][i]->set_mod_health(-1);
 	// else if(Bodyguard_count =! 0){
 	// 	board[turn][Bodyguard_space]->set_mod_health(-1);
 	// }
 	else{
 		continue;
 	}


 }
}


	
	Bees::Bees(){

	health = 3;
	damage = 1;
	name = "Bee";
	}
	
