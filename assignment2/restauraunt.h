/****************************************************** 
** Program: restauraunt.h 
** Author: Soren Andersen
** Date: 10/21/18 
** Description:  header file for restaurant class
** Input: 
** Output: 
******************************************************/ 
#ifndef RESTAURAUNT_H
#define RESTAURAUNT_H 

#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "assignment2.h"




using namespace std;

class Restaurant {
 private:
 Menu menu;
 employee* employees;
 hours* week;
 string name;
 string phone;
 string address; 
 public:
 	void print_address();


	void print_phone();
 	void print_pizzas_rest();
 	 	void cout_orders(order const_order);
void change_hours();
 	void print_hours();
 	bool login_func();
 	void load_employee_data();
 Menu view_menu();
  hours* view_hours();
 string view_address();
 string view_phone();
void set_menu(Menu new_menu);
void set_hours(hours* new_week);
void set_address(string new_address);
void set_phone(string new_phone);
void set_employees(employee* new_employees);
void set_name(string new_name);
void load_restaurant_info(fstream &input);

Menu get_menu();
string get_name();
string get_phone();
string get_address();
void get_hours(); 



 void load_data(); //reads from files to correctly populate menu, employees, hours, etc
 bool login(string id, string password);
 void search_menu_by_price();
 void search_by_ingredients();
 void place_order(Pizza* selection);
 void add_to_menu();
 void remove_from_menu();
 void view_orders();
 void remove_orders();

Restaurant();
~Restaurant();
Restaurant(Restaurant &copy);
void Restaurant_set();
Restaurant& operator= (const Restaurant &copy);

};

#endif