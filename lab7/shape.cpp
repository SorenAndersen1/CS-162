#include <iostream>
#include <string>

using namespace std;



class shape{
private:
	string name;
	string color;
public:
	string get_name();
	string get_color();
	virtual int calculate_area() = 0;

	void set_name(string new_name);
	void set_color(string new_color);

	void print_shape_info(shape & s);
shape();
~shape();
};

class rectangle: public shape{
private: 
	int length;
	int width;

public:

	 int get_length();
	 int get_width();

	 void set_length(int new_length);
	 void set_width(int new_width);


	 int calculate_area();


rectangle();
~rectangle();
};

class circle: public shape{
private: 
	int radius;

public:

	 int get_radius();

	 void set_radius(int new_radius);


	 int calculate_area();
	 

circle();
~circle();
}; 

	string shape::get_name(){return name;}
	string shape::get_color(){return color;}
	void shape::set_name(string new_name){name = new_name;}
	void shape::set_color(string new_color){color = new_color;}


	 int rectangle::get_length(){return length;}
	 int rectangle::get_width(){return width;}
	 void rectangle::set_length(int new_length){length = new_length;}
	 void rectangle::set_width(int new_width){width = new_width;}
	 	 int rectangle::calculate_area(){
	 	 	int temp, temp_another;
	 	 	temp = get_length();
	 	 	temp_another = get_width();
	 	 	return (temp * temp_another);
}
	  int circle::get_radius(){return radius;}
	  void circle::set_radius(int new_radius){radius = new_radius;}
	  	 int circle::calculate_area(){
	  	 	int temp;
	  	 	temp = get_radius();
	  	 	return (temp * (666/106));
	  	 }
	  	 
shape::shape(){
	name = " ";
	color = " ";
}
circle::circle(){
	radius = 0;
}
rectangle::rectangle(){
	length = 0;
	width = 0;
}

shape::~shape(){}
circle::~circle(){
}
rectangle::~rectangle(){
}

void print_shape_info(shape& s){
	cout << s.get_name() << endl;
	cout << s.get_color() << endl;
	cout << s.calculate_area() << endl;
 }



int main(){
	 rectangle r;
	  circle c;
	 shape * rect = &r;
	 shape * cir = &c;
	 r.set_width(5);
	 r.set_length(5);
	 rect->set_name("rectangle dangle");
	 rect->set_color("red");
	 c.set_radius(4);
	 cir->set_name("circle");
	 cir->set_color("blue");

	print_shape_info((*rect));
	cout << endl;
	print_shape_info((*cir));



	return 0;
}
