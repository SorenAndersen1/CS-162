/********************************************************************* 
 ** Program Filename:  house.h
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: h for house
 ** Input: 
 ** Output: 
 *********************************************************************/ 
 #ifndef HOUSE_H
#define HOUSE_H

#include "tenants_traits.h"
#include "traits.h"
using namespace std;

class house:public tenants_traits{
private:
	tenants_traits* test;
	 int num_tenants;

public:
	void house_array_func(house* house_array, int num_house);
	void set_num_tenants(int new_num_tenants);
	int get_num_tenants();
	tenants_traits get_tenants(int index);
	void make_tenant_array(int tenant_num);
void set_tenant_array(int num_apartments);
int get_max_money(int idx);
int get_agreeability(int idx);
int get_num_tenants(int idx);
house();
house(const house& copy);
~house();

};

#endif