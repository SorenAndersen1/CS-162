 /********************************************************************* 
 ** Program Filename:  apartments.cpp
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: cpp for apartments

 some of these functions are just to get data from the array inside of this class
 test
 ** Input: 
 ** Output: 
 *********************************************************************/ 
 #include "apartments.h"
#include <iostream>
#include <cstdlib>
using namespace std;


tenants_traits apartments::get_tenants(int index){
	return test[index];
}
void apartments::make_tenant_array(int tenant_num){
	test = new tenants_traits[tenant_num];
}
void apartments::set_tenant_array(int num_apartments){
	for (int i = 0; i < num_tenants; i++)
	{
			test[i].set_max_money((rand()%4500 + 500));
		test[i].set_in_house(false);
		test[i].set_in_apartment(true);
		test[i].set_agreeability(rand()%4 + 1);

	}
}

	void apartments::set_num_tenants(int new_num_tenants){num_tenants = new_num_tenants;}
	int apartments::get_num_tenants(){return num_tenants;}
int apartments::get_max_money(int idx){return test[idx].get_max_money();}
int apartments::get_agreeability(int idx){return test[idx].get_agreeability();}
apartments::apartments(const apartments& copy){
	test = copy.test;
	num_tenants = copy.num_tenants;
}
apartments::apartments(){
 test = NULL;
 num_tenants = 0;
}
apartments::~apartments(){
	if(test != NULL){
		delete [] test; 
	}

}

