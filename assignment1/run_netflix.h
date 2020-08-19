/****************************************************** 
** Program: run_
netflix
.h 
** Author: Soren Andersen 
** Date: 10/7/18
** Description: 
** Input: 
** Output: 
******************************************************/ 



#include <string>
#include <iostream>
#include <fstream>


struct movie{
		std::string title;
		int num_actors;
		std::string *actors;
		float rating;
		bool suggested;
	};

struct genre{
	std::string genre_name;
	movie* m;
	int num_movies;

	};
/* After searching for a while I can't figure out how to put ifstream in the function
if im not declaring it in the same file, and googling it has turned up nothing so I am declaring
the functions using fstream in the .cpp*/
genre* create_genres(int); 

movie* create_movies(int); 
void bad_coder_func(genre* genre_array);
void print_func(genre* genre_array);
void highest_rating(genre* genre_array, int amount_of_movies);
void average_rating(genre* genre_array, int amount_of_movies);
void most_movies(genre* genre_array, int amount_of_movies);
void suggested_movies(genre* genre_array, int amount_of_movies);
void most_actors(genre* genre_array, int amount_of_movies);
