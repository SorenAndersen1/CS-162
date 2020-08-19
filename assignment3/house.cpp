 
/********************************************************************* 
 ** Program Filename:  house.cpp
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: cpp for house
 ** Input: 
 ** Output: 
 *********************************************************************/ 

#include "house.h"
#include "tenants_traits.h"
#include <iostream>
#include <cstdlib>
using namespace std;


void house::make_tenant_array(int tenant_num){
	test = new tenants_traits[tenant_num];
}
void house::set_tenant_array(int num_house){
	for (int i = 0; i < num_house; i++)
	{
		test[i].set_max_money((rand()%4500 + 500));
				test[i].set_agreeability(rand()%4 + 1);
						test[i].set_in_house(true);
		test[i].set_in_apartment(false);

	}
}


	void house::set_num_tenants(int new_num_tenants){num_tenants = new_num_tenants;}
int house::get_max_money(int idx){return test[idx].get_max_money();}
int house::get_agreeability(int idx){return test[idx].get_agreeability();}

int house::get_num_tenants(){return num_tenants;}
tenants_traits house::get_tenants(int index){
	return test[index];
}
house::house(const house& copy){
	test = copy.test;
	num_tenants = copy.num_tenants;
}
house::house(){
	test = NULL;
	num_tenants = 1;
	}

house::~house(){

	if(test != NULL){
		delete [] test; 
	}
}


