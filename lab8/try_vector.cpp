#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);
   vector<int> hope_this_works;
   hope_this_works = v;
   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;
   try{
   	cout << v.at(123) << endl;
   }
   catch(out_of_range test){
   	std::cout << "out of range?" << endl;
   }
    cout << v[1] << "test's: " << hope_this_works[1] << endl;
     cout << v.at(1) << ' '<< hope_this_works.at(1) << endl;

   return 0;
}
