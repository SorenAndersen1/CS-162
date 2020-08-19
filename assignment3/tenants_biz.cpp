/********************************************************************* 
 ** Program Filename:  tenants_biz.cpp
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: need a different tenant traits for biz since its different
 probably could have done it in a different way
 ** Input: 
 ** Output: 
 *********************************************************************/ 

#include "tenants_biz.h"

	void tenants_biz::set_size(char new_size){size = new_size;}
	void tenants_biz::set_agreeability(int new_agreeability){agreeability = new_agreeability;}
	void tenants_biz::set_max_money(int new_max_money){max_money = new_max_money;}
	void tenants_biz::set_rent(int new_rent){rent = new_rent;}
	char tenants_biz::get_size(){return size;}
	int tenants_biz::get_agreeability(){return agreeability;}
	int tenants_biz::get_max_money(){return max_money;}
	int tenants_biz::get_rent(){return rent;}

tenants_biz::tenants_biz(){
	size = ' ';
	agreeability = 0;
	max_money = 0;
	rent = 1000;
}
tenants_biz::~tenants_biz(){

}