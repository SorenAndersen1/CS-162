/****************************************************** 
** Program: menu.cpp 
** Author: Soren Andersen 
** Date: 10/21/18
** Description: implementation for menu, has all menu
and pizza related functions
** Input: 
** Output: 
******************************************************/ 

#ifndef MENU_CPP
#define MENU_CPP
#include "assignment2.h"
#include "menu.h"


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Menu::Menu() {
	this->num_pizzas = 0;
	this->pizzas = NULL;
}

Menu::~Menu(){
 	if(pizzas != NULL){

 		delete[] pizzas;
}
 }

Menu:: Menu(Menu &copy){
	this->set_num_pizzas(get_num_pizzas());
	for(int i = 0; i < num_pizzas; i++){
		copy.pizzas[i].set_name(pizzas[i].get_name());
		copy.pizzas[i].set_small_cost(pizzas[i].get_small_cost());
		copy.pizzas[i].set_medium_cost(pizzas[i].get_medium_cost());
		copy.pizzas[i].set_large_cost(pizzas[i].get_large_cost());
		copy.pizzas[i].set_num_ingredients(pizzas[i].get_num_ingredients());
		
			for (int j = 0; j < pizzas[i].get_num_ingredients(); ++j)
	{

		 copy.pizzas[i].specific_set_ingredients(pizzas[i].get_ingredients(j), j);
	}
	
}


	}
// void Menu::add_pizza(){
// 	menu new_menu;
// 	new_menu.set_pizza = new 


// }
/*
void Menu::set_pizza(pizza* pizzas, int array_num){
	pizzas = new pizzas[array_num] 
}
*/

void Menu::print_pizzas(){

	for(int i = 0; i < 2; i++){
		cout << pizzas[i].get_name();
	
	
		cout << pizzas[i].get_small_cost() << " ";
		cout << pizzas[i].get_medium_cost() << " ";
		cout << pizzas[i].get_large_cost() << " ";
		cout << pizzas[i].get_num_ingredients() << " ";

		for (int j = 0; j < pizzas[i].get_num_ingredients(); ++j)
		{
			cout << pizzas[i].get_ingredients(j) << " ";

		}
		cout << endl;
	}
}

Menu& Menu::operator= (const Menu &copy){
	num_pizzas = copy.num_pizzas;
	pizzas = copy.pizzas;
}
 
void Menu::set_num_pizzas(int num){
 			num_pizzas = num;
 		}

int Menu::get_num_pizzas(){
 			return num_pizzas;
 		}
void Menu::load_data(){
	fstream input;

	input.open("menu.txt");



	load_menu_info(input);

	if(input.is_open()){

	}
	input.close();
	load_menu_info(input);

}

void Menu::load_menu_info(fstream &input){
	string string_test;
	int hold = 0;
	int small, medium, large, num_ingredients;
	set_num_pizzas(6);
this->pizzas = new Pizza[num_pizzas];

// this->num_pizzas = get_num_lines(input);

getline(input, string_test);
string_test = " ";


	for(int i = 0; i < num_pizzas; i++){


		input >> string_test;
		pizzas[i].set_name(string_test);

		input >> hold;
		pizzas[i].set_small_cost(hold);

		input >> hold;
		pizzas[i].set_medium_cost(hold);

		input >> hold;
		pizzas[i].set_large_cost(hold);

		input >> hold;
		pizzas[i].set_num_ingredients(hold);
		string* pizza_ingr_array = new string[pizzas[i].get_num_ingredients()];
		
		for(int j = 0; j < pizzas[i].get_num_ingredients(); j++){
			input >> pizza_ingr_array[j];

		}

		hold = pizzas[i].get_num_ingredients();

		pizzas[i].set_ingredients(pizza_ingr_array, hold);

	}
}
int get_num_lines(fstream &input){
	int c = 0;
	string test;
	while (!input.eof()) {
		getline(input, test);
		c++;
	}

	input.clear();
	input.seekg(0, ios::beg); 
	return c;

}
#endif