/********************************************************************* 
 ** Program Filename:  traits.cpp
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: cpp for traits
 ** Input: 
 ** Output: 
 *********************************************************************/ 

#ifndef TRAITS_CPP
#define TRAITS_CPP

#include <iostream>
#include <string>

#include "traits.h"


using namespace std;


	traits::traits(){
		prop_val = 0;
		mortgage = 0;
		rent = 0;
		tax_this_is_fifteen = .015;
		is_owned = false;
		type = " ";
		location = " ";
		num_turns_mort = 0;
		name = 0;
	}
	double traits::get_prop_val(){return prop_val;}
	double traits::get_mortgage(){return mortgage;}
	double traits::get_tax_this_is_fifteen(){return tax_this_is_fifteen;}
	int traits::get_rent(){return rent;}
	bool traits::get_is_owned(){return is_owned;}
	string traits::get_type(){return type;}
	string traits::get_location(){return location;}
	int traits::get_num_turns_mort(){return num_turns_mort;}

	void traits::set_prop_val(double new_prop_val){ prop_val = new_prop_val;}
	void traits::set_mortgage(double new_mortgage){ mortgage = new_mortgage;}
	void traits::set_tax_this_is_fifteen(double new_tax_this_is_fifteen){ tax_this_is_fifteen = new_tax_this_is_fifteen;}
	void traits::set_rent(int new_rent){ rent = new_rent;}
	void traits::set_is_owned(bool new_is_owned){ is_owned = new_is_owned;}
	void traits::set_type(string new_type){ type = new_type;}
	void traits::set_location(string new_location){ location = new_location;}
		void traits::set_num_turns_mort(int new_num_turns_mort){ num_turns_mort = new_num_turns_mort;}

	bool traits::operator>(const traits& t){
		if(get_prop_val() <= prop_val){
			return true;
		}

		else{
			return false;
		}
	}
	bool traits::operator<(const traits& t){
				if(prop_val <= get_prop_val()){
			return true;
		}
			else{
			return false;
		}
	}
traits& traits::operator=(const traits& copy) {
	prop_val = copy.prop_val;
	name = copy.name;
		is_owned = copy.is_owned;
	mortgage = copy.mortgage;
	rent = copy.rent;
	
return *this;
}

int traits::get_name(){
	return name;
}

	void traits::set_name(int new_name){name = new_name;}

#endif