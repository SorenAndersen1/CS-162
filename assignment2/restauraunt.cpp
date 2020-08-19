/****************************************************** 
** Program: restaurunt.cpp 
** Author: Soren Andersen
** Date: 10/21/18 
** Description:  implementation for the restaurant class
and has and calls all the other functions used, also loads data
** Input: 
** Output: 
******************************************************/ 
#include "restauraunt.h"

#include <iostream>
#include <fstream>
#include <string>

Restaurant:: Restaurant(){
	employees = NULL;
	name = "blank";
	phone = "blank";
	address = "blank";
	week = NULL;
}
Restaurant:: ~Restaurant(){
		delete []employees;
	

		delete []week;
	

}
Restaurant:: Restaurant(Restaurant & copy){
}
void Restaurant::load_data(){
	Menu menu;
	load_employee_data();
	fstream input;
	input.open("restaurant_info.txt");
	load_restaurant_info(input);
	if(input.is_open()){

	}


	input.close();


	menu.load_data();

}
bool Restaurant::login_func(){

	cout << "Please provide your ID number" << endl;
	string temp;
	cin >> temp;
	cout << "Please enter your password" << endl;
	string test;
	cin >> test;
	int ok_count, hold;
	ok_count = 0;
	for (int i = 0; i < 3; ++i)
	{
		if(temp == employees[i].id){
			ok_count++;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		if(test == employees[i].password){
			ok_count++;
			hold = i;
		}
	}
	if(ok_count == 2){
		cout << "Welcome " << employees[hold].first_name << " " << employees[hold].last_name;
		cout << endl;
		return true;
	}
	else if(ok_count != 2){
		return login_func();
	}

}
/*
Restaurant& Restaurant::operator= (const Restaurant &copy){


}
*/

void Restaurant::load_employee_data(){
	fstream input;
	input.open("employee.txt");
	int temp = 0;
	input >> temp;
	this->employees = new employee[temp];

		for(int i = 0; i < temp; i++ ){
			input >> employees[i].id;
			input >> employees[i].first_name;
			input >> employees[i].last_name;
			input >> employees[i].password;

	}
	input.close();

}
void Restaurant::load_restaurant_info(fstream &input){
	string this_number_is_seven = " ";
	this->week = new hours[7];
	getline(input, name);
	getline(input, phone);
	getline(input, address);
	getline(input, this_number_is_seven);
		
	for(int i = 0; i < 7; i++){
		input >> week[i].day;
		input >> week[i].open_hour;
		input >> week[i].close_hour;
	}
	
}

void Restaurant::set_employees(employee* new_employees){
	employees = new_employees;
}
void Restaurant::Restaurant_set() {
	employees = NULL;
	week = NULL;
	name = "No Name";
	phone = "No Number";
	address = "No Address";
}
void Restaurant::set_menu(Menu new_menu){
	menu = new_menu;
 }
 void Restaurant::set_hours(hours* new_week){
	 

	  week = new_week;
 
 }
void Restaurant::set_address(string new_address){
	address = new_address;
}
void Restaurant::set_phone(string new_phone){
	phone = new_phone;
}
void Restaurant::set_name(string new_name){
	name = new_name;
}


Menu Restaurant::get_menu(){
	return menu;
}
string Restaurant::get_name(){
	return name;
}
string Restaurant::get_phone(){
	return phone;
}
string Restaurant::get_address(){
	return address;

}

void Restaurant::change_hours(){
	cout << "What day would you like to change hours? Single letter please" << endl;
	string input;
	cin >> input;
	int hold = 0;
	for (int i = 0; i < 7; ++i)
	{
		if(week[i].day == input){
			hold = i;
		}
	}
	cout << "What should be the new opening hour?" << endl;
	string new_hour;
	cin >> new_hour;
	week[hold].open_hour = new_hour; 
	cout << "What should be the new closing hour?" << endl;
	cin >> new_hour;
	week[hold].close_hour = new_hour;
	print_hours();
}
void Restaurant::print_hours(){
	for (int i = 0; i < 7; ++i)
	{
		cout << week[i].day << "  ";
		cout << week[i].open_hour << "  ";
		cout << week[i].close_hour << "  ";
		cout << endl;
	}
}
void Restaurant::print_address(){
	cout << address << endl;

}
void Restaurant::print_phone(){
	cout << phone << endl;

} 
void Restaurant::print_pizzas_rest(){
	cout << "worked" << endl;
	menu.print_pizzas();
}
 void Restaurant::view_orders(){
 
 	fstream input;

 	input.open("order.txt");
 	order const_order;
 	string num_order = "wat";
 	getline(input, num_order);



 	input >> const_order.num;
 	input >> const_order.first_name;
 	input >> const_order.last_name;
 	input >> const_order.cust_cc;
 	input >> const_order.address;
 	input >> const_order.pizza_name;
 	input >> const_order.size;
 	input >> const_order.quanity;
 	cout_orders(const_order);
 	input.close();
 }

void Restaurant::cout_orders(order const_order){
	cout << const_order.num << "  ";
 	cout << const_order.first_name << "  ";
 	cout << const_order.last_name << "  ";
 	cout << const_order.cust_cc << "  ";
 	cout << const_order.address << "  ";
 	cout << const_order.phone << "  ";
 	cout << const_order.pizza_name << "  ";
 	cout << const_order.size << "  ";
 	cout << const_order.quanity << "  " << endl;
}


/*
hours* Restaurant::get_week(){
	for(int i = 0; i <)
	return week;
}
FIX THIS TOO
*/
/*
void Restaurant::set_week(string new_week){
	week = new_week;
}
void change_hours();
void change_hours();
void change_hours();

THIS IS WHERE THE NEW HOURS FUNCTION GOES */


