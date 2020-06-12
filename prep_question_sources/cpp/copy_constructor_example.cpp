/* This example will work without copy constructor because we very basic example.
   When we have complex object allocation where we need to carefully while copying state one object to another,
   copy constructor plays key role. */
using namespace std;
#include <iostream>
class point {
private:
  int x,y;
public:
  void pointX() const { cout <<"\nDefault constructor";}
  // point() const { cout <<"\nconst Default constructor";}  ==> constructor can not be const
  point() { cout <<"\nDefault constructor";}
  point(int x, int y): x(x), y(y) {cout << "\nConstructor called\n"; }
  point(const point &p) {x=p.x; y=p.y; cout << "Copy constructor called\n";}
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
