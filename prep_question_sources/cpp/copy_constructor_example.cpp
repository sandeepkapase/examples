// [[file:~/github/prep/cpp/Questions.org::copy constructor example.][copy constructor example.]]
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>






/* This example will work without copy constructor because we very basic example.
   When we have complex object allocation where we need to carefully while copying state one object to another,
   copy constructor plays key role. */
using namespace std;
class point {
private :
  int x,y;
public:
  point() { cout << "\ndefault constructor";}                                     // default constructor
  point(const point &p) {cout << endl << "Copy Constructor: ";}                  // copy constructor
  point (int x, int y): x(x), y(y) {cout << "\nparameterized constructor";}      // parameterized constructor
  void operator = (point &x) {                                                   // = operator overloading
    cout << endl << "= operator overloading\t" << x.x << "\t" << x.y;
    this->x = x.x;
    this->y = x.y;
  }
};

point testfun(point x) {
  return x;
}
int main() {
  const point c{}; // default constructor call
  point j{}; // default constructor call
  point k; // default constructor call
  point p(1,2);
  point p1 = p; // copy constructor.
  p1 = p; // this will invoke equal to operator ( either overloaded or default compiler generated)
  testfun(p); // 2 calls : passing and returning.
  return 0;
}
// copy constructor example. ends here
