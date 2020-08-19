#ifndef GAMEFILES_H
#define GAMEFILES_H 
#include "Insect.h"
#include <iostream>
#include <vector>

class Gamefiles{
	private:

	public:

	void start_game(std::vector<std::vector<Insect* > > &board);	
	bool win_func(vector<vector<Insect* > > &board);
	void board_generate(vector<vector<Insect* > > &board);
	int choice_func();
	void generate_ant(vector<vector<Insect* > > &board, int &food);
	int simple_return();
	void turn_func(vector<vector<Insect* > > &board, int &food);
	void board_move(vector<vector<Insect* > > &board);
	bool no_bodyguard(vector<vector<Insect* > > &board, int idx);
	void check_dead(vector<vector<Insect* > > &board);
	void message_func(char lazy);
bool check_for_ants(vector<vector<Insect* > > &board, int idx);


	Gamefiles();
};

#endif