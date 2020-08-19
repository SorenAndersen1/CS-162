 /********************************************************************* 
 ** Program Filename:  tenants_biz.h
 ** Author: Soren Andersen
 ** Date: 11/11/2018
 ** Description: h for tenants_biz.h
 ** Input: 
 ** Output: 
 *********************************************************************/ 
 #ifndef TENANTS_BIZ_H
#define TENANTS_BIZ_H


using namespace std;

class tenants_biz{


private:

	int agreeability; // random 1-5 
	int max_money;
	char size; // S M L
	int rent;

public:

	void set_size(char new_size);
	void set_money(int new_size);
	void set_agreeability(int new_agreeability);
	void set_max_money(int new_max_money);
	void set_rent(int new_rent);


	int get_rent();
	char get_size();
	int get_money();
	int get_agreeability();
	int get_max_money();

	tenants_biz();
	~tenants_biz();
};
#endif