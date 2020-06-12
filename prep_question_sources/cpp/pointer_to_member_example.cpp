/* const member function can not modify data member of class object */
using namespace std;
#include <iostream>
class point {
private:
  int i,j;
public:
  int x,y;
  int getPointi() {return i;}
  int getPointj() {return j;}
};

int getPointi() {return 0;}
int main() {
  /* pointer to function/data member of class.
     For simplification assume that function/variable is outside the class and
     and we have declare pointer for that function/data.
     Later on attach class namespace to variable/function and pointer. */

  point c{};
  // pointer to data member of class 'x'
  // Now consider x is outside class and we have to declare pointer to it.
  // int x;       // variable.
  // int *x = &x  // pointer declaration.
  // int point::*x = &point::x  // Attach namespace.

  int point::*xptr = &point::x;

  // pointer to data function
  // Now consider getPointi is outside class and we have to declare pointer to it.
  // int getPointi();
  // int (*gptr)() = &getPointi
  // int (point::*gptr)() = &point::getPointi
  int (point::*giptr) () = &point::getPointi;
  cout << "\nClass access with pointer to memeber: " << c.*xptr ;

  return 0;
}
