/****************************************************** 
** Program: assignment2.cpp 
** Author: Soren Andersen
** Date: 10/21/18 
** Description:  implementation for the pizza class
least important 
** Input: 
** Output: 
******************************************************/ 
#include "assignment2.h"
#ifndef ASSIGNMENT2_CPP
#define ASSIGNMENT2_CPP
#include <iostream>


Pizza::Pizza(){

	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	ingredients = NULL;
	name = "Blank";
}
 
 Pizza::~Pizza(){
 	if(ingredients != NULL){
	delete []ingredients;
}

}

Pizza& Pizza::operator= (const Pizza &copy){}

Pizza:: Pizza(Pizza &copy){
	ingredients = copy.ingredients;
	name = copy.name;
 	small_cost = copy.small_cost;
 	medium_cost = copy.medium_cost;
 	large_cost = copy.large_cost;
 	num_ingredients = copy.num_ingredients;

}


void Pizza::set_ingredients(string* ingredients_array, int num_ingredients){ //string* ingredients_from_the_class){
	ingredients = new string[get_num_ingredients()];
	for (int i = 0; i < num_ingredients; ++i)
	{

		 ingredients[i] = ingredients_array[i];
	}
}
string Pizza::get_ingredients(int idx){
	{
		return ingredients[idx]; // need to access it as an array
	}
}
void Pizza::specific_set_ingredients(string test, int idx){
	ingredients[idx] = test;

}
	string Pizza::get_name(){
		return name;
	}
	int Pizza::get_num_ingredients(){return num_ingredients;}
	int Pizza::get_small_cost(){return small_cost;}
	int Pizza::get_medium_cost(){return medium_cost;}
	int Pizza::get_large_cost(){return large_cost;}

	void Pizza::set_name(string new_name){
		name = new_name;
	}
	void Pizza::set_small_cost(int new_small_cost){
		small_cost = new_small_cost;
	}
	void Pizza::set_medium_cost(int new_medium_cost){
		medium_cost = new_medium_cost;
	}
	void Pizza::set_large_cost(int new_large_cost){
		large_cost = new_large_cost;
	}
	void Pizza::set_num_ingredients(int new_num_ingredients){
		num_ingredients = new_num_ingredients;
	}


#endif