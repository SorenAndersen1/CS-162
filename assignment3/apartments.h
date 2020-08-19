/********************************************************************* 
 ** Program Filename:  apartments.h
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: h for apartments
 ** Input: 
 ** Output: 
 *********************************************************************/ 
#ifndef APARTMENTS_H
#define APARTMENTS_H

#include "traits.h"
#include "tenants_traits.h"
using namespace std;

class apartments:public tenants_traits{
private:
	tenants_traits* test;
	int num_tenants;


public:
	void apartments_array_func(apartments* apartments_array, int num_apartments);
	void set_num_tenants(int new_num_tenants);
	int get_num_tenants();
	tenants_traits get_tenants(int index);
	void make_tenant_array(int tenant_num);
void set_tenant_array(int num_apartments);
int get_max_money(int idx);
int get_agreeability(int idx);
int get_num_tenants(int idx);

apartments();
apartments(const apartments&);
~apartments();
};

#endif