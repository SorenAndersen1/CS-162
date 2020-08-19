/********************************************************************* 
 ** Program Filename:  traits.h
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: h for traits
 ** Input: 
 ** Output: 
 *********************************************************************/ 
#ifndef TRAITS_H
#define TRAITS_H

// #include "tenants_biz.h"
// #include "tenants_traits.h"
#include <string>

using namespace std;

class traits{

	double prop_val;
	double mortgage;
	double tax_this_is_fifteen;
	int rent;
	bool is_owned;
	string type;
	string location;
	int num_turns_mort;
	int name;

public:

	double get_prop_val();
	double get_mortgage();
	double get_tax_this_is_fifteen(); // i have no idea how this would be useful its always .0015
	int get_rent();
	int get_num_tenants();
	bool get_is_owned();
	string get_type();
	string get_location();
	int get_num_turns_mort();
	int get_name();

		void set_prop_val(double new_prop_val);
		void set_mortgage(double new_mortgage);
		void set_tax_this_is_fifteen(double new_tax_this_is_fifteen); // again have no idea 
		// how this would be useful but im including it for credit
		void set_rent(int new_rent);
		void set_num_tenants(int new_num_tenants);
		void set_is_owned(bool new_is_owned);
		void set_type(string new_type);
		void set_location(string new_location); // this should be randomly done, one of 5?
		void set_num_turns_mort(int new_num_turns_mort);
		void set_name(int new_name);


bool operator>(const traits& t);
bool operator<(const traits& t);

traits& operator=(const traits& copy) ;
traits();
traits(const traits& copy);
virtual ~traits(){};

};

#endif