/********************************************************************* 
 ** Program Filename:  buisness.h
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: h for buisness
 ** Input: 
 ** Output: 
 *********************************************************************/ 

 #ifndef BUISNESS_H
#define BUISNESS_H

#include "tenants_biz.h"
using namespace std;

class buisness{ //public traits{
private:
	tenants_biz* tenants;
	int num_tenants;
	int size;

public:
	void make_tenant_array(int tenant_num);
	void buisness_array_func(buisness* apartments_array, int num_apartments);
	void set_num_tenants(int new_num_tenants);
	int get_num_tenants();
	tenants_biz get_tenants(int index);
void set_tenant_array(int num_apartments);
int get_max_money(int idx);
int get_agreeability(int idx);
int get_num_tenants(int idx);
int get_rent(int idx);
void set_rent(int idx, int new_rent);

buisness();
buisness(const buisness& copy);
~buisness();

};

#endif