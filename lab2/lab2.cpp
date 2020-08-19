#include <iostream>
#include <fstream>



using namespace std;


struct students{
	int idnum;
	string first_name;
	string last_name;
	string majors_num;
};
void sort_id(students* stu_array, int num_students);
void get_student_db_info(students* stu_array, int num_students, ifstream &input){
	for(int i = 0; i < num_students; i++){
		input >> stu_array[i].idnum;
		input >> stu_array[i].first_name;
		input >> stu_array[i].last_name;
		input >> stu_array[i].majors_num;
	}

	for(int i = 0; i < num_students; i++){
		cout << stu_array[i].idnum << " ";
		cout << stu_array[i].first_name << " ";
		cout << stu_array[i].last_name << " ";
		cout << stu_array[i].majors_num << " ";
		cout << endl;
}
}

int main(){
	ifstream input;
	input.open("input.txt");
	int num_students = 0;
	input >> num_students;
	students* stu_array = new students[num_students];
	

	get_student_db_info(stu_array, num_students, input);
	sort_id(stu_array, num_students);


	input.close();
}

void sort_id(students* stu_array, int num_students){
 int* array = new int[num_students];
 for (int j = 0; j < num_students; ++j)
 {
 	/* code */
 
	for (int i = 0; i < num_students; ++i)
	{
		if(stu_array[j].idnum > array[i]){
			array[i + 1] = array[i];
			array[i] = stu_array[j].idnum;

			break;
		}

	}
}
	for (int i = 0; i < num_students; ++i)
	{
		cout << array[i] << endl;
	}

	delete[] array; 
}
/*
void unique_majors(students* stu_array, int num_students){
	string* array = new string[num_students];
	for (int i = 0; i < num_students; ++i)
	{
		stu_array[i].majors_num
	for (int j= 0; j < num_students; ++j)
	{
		/* code 
	
		if(stu_array[i].majors_num == array[j]){
			continue;
		}
		else{}
	}
	}
}
/*

void sort_lastname(students* stu_array, int num_students){
string* array = new string[num_students];
	int min_val, min_idx;
	for(int i = 0; i < num_students; i++){
		min_idx = i;
		min_val = stu_array[i].last_name;
		for (int j = i + 1; j < num_students; ++j)
		{
			if(stu_array[j].last_name < min_val){
				min_val = stu_array[j].last_name;
				min_idx = j;
			}
		}
		stu_array[min_idx].last_name = stu_array[i];
		stu_array[min_idx].last_name = min_val;
	}
	for (int i = 0; i < num_students; ++i)
	{
		cout << stu_array[i].last_name;
	}

}