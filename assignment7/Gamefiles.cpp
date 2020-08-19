

#include "Gamefiles.h"
#include "Insect.h"
#include "Bees.h"
#include "Harvester.h"
#include "Thrower.h"
#include "Fire.h"
#include "Longthrower.h"
#include "Shortthrower.h"
#include "Wall.h"
#include "Ninja.h"
#include "Bodyguard.h"
#include <iostream>
#include <vector>

void Gamefiles::board_generate(vector<vector<Insect* > > &board){

	for(int i = 0; i < 10; i++){
		cout << "|";
		for (int j = 0; j < board[i].size(); j++)
		{
			 cout << board[i][j]->get_name() << " ";

		}
		cout << " | " << i + 1;
		cout << endl;
	}




}
void Gamefiles::message_func(char lazy){
	if(lazy == 'b'){
		cout << "The Bees have won" << endl;
	}
	else if(lazy == 'a'){
		cout << "The ants have won" << endl;
	}
}
bool Gamefiles::win_func(vector<vector<Insect* > > &board){
int temp = 0;
char lazy;
do{
	for(int i = 0; i < board[0].size(); i++){
		if(board[0][i]->get_name() == "Bee"){
			cout << "The Bees have won" << endl;
			lazy = 'b';
			board_generate(board);
			cout << "there is no bee in 10 because it hasnt been generated yet" << endl;
			return false;
			break;
			break;
			break;

		}
		else{
			temp++;
			break;

		}
	}	
	
	for(int j = 0; j < 10; j++){
	for(int i = 0; i < board[j].size(); i++){
		if(board[j][i]->get_name() == "Bee"){
			lazy = 'a';
			temp++;
			break;

		}
		else{
			continue;
		}

}
}

	if(temp >= 1){
		return true;

	}
	else{
		return false;
	}
	}while(false);
	message_func(lazy);

}
int Gamefiles::choice_func(){
	cout << "Would you like to place an ant? If yes enter y, if no enter n ." << endl;
	string input;
	cin >> input;
	if(input == "y"){
		cout << "What type of ant do you want? Enter corresponding num" << endl;
		

		cout << "1 Harvester" << endl;
		cout << "2 Thrower" << endl;
		cout << "3 Fire" << endl;
		cout << "4 Long Thrower" << endl;
		cout << "5 Short Thrower" << endl;
		cout << "6 Wall" << endl;
		cout << "7 Ninja" << endl;
		cout << "8 Bodyguard" << endl;
		int temp = 0;
		cin >> temp;
		return temp;
	}
	else if(input == "n"){
		return 0;
	}
	else{
		// return choic?_func()
	}
}
int Gamefiles::simple_return(){
	cout << "What space do you want the ant?" << endl;
	int temp = 0;
	cin >> temp;
	// if(temp =! 1){
	return temp;
// }
	// else{
		// return simple_return();
	// }
}
void Gamefiles::check_dead(vector<vector<Insect* > > &board){
	
	for(int i =0; i < 10; i++){
		for (int j = 0; j < board[i].size(); ++j)
		{
			if(board[i][j]->get_health() <= 0){
				delete board[i][j];
				board[i].erase(board[i].begin() + j);
			}
			else
				continue;
		}
	}
}
bool Gamefiles::check_for_ants(vector<vector<Insect* > > &board, int idx){
	int ants = 0;
		for (int i = 0; i < board[idx].size(); ++i)
		{
			if(board[idx][i]->get_name() == "Thrower" || board[idx][i]->get_name() == "Fire" || board[idx][i]->get_name() == "Harvester"
				|| board[idx][i]->get_name() == "Longthrower" || board[idx][i]->get_name() == "Ninja" || board[idx][i]->get_name() == "Shortthrower" || board[idx][i]->get_name() == "Wall"){
				ants++;
			}
		}
		if(ants >= 1){
			cout << "Too many ants there, try again" << endl;
			return false;

		}
		else if(ants < 1){
			return true;
		}
	}
void Gamefiles::generate_ant(vector<vector<Insect* > > &board, int &food){

	int temp = choice_func(); 
	int another_temp = 0;
	if(temp != 0){
	another_temp = simple_return();
	cout << another_temp << endl;
	another_temp += -1;
	if(check_for_ants(board, another_temp) && another_temp < 10){
	if(temp == 1){
		board[another_temp].push_back(new Harvester);
		food = food - 2;
	}
	if(temp == 2){
		board[another_temp].push_back(new Thrower);
		food = food - 4;
	}
	if(temp == 3){
		board[another_temp].push_back(new Fire);
			food = food - 4;

	}

	if(temp == 4){
		board[another_temp].push_back(new Longthrower);
			food = food - 3;
	}
	if(temp == 5){
		board[another_temp].push_back(new Shortthrower);
			food = food - 3;
	}
	if(temp == 6){
		board[another_temp].push_back(new Wall);
			food = food - 3;
	}
	if(temp == 7){
	
		board[another_temp].push_back(new Ninja);
				food = food - 6;
	}
	if(temp == 8){
		board[another_temp].push_back(new Bodyguard);
			food = food - 4;
	}
}
}
	board_generate(board);



}
void Gamefiles::turn_func(vector<vector<Insect* > > &board, int &food){
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			board[i][j]->turn(board, i, food);
		}
	}
}
bool Gamefiles::no_bodyguard(vector<vector<Insect* > > &board, int idx){
		int temp = 0;
		for (int j = 0; j < board[idx].size(); ++j)
		{
			if(board[idx][j]->get_name() == "Wall"){
					temp++;
				
			}	

		}
		if(temp >= 1){
			return false;
		}
		else if(temp == 0){
			return true;
		}

	}

void Gamefiles::board_move(vector<vector<Insect* > > &board){

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j]->get_name() == "Bee" /*&& board[i][j]->get_health() > 0 && no_bodyguard(board, i)*/){\
				// if(board[i][j]->get_move() == true){
				// board[i][j]->set_move(false);
				// cout << "got here" << endl;
				 board[i - 1].push_back(board[i][j]);
				
				 
				 board[i].erase(board[i].begin() + j);
				 // delete [] board[i][j];
				 

	
}
		}
	// }
	cout << endl;
	}
	board_generate(board);
}
void Gamefiles::start_game(vector<vector<Insect* > > &board){
	
int turn_num = 0;
int food = 50;

	do{
			board[9].push_back(new Bees);
		   generate_ant(board, food);
		turn_func(board, food);
		   check_dead(board);

		 


		  // board_move(board);


			cout << "You have " << food << " many pieces of food" << endl;
		turn_num++;
	}while(win_func(board));

// 	for(int i = 0; i < board.size(); i++){
// 		for(int j = 0; j < board[i].size(); j++){
// 			delete [] board[i][j];
// 				board[i][j] = NULL;
// 		}
// }

		for (int j = 0; j < board.size(); ++j)
		{
			
	for(int i = 0; i < board[j].size(); i++){
			 delete board[j][i];
			
			 board[j].erase(board[j].begin() + i);
		}
}
		 // board.clear();
}

Gamefiles::Gamefiles(){
}


