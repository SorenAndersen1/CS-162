
/********************************************************************* 
 ** Program Filename:  player.cpp
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: cpp for player
 ** Input: 
 ** Output: 
 *********************************************************************/ 
#include <iostream>
#include "player.h"	
using namespace std;

	int player::get_cash(){
		return cash;
	}
	int player::get_amt_owned(){
		return amt_owned;
	}

	int player::get_num_props(){
		return num_props;
	}

		void player::set_cash(int new_cash){
			cash = new_cash;

		}
		void player::set_amt_owned(int new_amt_owned){
			amt_owned = new_amt_owned;
		}
		void player::set_num_props(int new_num_props){
			num_props = new_num_props;
		}

player::player(){
	amt_owned = 0;
	cash = 500000;
	num_props = 0;
}
player::player(const player& copy){}
player::~player(){}
