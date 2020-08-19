

#include <iostream>
#include <string>
#include <cstdlib>
#include "traits.h"
#include "apartments.h"
#include "house.h"
#include "player.h"
#include "buisness.h"
#include "tenants_traits.h"
using namespace std;


void set_rent_buisness(traits* owned_props, buisness* buisness_array, int idx);
/********************************************************************* 
 ** Function: rand_functions
 ** Description: This orignally was supposed to doo all my setup, I may not need these now but I dont 
 want to delete them incase I do
 ** Parameters:  Pop in a type and this will spit out a random value for each
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
double rand_prop_val(string type){
	double return_val;
	if(type == "house"){
		return_val = rand()%100000;
		return return_val;
	}
	else if(type == "apartments"){
		return_val = rand()%300000;
		return return_val;
	}
	else if(type == "buisness"){
		return_val = rand()%400000;
		return return_val;
	}

}
int rand_num_tenants(string type){
	int return_val;
	if(type == "house"){
		return_val = 1;
		return return_val;
	}
	else if(type == "apartments"){
		return_val = ((rand()%9) + 1);
		return return_val;
	}
	else if(type == "buisness"){
		return_val = ((rand()%4) + 1);
		return return_val;
	}

}
string rand_type_prop(){
	int random = rand()%3;

	if(random == 0){
		return "house";
	}
	else if(random == 1){
		return "apartments";
	}
	else if(random == 2){
		return "buisness";
	}
}

string rand_location(){
	int random = rand()%5;

	if(random == 0){
		return "SE";
	}
	else if(random == 1){
		return "NE";
	}
	else if(random == 2){
		return "Midwest";
	}
	else if(random = 3){
		return "SW";
	}
	else if(random = 4){
		return "NW";
	}
}
/********************************************************************* 
 ** Function: diaster funcs
 ** Description: Takes a random number, then does its diaster corresponding,
 funcs cant be more than 20 lines so I had to break it up, plus the last one needs all properties so I had to edit it a hardcode
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void disaster_mod(traits* full_rand_props, traits* owned_props, float mod, string region, int num_buildings){
	for(int i = 0; i < num_buildings; i++){
		if(full_rand_props[i].get_location() == region){
			full_rand_props[i].set_prop_val(full_rand_props[i].get_prop_val() * mod);
		}
		if(owned_props[i].get_location() == region){
			owned_props[i].set_prop_val(owned_props[i].get_prop_val() * mod);
		}
	}

}
void gentrified_func(traits* full_rand_props, traits* owned_props, int num_buildings){
	int rand_num = rand()%3 + 1;
	if(rand_num == 1){
		disaster_mod(full_rand_props, owned_props, 1.20, "SE" , num_buildings);
		cout << "Roy Moore didn't get elected! SE properties increase 20% in value!" << endl << endl;
	}
	if(rand_num == 2){
		disaster_mod(full_rand_props, owned_props, 1.20, "Midwest" , num_buildings);
		cout << "The dustbowl is over? Midwest properties increase 20% in value!" << endl << endl;
	}
	if(rand_num == 3){
		disaster_mod(full_rand_props, owned_props, 1.20, "NW" , num_buildings);
		cout << "Californians move North! NW properties increase 20% in value!" << endl << endl;
	}
	if(rand_num == 4){
		disaster_mod(full_rand_props, owned_props, 1.20, "SW" , num_buildings);
		cout << "The drought is over!! SE properties increase 20% in value!" << endl << endl;
	}
}
void rand_diaster(traits* full_rand_props, traits* owned_props, int num_buildings){
	int rand_num = rand()%5 + 1;
	if(rand_num == 1){
		cout << "A hurricane has occured, 50% off all SE properties" << endl << endl;
		disaster_mod(full_rand_props, owned_props, .50, "SE" , num_buildings);

	}
	if(rand_num == 2){
		cout << "A tornado has occured, 30% off all Midwest properties" << endl << endl;
		disaster_mod(full_rand_props, owned_props, .70, "Midwest" , num_buildings);

	}
	if(rand_num == 3){
		cout << "A earthquake has occured, 10% off all SE properties" << endl << endl;
		disaster_mod(full_rand_props, owned_props, .90, "NW" , num_buildings);

	}
	if(rand_num == 4){
		cout << "A wildfire has occured, 25% off all SE properties" << endl << endl;
		disaster_mod(full_rand_props, owned_props, .75, "SW" , num_buildings);

	}
	if(rand_num == 5){
		cout << "A housing bubble has occured, 30% off all properties" << endl << endl;
		disaster_mod(full_rand_props, owned_props, .70, "SE" , num_buildings);
		disaster_mod(full_rand_props, owned_props, .70, "NW" , num_buildings);
		disaster_mod(full_rand_props, owned_props, .70, "SW" , num_buildings);
		disaster_mod(full_rand_props, owned_props, .70, "Midwest" , num_buildings);
	if(rand_num == 6){
		gentrified_func(full_rand_props, owned_props, num_buildings);
	}

	}
}
/********************************************************************* 
 ** Function: get_three_props
 ** Description: fills buyable props array when its empty
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
traits* get_three_props(int& idx, traits* full_rand_props, traits* buyable_props){

		for(int i = 0; i < 3; i++){

			buyable_props[i].set_type(full_rand_props[(i + idx)].get_type());
			buyable_props[i].set_prop_val(full_rand_props[i + idx].get_prop_val());

			buyable_props[i].set_location(full_rand_props[i + idx].get_location());

			buyable_props[i].set_mortgage(full_rand_props[i + idx].get_mortgage());
			buyable_props[i].set_is_owned(full_rand_props[i + idx].get_is_owned());
			buyable_props[i].set_rent(full_rand_props[i + idx].get_rent());
			buyable_props[i].set_name(full_rand_props[i + idx].get_name());
	}
	idx = idx + 3;


}
/********************************************************************* 
 ** Function: rand_props
 ** Description: makes all the random properties 
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void rand_props(traits* rand_props, int &num_apartments, int &num_house, int &num_buisness, int num_of_buildings){
	for(int i = 0; i < num_of_buildings; i++){
		rand_props[i].set_type(rand_type_prop());
		rand_props[i].set_prop_val(rand_prop_val(rand_props[i].get_type()));
		rand_props[i].set_location(rand_location());
		rand_props[i].set_mortgage((rand()%4999) + 1);
			if(rand_props[i].get_type() == "apartments"){
				rand_props[i].set_name(num_apartments);
				num_apartments++;
		}
		else if(rand_props[i].get_type() == "house"){
				rand_props[i].set_name(num_house);
				num_house++;
		}
				else if(rand_props[i].get_type() == "buisness"){
				rand_props[i].set_name(num_buisness);
				num_buisness++;
		}


	}


}
/********************************************************************* 
 ** Function: zero_buyable
 ** Description: simply zereos any traits varaible
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void zero_buyable(traits* buyable_props, int choice){
				(buyable_props[choice].set_type("Sold"));
			(buyable_props[choice].set_prop_val(0));

			(buyable_props[choice].set_location("      "));

			(buyable_props[choice].set_mortgage(1));
			(buyable_props[choice].set_is_owned(false));
			(buyable_props[choice].set_rent(0));
			(buyable_props[choice].set_name(0));
}
/********************************************************************* 
 ** Function: what_prop_do_they_want
 ** Description: simple function to get name of what prop they want
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
int what_prop_do_they_want(player &main, traits* owned_props){
	
	cout << " Which number propety do you want to change?" << endl;
	for(int i = 0; i < main.get_amt_owned(); i++){
		cout << "PROPERTY NUMBER: " << i << " ";
		cout << owned_props[i].get_type() << " ";
		cout << owned_props[i].get_prop_val() << " ";
		cout << owned_props[i].get_location() << " ";
		cout << owned_props[i].get_mortgage() << " ";
		cout << owned_props[i].get_name() << " ";
		cout << endl;
	}
	int temp = 0;
	cin >> temp;
	return temp;
}

/********************************************************************* 
 ** Function: rand_how_much_money
 ** Description: Sees if they can sell (no one lives there) and then gives them a random (of 3)
 price for the property
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
int rand_how_much_money(player &main, traits* owned_props, apartments* apartments_array){
	int property_num = what_prop_do_they_want(main, owned_props);
	if(owned_props[property_num].get_prop_val() != 0 && apartments_array[owned_props[property_num].get_name()].get_num_tenants() == 0){
	cout << "What is your selling price?" << endl;
	int price = 0;
	cin >> price;
	int rand_num = 0;
	rand_num = rand()%2 + 1;
	if(rand_num == 1){ cout << "Congrats you bidding fiend you got your asking price" << endl;
		main.set_cash(main.get_cash() + price);
	}
	else if(rand_num == 2){	cout << "You got 10% less than the value" << endl;
	main.set_cash(main.get_cash() + (owned_props[property_num].get_prop_val() * .90));
		
	}
	else if(rand_num == 3){	cout << "You got the value" << endl;
		main.set_cash(main.get_cash() + owned_props[property_num].get_prop_val());
		
	}
	cout << "You now have " << main.get_cash() << " dollars " << endl;
	zero_buyable(owned_props, property_num);
}
 else{
 	cout << "There is someone still living there, try again later." << endl;
 }

}
// simple print function
void print_buyable_props(traits* buyable_props, int idx){
	for(int i = 0; i < idx; i++){
		cout << buyable_props[i].get_type() << " ";
		cout << " Price: " << buyable_props[i].get_prop_val() << "  ";
		cout << buyable_props[i].get_location() << " ";
		cout << "Per turn: " << buyable_props[i].get_mortgage() << " ";
		cout << " ID num: " << buyable_props[i].get_name() << " ";
		cout << endl;
	}

}
/********************************************************************* 
 ** Function: buying properties
 ** Description: switches values, and makes sure they can buy the property,
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void finish_buy_prop(traits* buyable_props, traits* owned_props, int choice, player &main, int prop_num, buisness* buisness_array){


			owned_props[prop_num].set_type(buyable_props[choice].get_type());
			owned_props[prop_num].set_prop_val(buyable_props[choice].get_prop_val());

			owned_props[prop_num].set_location(buyable_props[choice].get_location());

			owned_props[prop_num].set_mortgage(buyable_props[choice].get_mortgage());
			owned_props[prop_num].set_is_owned(buyable_props[choice].get_is_owned());
			owned_props[prop_num].set_rent(buyable_props[choice].get_rent());
			owned_props[prop_num].set_name(buyable_props[choice].get_name());
			zero_buyable(buyable_props, prop_num);
if(owned_props[prop_num].get_type() == "buisness"){
	set_rent_buisness(owned_props, buisness_array, prop_num);
}
else{
		cout << "What should rent be for this property? Whole numbers only" << endl;
	int temp_rent = 0;
	cin >> temp_rent;
		owned_props[prop_num].set_rent(temp_rent);
}

}
void buy_property(traits* buyable_props, player &main, traits* owned_props, int &idx, buisness* buisness_array){
	print_buyable_props(buyable_props, 3);

	cout << "What property would you like to buy? Enter 1 2 or 3." << endl;
	int choice = 0;
	cin >> choice;
	choice = choice - 1;
	if(main.get_cash() >= buyable_props[choice].get_prop_val()){
		cout << "Congratulations you now own another property." << endl;
		main.set_amt_owned((main.get_amt_owned() + 1));
		cout << "You will now owe " << ((buyable_props[choice].get_mortgage())) << " a month for 12 months" << endl;
		
			int temp = main.get_amt_owned() - 1;
			finish_buy_prop(buyable_props, owned_props, choice, main, temp, buisness_array);
			--idx;
	}

	else{
		cout << "You do not have enough money to buy this property, try again." << endl;
	}
}
/********************************************************************* 
 ** Function: angry_tenant
 ** Description: Sees how many of the tenants can pay the rent (rent > max budget)
 then sees if the agreeability score is lower than 2 to see if the player can sell it
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
int angry_tenant(int idx, traits* owned_props, apartments* apartments_array, house* house_array){


int num_of_angry_tenants = 0;


	if(owned_props[idx].get_type() == "apartments"){
		for (int i = 0; i < apartments_array[owned_props[idx].get_name()].get_num_tenants(); ++i)
		{
		
		
		if(owned_props[idx].get_rent() >= apartments_array[owned_props[idx].get_name()].get_max_money(i)){
			if( apartments_array[owned_props[idx].get_name()].get_agreeability(i) <= 2){
				num_of_angry_tenants++;
			}
			else{
				apartments_array[owned_props[idx].get_name()].set_max_money(0);
				cout << "Uh oh! A tenant from apartment " << owned_props[idx].get_name() << " is gone" << endl; 
				apartments_array[owned_props[idx].get_name()].set_num_tenants(apartments_array[owned_props[idx].get_name()].get_num_tenants() - 1);

				num_of_angry_tenants++;}
				
		
		}
	}
	cout << num_of_angry_tenants << " many people out of: " << apartments_array[owned_props[idx].get_name()].get_num_tenants() << " refused to pay rent this month for " << owned_props[idx].get_type() << " number: " << owned_props[idx].get_name()<< endl;

}
	if(owned_props[idx].get_type() == "house" && house_array[owned_props[idx].get_name()].get_max_money(0) != 0){
		
		if(owned_props[idx].get_rent() >= house_array[owned_props[idx].get_name()].get_max_money(0)){
			if( house_array[owned_props[idx].get_name()].get_agreeability(0) <= 2){
				num_of_angry_tenants++;
			}
			else{
				house_array[owned_props[idx].get_name()].set_max_money(0);
				cout << "Uh oh! You're tenant from house " << owned_props[idx].get_name() << " just left" << endl;
				return 1;}
		}
		cout << num_of_angry_tenants << " many people out of: " << house_array[owned_props[idx].get_name()].get_num_tenants() << " refused to pay rent this month for " << owned_props[idx].get_type() << " number: " << owned_props[idx].get_name()<< endl;

	}


return num_of_angry_tenants;
}
/********************************************************************* 
 ** Function: rent_funcs
 ** Description: getting the apartments and house rent is easy its store in the owned properties
 but mutiple rents can be set for buisnesses so a seperate func had to made for that, then returns so the player can make money
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
int buisness_rent_func(traits* owned_props, buisness* buisness_array, int idx){
	int return_val;
	for (int i = 0; i < buisness_array[owned_props[idx].get_name()].get_num_tenants(); i++){
			return_val = return_val + buisness_array[owned_props[idx].get_name()].get_rent(i);
	}
	return return_val;
}
void set_rent_buisness(traits* owned_props, buisness* buisness_array, int idx){
	cout << "There are " << buisness_array[owned_props[idx].get_name()].get_num_tenants() << " tenants" << endl;

	for(int i = 0; i < buisness_array[owned_props[idx].get_name()].get_num_tenants(); i++){

		cout << "What should rent be for tenant number: " << i + 1 << endl;
		int new_rent = 0;
		cin >> new_rent;
		buisness_array[owned_props[idx].get_name()].set_rent(i, new_rent);
	}
}
void check_rent(player &main, traits* owned_props, buisness* buisness_array){
	int temp;
	temp = what_prop_do_they_want(main, owned_props);
	if(owned_props[temp].get_type() == "apartments" || owned_props[temp].get_type() == "house"){
	cout << "Property " << temp << "'s rent is: " << owned_props[temp].get_rent() << endl;
}
	else if(owned_props[temp].get_type() == "buisness"){
		for(int i = 0; i < buisness_array[owned_props[temp].get_name()].get_num_tenants(); i++){
			cout << "Rent for tenant " << i + 1 << " is: " << buisness_array[owned_props[temp].get_name()].get_rent(i) << endl;
		}
	}
}


/********************************************************************* 
 ** Function: debt_func
 ** Description: deals with both adding money through rent to the player and 
 deals with subtracting money through taxes 
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void debt_func(player &main, traits* owned_props, apartments* apartments_array, house* house_array, buisness* buisness_array){
	for (int i = 0; i < main.get_amt_owned(); ++i)
	{
		if(owned_props[i].get_type() == "apartments"){
		main.set_cash((main.get_cash() + (apartments_array[owned_props[i].get_name()].get_num_tenants() - angry_tenant(i, owned_props, apartments_array, house_array)) * owned_props[i].get_rent()));
		main.set_cash((main.get_cash() - (owned_props[i].get_prop_val() * .015)));
	}
		if(owned_props[i].get_type() == "house"){
		main.set_cash((main.get_cash() + (house_array[owned_props[i].get_name()].get_num_tenants() - angry_tenant(i, owned_props, apartments_array, house_array)) * owned_props[i].get_rent()));
		main.set_cash((main.get_cash() - (owned_props[i].get_prop_val() * .015)));
	}
		if(owned_props[i].get_type() == "buisness"){
			main.set_cash((main.get_cash() + (buisness_rent_func(owned_props, buisness_array, i))));
			main.set_cash((main.get_cash() - (owned_props[i].get_prop_val() * .015)));
		}
		if(owned_props[i].get_num_turns_mort() != 12){
		main.set_cash((main.get_cash() - owned_props[i].get_mortgage()));
		owned_props[i].set_num_turns_mort(owned_props[i].get_num_turns_mort() + 1);
	}

}
	
	cout << "You have " << main.get_cash() << " dollars" << endl;
}


int print_options(){
	cout << endl;
	cout << "What would you like to do?" << endl;
		cout << "1 Buy Property" << endl;
			cout << "2 Sell Property" << endl;
				cout << "3 Adjust Rent" << endl;
					cout << "4 End Turn" << endl;
						cout << "5 Check Rent on a property" << endl;
	int temp = 0;
	cin >> temp;
	return temp;
}
void set_new_rent(traits* owned_props, player& main, buisness* buisness_array){
	int property_num = what_prop_do_they_want(main, owned_props);
	if(owned_props[property_num].get_type() == "apartments" || owned_props[property_num].get_type() == "house"){
	cout << "Whats the new rent? " << endl;
	int temp = 0;
	cin >> temp;
	
		owned_props[property_num].set_rent(temp);
	cout << "Rent is now " << temp << " dollars." << endl << endl;

}
	else if(owned_props[property_num].get_type() == "buisness"){
			set_rent_buisness(owned_props, buisness_array, property_num);
	}
}
/********************************************************************* 
 ** Function: actual game funcs
 ** Description: Turn function does exactly does what it sounds like
 asks the player what they want and then does it
 win func checks to see if they won or lost
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void win_func(player &main){
	if(main.get_cash() >= 1000000){
		cout << "You have won!" << endl;
	}
	if(main.get_cash() <= 0){
		cout << "You have somehow lost" << endl;
	}
}

void turn_func(player &main, traits* owned_props, apartments* apartments_array, house* house_array, traits* buyable_props, traits* full_rand_props, int num_buildings, buisness* buisness_array){
		int idx = 0;
		int num_props_left = 3;
		get_three_props(idx, full_rand_props, buyable_props);
	do{ do{
		
		debt_func(main, owned_props, apartments_array, house_array, buisness_array);
		int choice = print_options();
		if(choice == 1){
 	
buy_property(buyable_props, main, owned_props, num_props_left, buisness_array);
	if(num_props_left == 0){
		get_three_props(idx, full_rand_props, buyable_props);
		num_props_left = 3;
	}
}
	if(choice == 2){
		rand_how_much_money(main, owned_props, apartments_array);
	}
	if(choice == 3){
		set_new_rent(owned_props, main, buisness_array);
	}
	else if(choice == 5){
		check_rent(main, owned_props, buisness_array);
	}
	if(choice == 4){
		break;
	}
	}while(true);
		rand_diaster(full_rand_props, owned_props, num_buildings);
		
		
	}while(main.get_cash() > 0 && main.get_cash() < 1000000);
		win_func(main);
}


/********************************************************************* 
 ** Function: _______ array_func()
 ** Description: makes the arrays for various types, worst way to do this ever
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void apartments_array_func(apartments* apartments_array, int num_apartments){

	for (int i = 0; i < num_apartments; ++i)
	{
		apartments_array[i].make_tenant_array(apartments_array[i].get_num_tenants());
		apartments_array[i].set_tenant_array(apartments_array[i].get_num_tenants());
	}
}
void buisness_array_func(buisness* buisness_array, int num_buisness){
	for(int i = 0; i < num_buisness; i++){
		buisness_array[i].make_tenant_array(buisness_array[i].get_num_tenants());
		buisness_array[i].set_tenant_array(buisness_array[i].get_num_tenants());
	}
}

void house_array_func(house* house_array, int num_house){

	for (int i = 0; i < num_house; ++i)
	{
		house_array[i].make_tenant_array(house_array[i].get_num_tenants());
		house_array[i].set_tenant_array(house_array[i].get_num_tenants());
	}
}
/********************************************************************* 
 ** Function: start_game
 ** Description: starts the game and makes iterations of all the class
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void start_game(){
	srand(time(NULL));
	int num_of_buildings = 20;
	int num_apartments = 0;
	int num_house = 0;
	int num_buisness = 0;
	player main;
	traits full_rand_props[num_of_buildings];
	traits buyable_props[3]; 
	traits owned_props[num_of_buildings];


	rand_props(full_rand_props, num_apartments, num_house, num_buisness, num_of_buildings);
		house house_array[num_house];
	buisness buisness_array[num_buisness];
		apartments aprt[num_apartments];
 apartments_array_func(aprt, num_apartments);
house_array_func(house_array, num_house);
buisness_array_func(buisness_array, num_buisness);

		

 turn_func(main, owned_props, aprt, house_array,buyable_props, full_rand_props, num_of_buildings, buisness_array);

}


/********************************************************************* 
 ** Function: int main
 ** Description: starts game
 ** Parameters:  
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
int main(){
 
 start_game();

	return 0;
}