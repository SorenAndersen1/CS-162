/****************************************************** 
** Program: run_
netflix
.cpp 
** Author: Soren Andersen
** Date: 10/7/18
** Description: Reads through a .txt in a specific format and generates data based on it.
** Input: .txt and command line argument for name of .txt
** Output: Data
******************************************************/ 


#include "assignment1.h"
using namespace std;

void get_genre_data(genre* genre_array, int amount_of_movies, ifstream& input); 
void get_movie_data(movie* movie_array, int num_movies, ifstream &input); 
void delete_info(genre*g, ifstream &input);


/********************************************************************* 
 ** Function: main
 ** Description: Calls most of the functions, mainly the functions that create the data
 ** Parameters:  command line
 ** Pre- 
Conditions: Command line 
 ** Post-
Conditions: 
 *********************************************************************/ 
int main(int argv, char** argc){

	ifstream input;
	input.open(argc[1]);

	while(!input.is_open()){
		cout << "Please re enter file name" << endl;
		cin >> argc[1];
		input.open(argc[1]);
	}


	int amount_of_movies = 0;
	input >> amount_of_movies;
		genre* genre_array = new genre[amount_of_movies];
	
	//get_genre_data(genre_array, amount_of_movies, input);

	bad_coder_func(genre_array);
	
	highest_rating(genre_array, amount_of_movies);
	average_rating(genre_array, amount_of_movies);
	most_movies(genre_array, amount_of_movies);
	suggested_movies(genre_array, amount_of_movies);
	most_actors(genre_array,amount_of_movies);

	delete_info(genre_array, input);

}

/********************************************************************* 
 ** Function: print_func
 ** Description: Prints out array just to test it
 ** Parameters:  genre_array
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void print_func(genre* genre_array)
{
	for (int i = 0; i < 2; ++i)
	{
		cout << genre_array[i].genre_name << endl << endl;
		for (int j = 0; j < genre_array[i].num_movies; ++j)
		{
			cout << genre_array[i].m[j].title << " ";
			cout << genre_array[i].m[j].rating << " ";
			cout << genre_array[i].m[j].num_actors << " ";
			cout << genre_array[i].m[j].actors[i] << " ";
			cout << genre_array[i].m[j].suggested << " " << endl << endl;

		}
	}
}
/********************************************************************* 
 ** Function: get_genre_data
 ** Description: inputs the main genre array's values, and creates the movie array to pointer
 ** Parameters:  genre_array w the amount of genres aptly named amount_of_movies
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void get_genre_data(genre* genre_array, int amount_of_movies, ifstream& input){
	for(int i = 0; i < amount_of_movies; i++){

	input >> genre_array[i].genre_name;
	input >> genre_array[i].num_movies;
	
	
	genre_array[i].m = create_movies(genre_array[i].num_movies);
	cout << "movie " << i << " was created" << endl;
	
	cout << "Genre Name:" << genre_array[i].genre_name << endl;
	cout << "Number of movies " << genre_array[i].num_movies << endl;


}	

}	

/********************************************************************* 
 ** Function: create_movies
 ** Description: Creates the movie array
 ** Parameters:  The amount of movies
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
movie* create_movies(int amount_of_movies) {
	movie* movie_array = new movie[amount_of_movies];
	return movie_array;
}
/********************************************************************* 
 ** Function: get_movie_data
 ** Description: assigns the movie_array values
 ** Parameters:  movie array and what movie its on, plus input
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void get_movie_data(movie* movie_array, int number_movies, ifstream &input){
	for(int i = 0; i < (number_movies); i++){
		input >> movie_array[i].title;
		input >> movie_array[i].rating;
		input >> movie_array[i].num_actors;
		//cout << "title: " << movie_array[i].title << endl;
		//cout << "rating " << movie_array[i].rating << endl;
		//cout << "Actor " << movie_array[i].num_actors << endl;

		movie_array[i].actors = new string[movie_array[i].num_actors];
		for(int j = 0; j < movie_array[i].num_actors; j++){
				input >> movie_array[i].actors[j];
				cout << "Actors " << movie_array[i].actors[j] << endl;
		}
		
		input >> movie_array[i].suggested;
		cout << "Suggested " << movie_array[i].suggested << endl;

	}
}
/********************************************************************* 
 ** Function: most_movies
 ** Description: Checks which genre has the most movies then prints it
 ** Parameters:  The genre array which you can get the movie number from and 
 the amount of movies
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void most_movies(genre* genre_array, int amount_of_movies){
	int check = 0;
	for(int i = 0; i < amount_of_movies; i++){
		if(genre_array[i].num_movies >= genre_array[i + 1].num_movies){
			check = i;

	
		}
	else{
		continue;
	}
	}
	cout << "The genre with the most number of movies is: " << genre_array[check].genre_name << " with: " << genre_array[check].num_movies << " movies." << endl;
}

/********************************************************************* 
 ** Function: highest_rating
 ** Description: Checks all movies to see the highest rated one
 ** Parameters:  Genre_array to see ratings, it also needs amount of movies for
 the for loop
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void highest_rating(genre* genre_array, int amount_of_movies){
	int g_check = 0;
	int m_check = 0;

	for(int i = 0; i < amount_of_movies; i++){
		for(int j = 0; j < genre_array[i].num_movies; j++){
		if(genre_array[i].m[j].rating >= genre_array[g_check].m[m_check].rating){
			g_check = i;
			m_check = j;

		}

	}
}
		cout << "The highest rated movie is: " << genre_array[g_check].m[m_check].title << " with a rating of " << genre_array[g_check].m[m_check].rating << endl;

}

/********************************************************************* 
 ** Function: average+rating
 ** Description: Takes all the ratings in a genre and adds them up
 and then divides it to find the average rating of movie in a genre
 ** Parameters:  genre array and amount of movies
 ** Pre-
Conditions: Needs input from user 
 ** Post-
Conditions: 
 *********************************************************************/ 
void average_rating(genre* genre_array, int amount_of_movies){

		float min_avg = 0;
		cout << "Please enter minimum movie rating amount." << endl;
		cin >> min_avg;
		float avg_rating = 0;
	for(int i = 0; i < amount_of_movies; i++){
		avg_rating = 0;
		for(int j = 0; j < genre_array[i].num_movies; j++){
		
		avg_rating = genre_array[i].m[j].rating + avg_rating;
			
		}
		cout << "The average rating of: " << genre_array[i].genre_name << " is: " << (avg_rating / genre_array[i].num_movies) << endl;
		if((avg_rating / genre_array[i].num_movies) > min_avg){
			cout << "The average rating of this genre is above the minimum inputed." << endl;
		}
		else
			continue;
}
		

}
/********************************************************************* 
 ** Function: most_actors
 ** Description: Checks to see what movie has the most actors
 ** Parameters:  Just picks most recent one if theres a tie
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void most_actors(genre* genre_array, int amount_of_movies){

		
	int g_check = 0;
	int m_check = 0;

	for(int i = 0; i < amount_of_movies; i++){
		for(int j = 0; j < genre_array[i].num_movies; j++){
		if(genre_array[i].m[j].num_actors >= genre_array[i].m[j + 1].num_actors){
			g_check = i;
			m_check = j;

		}

	else{
		continue;
	
	}

}
}
	cout << "The movie with the most actors in it is: " << genre_array[g_check].m[m_check].title << endl;
	cout << "The actors in the movie are: ";
	for(int i = 0; i < genre_array[g_check].m[m_check].num_actors; i++){
		
			cout << genre_array[g_check].m[m_check].actors[i] << " ";
	}
	cout << endl;
}

//this is where my all movies sorted by rating function should go if i want to spend 15 years on it
/********************************************************************* 
 ** Function: suggested_movies
 ** Description: Checks to see if the bool is true and see if the movie is suggested
 ** Parameters: genre_array and amount_of_movies
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void suggested_movies(genre* genre_array, int amount_of_movies){


	for(int i = 0; i < amount_of_movies; i++){
		for(int j = 0; j < genre_array[i].num_movies; j++){
		if(genre_array[i].m[j].suggested == true){
			cout << genre_array[i].m[j].title << " is a suggested title for you " << endl;
		}
		else
			continue;
}
		

}
}
/********************************************************************* 
 ** Function: bad_coder_func
 ** Description: My function for not being able to make my code work, so 
 I hard coded the array to test my functions
 ** Parameters:  genre_array
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void bad_coder_func(genre* genre_array){
	genre_array[0].m = create_movies(3);
	genre_array[1].m = create_movies(2);

	genre_array[0].genre_name = "Comedy";
	genre_array[1].genre_name = "Romance";
	genre_array[0].num_movies = 3;
	genre_array[1].num_movies = 2;
	

	genre_array[0].m[0].actors = new string[1];
	genre_array[0].m[1].actors = new string[2];
	genre_array[0].m[2].actors = new string[2];
	genre_array[1].m[0].actors = new string[2];
	genre_array[1].m[1].actors = new string[2];
		

	genre_array[0].m[0].title = "Zoolander";
	genre_array[0].m[0].rating = 4.5;
	genre_array[0].m[0].num_actors = 1;
	genre_array[0].m[0].actors[0] = "Ben_Stiller";
	genre_array[0].m[0].suggested = true;

	genre_array[0].m[1].title = "Rushmore";
	genre_array[0].m[1].rating = 4.3;
	genre_array[0].m[1].num_actors = 2;
	genre_array[0].m[1].actors[0] = "Bill_Murray";
	genre_array[0].m[1].actors[1] = "Jason_Schwartzman";
	genre_array[0].m[1].suggested = false;

	genre_array[0].m[2].title = "The_Big_Lebowski";
	genre_array[0].m[2].rating = 4.9;
	genre_array[0].m[2].num_actors = 1;
	genre_array[0].m[2].actors[0] = "Jeff_Bridges";
	genre_array[0].m[2].actors[1] = "";
	genre_array[0].m[2].suggested = false;

	genre_array[1].m[0].title = "Titantic";
	genre_array[1].m[0].rating = 4.1;
	genre_array[1].m[0].num_actors = 2;
	genre_array[1].m[0].actors[0] = "Kate_Winslet";
	genre_array[1].m[0].actors[1] = "Leo_DiCaprio";
	genre_array[1].m[0].suggested = true;

	genre_array[1].m[1].title = "The_Notebook";
	genre_array[1].m[1].rating = 3.9;
	genre_array[1].m[1].num_actors = 2;
	genre_array[1].m[1].actors[0] = "Ryan Gosling";
	genre_array[1].m[1].actors[1] = "Rachel_McAdams";
	genre_array[1].m[1].suggested = false;

	
}
/********************************************************************* 
 ** Function: delete_info
 ** Description: Deletes all necessary components
 ** Parameters:  genre_array and the input
 ** Pre-
Conditions: 
 ** Post-
Conditions: 
 *********************************************************************/ 
void delete_info(genre*genre_array, ifstream &input){
	
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < genre_array[i].num_movies; ++j)
		{
			delete[] genre_array[i].m[j].actors;
			delete[] genre_array[i].m;
			delete[] genre_array;
		}
		
	}
	input.close();
}









