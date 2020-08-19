/****************************************************** 
** Program: menu.h 
** Author: Soren Andersen
** Date: 10/21/18 
** Description:  header file for menu class
** Input: 
** Output: 
******************************************************/ 
#ifndef MENU_H
#define MENU_H
#include "assignment2.h"
#include <iostream>
#include <fstream>
#include <string>





using namespace std;

class Menu{
 	private:

 		int num_pizzas;
		Pizza* pizzas;
 	public:
 		void print_pizzas();
 		void set_num_pizzas(int num);
 		int get_num_pizzas();
	Menu search_pizza_by_cost(int upper_bound, string size);
 	Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients){
 	};
 	Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int
		num_ingredients);
 	void add_to_menu(Pizza pizza_to_add);
 	void remove_from_menu(int index_of_pizza_on_menu);
 	void load_data();
 	void load_menu_info(fstream &input);
void set_ingredients(string* ingredients_array, int num_ingredients);
int get_num_lines(fstream &input);
Menu();
 ~Menu();
Menu(Menu &copy);
Menu& operator= (const Menu &copy);
 
};

#endif