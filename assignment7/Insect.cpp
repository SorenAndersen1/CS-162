#include "Insect.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

 Insect::Insect() {
 	health = 0;
 	damage = 0;
 	food = 0;
 	name = "blank";
 	attacked = false;
	
 	}


 	void Insect::set_attacked(bool new_attacked){attacked = new_attacked;}
 	void Insect::set_health(int new_health){health = new_health;}
 	void Insect::set_damage(int new_damage){damage = damage;}
 	void Insect::set_mod_health(int new_health){health = health + new_health;}
 	void Insect::set_food(int new_food){food = new_food;}	
 	void Insect::set_name(string new_name){name = new_name;}

 	bool Insect::get_attacked(){return attacked;}
 	string Insect::get_name(){return name;}
 	int Insect::get_damage(){return damage;}
 	int Insect::get_food(){return food;}
 	int Insect::get_health(){return health;}

void turn(vector<vector<Insect*> > & board, int turn, int &food){
	
}



 //  Insect::Insect operator=(const Insect &copy ){


 // }
