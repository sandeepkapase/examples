#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>









using namespace std;
class testclass {
private :
  int i,j;
public:
  explicit testclass(int i, int j=0): i(i), j(j) { std::cout << "\nConstructor call";}
  bool operator ==(testclass t) { if (t.i == this->i && t.j == this->j) return true; else return false ; }
};


int main() {
  testclass t1(1,0); // explicit call. no problem
  // In below initialization,constructor gets called implicitely.
  // This can be avoided by specifier explicit for constructor i.e prefix explicit to constructor definition
  //testclass t2 = {1,2}; // implicit constructor call
  //testclass t3 = 1;     // implicit constructor call.
  //t1 == 1 ;               // implicit constructor call.
}
