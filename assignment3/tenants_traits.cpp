/********************************************************************* 
 ** Program Filename:  tenants_traits.cpp
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: cpp for tenants_traits
 ** Input: 
 ** Output: 
 *********************************************************************/ 

#include "tenants_traits.h"
#include <iostream>



	int tenants_traits::get_max_money(){return max_money;}
	bool tenants_traits::get_in_house(){return in_house;}
	bool tenants_traits::get_in_apartment(){return in_apartment;}




		void tenants_traits::set_agreeability(int new_agreeability){agreeability = new_agreeability;}
	int tenants_traits::get_agreeability(){return agreeability;}
	// void tenants_traits::set_agreeability(int num_tenants){agreeability = new int[num_tenants];}
	
	void tenants_traits::set_max_money(int new_max_money){max_money = new_max_money;}
	void tenants_traits::set_in_house(bool new_in_house){in_house = new_in_house;}
	void tenants_traits::set_in_apartment(bool new_in_apartment){in_apartment = new_in_apartment;}


tenants_traits::tenants_traits(){
	int max_money = 0;
	int num_tenants = 0;
	bool in_house = false;
	bool in_apartment = false;
	agreeability = 0;

}

tenants_traits::~tenants_traits(){

}