#ifndef restauraunt_h
#define restauraunt_h
#ifndef assignment_h
#define assignment_h


#include <iostream>
#include <fstream>
#include <string>


using namespace std;


class Menu {
 	private:

 		int num_pizzas;
		Pizza* pizzas;
 	public:
 		void set_num_pizzas(int num){
 			num_pizzas = num;
 		}
 		int return_num_pizzas(){
 			return num_pizzas;
 		}

	/*Menu search_pizza_by_cost(int upper_bound, string size);
 	/Menu search_pizza_by_ingredients_to_include(string* ingredients, int, num_ingredients){
 	};
 	Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int
		num_ingredients);
 	void add_to_menu(Pizza pizza_to_add);
 	void remove_from_menu(int index_of_pizza_on_menu);
 */
}; 
#endif
#endif