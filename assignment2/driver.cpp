/****************************************************** 
** Program: driver.cpp 
** Author: Soren Andersen
** Date: 10/21/18 
** Description:  holds main and holds input funcs
** Input: 
** Output: 
******************************************************/ 
#include "assignment2.cpp"
#include "restauraunt.cpp"
#include "menu.cpp"




using namespace std;
char start_func();

void employee_func(Restaurant& r);
void choice_func(char input, Restaurant& r);
int cout_employee_func();
void cust_func(Restaurant& r);
void employee_func(Restaurant& r);

int main(){
	Restaurant r;
	  r.load_data();
	 
 choice_func(start_func(), r);


}

char start_func(){
	cout << "Bytes Pizza" << endl;
	cout << "Are you a customer (C) , employee (E) or would you like to quit (Q)" << endl;
	char input = ' ';
	cin >> input;
	if (input == 'C' || input == 'E'){
		return input;
	}
	else if(input == 'Q'){
	}

	else{
		while(input != 'C' || input != 'Q' || input != 'E'){
		cout << "Please reenter the value" << endl;
		cin >> input;
		if(input == 'C' || input == 'Q' || input == 'E'){
			return input;
			break;

		}
	}
	}


}
void choice_func(char input, Restaurant& r){
	if(input == 'E'){
		if(r.login_func()){
			employee_func(r);

		}
	}
	else if(input == 'C'){
		cust_func(r);
	}
	else if(input == 'Q'){
		cout << "End" << endl;
	}

}
void employee_func(Restaurant& r){
int ez_save = 0;
do{
	ez_save = cout_employee_func();
if(ez_save == 1 ){
	r.change_hours();
}
if(ez_save == 2){
	r.view_orders();
}
if(ez_save == 6){
// r.print_pizzas_rest();
	
}
if(ez_save == 7){

}
if(ez_save == 10){
	cout << "End" << endl;
}
}while(ez_save != 8);
}

int cout_customer_func(){
	cout << "Please enter a number corresponding to your desired location" << endl;
	cout << "(1) View Menu" << endl << endl;
	cout << "(2) Search By Cost" << endl << endl;
	cout << "(3) Search By Ingredients" << endl << endl;
	cout << "(4) Place Order" << endl << endl;
	cout << "(5) View Hours" << endl << endl;
	cout << "(6) View Addres" << endl << endl;
	cout << "(7) View Phone" << endl << endl;
	cout << "(8) Logout" << endl << endl;

	int cust_choice = 0;
	cin >> cust_choice;

	return cust_choice;

	
}
void cust_func(Restaurant& r){
int ez_save = 0;
do{
	
	ez_save = cout_customer_func();

if(ez_save == 1 ){
	r.print_pizzas_rest();
}
else if(ez_save == 2){

}
else if(ez_save == 5){
	r.print_hours();

	cout << endl;
}
else if(ez_save == 6){
 	r.print_address();

}
else if(ez_save == 7){
	r.print_phone();
}

else if(ez_save == 8){
	cout << "You are logged out" << endl;

}
}while(ez_save != 8);
}


int cout_employee_func(){
	cout << "Please enter a number corresponding to your desired location" << endl;
	cout << "(1) Change hours" << endl << endl;
	cout << "(2) View Orders" << endl << endl;
	cout << "(3) Remove Order" << endl << endl;
	cout << "(4) Add Item to Menu" << endl << endl;
	cout << "(5) Remove Item from Menu" << endl << endl;
	cout << "(6) View Menu" << endl << endl;
	cout << "(7) View Hours" << endl << endl;
	cout << "(8) View Address" << endl << endl;
	cout << "(9) View Phone" << endl << endl;
	cout << "(10) Logout " << endl << endl;

	int emp_choice = 0;
	cin >> emp_choice;

	return emp_choice;

	// getting a seg fault at the end because of the r intializer, making load data funcs to see if I 
	// assign values if it will fix itself
}



