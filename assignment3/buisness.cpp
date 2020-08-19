 /********************************************************************* 
 ** Program Filename:  buisness.cpp
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: cpp for buisness
 like aparmtnets and house but has a weird size part and has differnet numbers
 ** Input: 
 ** Output: 
 *********************************************************************/ 
#include "buisness.h"
#include <iostream>
#include <cstdlib>

void buisness::make_tenant_array(int tenant_num){
	
	tenants = new tenants_biz[tenant_num];
}
void buisness::set_tenant_array(int num_buisness){
	for (int i = 0; i < num_tenants; i++)
	{
			tenants[i].set_max_money((rand()%8000 + 2000));
		tenants[i].set_agreeability(rand()%4 + 1);
		tenants[i].set_rent(0);
		
		int input = rand()%2 + 1;
		if(input == 1){
			tenants[i].set_size('S');
		}
		if(input == 2){
			tenants[i].set_size('M');
		}
		if(input == 3){
			tenants[i].set_size('L');
		}

	}
}
void buisness::set_num_tenants(int new_num_tenants){num_tenants = new_num_tenants;}
	int buisness::get_num_tenants(){return num_tenants;}
int buisness::get_max_money(int idx){return tenants[idx].get_max_money();}
int buisness::get_agreeability(int idx){return tenants[idx].get_agreeability();}
int buisness::get_rent(int idx){return tenants[idx].get_rent();}
void buisness::set_rent(int idx, int new_rent){return tenants[idx].set_rent(new_rent);}
buisness::buisness(){
	tenants  = NULL;
	num_tenants = rand()%4 + 1;

}
buisness::buisness(const buisness& copy){
	tenants = copy.tenants;
	num_tenants = copy.num_tenants;
}
buisness::~buisness(){
	if(tenants != NULL){
		delete [] tenants;
	}
}
