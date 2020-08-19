/********************************************************************* 
 ** Program Filename:  player.h
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: h for player
 ** Input: 
 ** Output: 
 *********************************************************************/ 

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;


class player{

private:
	int amt_owned;
	int cash;
	int num_props;

public:

	int get_cash();
	int get_amt_owned();
	int get_num_props();

		void set_cash(int new_cash);
		void set_amt_owned(int new_amt_owned);
		void set_num_props(int new_num_props);

player();
player(const player& copy);
~player();

};

#endif