#include <stdlib.h>
#include <stdexcept>
#include <iostream>
using std::exception;
using std::out_of_range;
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }
	  
      ~vector(){
	     delete [] v;
      }
	  
      int size() {
	     return s;
      }
	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
      }

      vector(vector<T> &other) {
      	if( v != NULL && other.v != NULL){
			s = other.s;
                 for(int i = 0; i < other.s; i++)
                        v[i] = other.v[i];
              
                 v = NULL;
      	}
      	else{
      		std::cout << "didnt work" << '\n';
      	}
}

      void operator=(vector<T> &copy){
      	for(int i = 0; i < s-1; i++){
      	copy.v[i] = v[i];
   
      }
  		s = copy.s;
  }

T operator[](int idx){
	 	if( v != NULL ){
	return this->v[idx];
}
else{
	std::cout << "didnt work" << '\n';
}
}
T at(int idx){
	 	if( v != NULL){
	if(idx <= s)
{
	return v[idx];
}
	else{
		throw std::out_of_range("out of my bounds");

	}
	return s;
}
else{
	std::cout << "didnt work" << '\n';
}
}

};