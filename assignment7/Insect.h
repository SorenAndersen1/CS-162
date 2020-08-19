 #ifndef INSECT_H
 #define INSECT_H

 #include <iostream>
 #include <stdlib.h>
#include <vector>

 using namespace std;

 class Insect {
 protected:

 	string name;
 	int food;
 	int damage;
 	int health;
 	bool attacked;

 public:


 		Insect();

 	void set_attacked(bool new_attacked);
 	void set_health(int new_health);
 	void set_damage(int new_damage); //use number to add to it, not just num
 	void set_food(int new_food);	
 	void set_name(string new_name);
 	void set_mod_health(int new_health);


 	bool get_attacked();
 	string get_name();
 	int get_damage();
 	int get_food();
 	int get_health();

 		 virtual void turn(vector<vector<Insect*> > & board, int turn, int &food) { };


	

 };

 #endif