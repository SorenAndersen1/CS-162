/****************************************************** 
** Program: assignment2.h 
** Author: Soren Andersen
** Date: 10/21/18 
** Description:  header file for order, employee, and hours struct
and Pizza class
** Input: 
** Output: 
******************************************************/ 
#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

#include <iostream>
#include <fstream>
#include <string>






using namespace std;
struct order {
	string num;
	string first_name;
	string last_name;
	string cust_cc;
	string address;
	string phone;
	string pizza_name;
	string size;
	string quanity;


};

struct employee {
 string id;
 string first_name;
 string last_name;
 string password;
};

struct hours {
 string day;
 string open_hour;
 string close_hour;
};

class Pizza {
 private:
 string name;
 int small_cost;
 int medium_cost;
 int large_cost;
 int num_ingredients;
 string* ingredients;
 public:
 	string get_ingredients(int idx);
 	void specific_set_ingredients(string test, int idx);
 	void set_ingredients(string* ingredients_array, int num_ingredients);
 	void set_name(string new_name);
	 string get_name();
	 int get_num_ingredients();
	 int get_small_cost();
	 int get_medium_cost();
	 int get_large_cost();

	 void set_small_cost(int new_small_cost);
	 void set_medium_cost(int new_medium_cost);
	 void set_large_cost(int new_large_cost);
	 void set_num_ingredients(int new_num_ingredients);
	 void set_ingriedents(int loop_num);

Pizza();
~Pizza();

Pizza(Pizza &copy);

 Pizza& operator= (const Pizza &copy);

};



#endif


