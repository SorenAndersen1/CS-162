#ifndef TENANTS_TRAITS_H
#define TENANTS_TRAITS_H

using namespace std;

class tenants_traits{

private:
	
	int max_money;
	bool in_house;
	bool in_apartment;
	int agreeability; // random 1-5 

public:
	int get_max_money();
	bool get_in_house();
	bool get_in_apartment();
	int get_num_tenants();
	void set_agreeability(int new_agreeability);

	int get_agreeability();
	void set_max_money(int new_max_money);
	void set_in_house(bool new_in_house);
	void set_in_apartment(bool new_in_apartment);
	// void make_tenant_array(int tenant_num);
	void set_num_tenants(int new_num_tenants);
tenants_traits();
~tenants_traits();

};

#endif