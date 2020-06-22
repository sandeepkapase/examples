// [[file:~/github/prep/cpp/Questions.org::operator overloading basic exmaple][operator overloading basic exmaple]]
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

class point {
private :
  int x,y;
public:
  point(const point &p) {
    cout << endl << "Copy Constructor: ";
    this->x= p.x;
    this->y= p.y;
  }
  void printpoint(void) {
    cout << endl << "pointX: " << x << " pointY: " << y;
  }
  point (int x, int y): x(x), y(y) {}
  point operator + (const point &x) {
    cout << endl << "+ operator overloading\t" << x.x << "\t" << x.y;
    point p(this->x+x.x, this->y+x.y);
    return  p;
  }
  point operator - (const point &x) {
    cout << endl << "- operator overloading\t" << x.x << "\t" << x.y;
    point p(this->x-x.x, this->y-x.y);
    return  p;
  }
  void operator -() {
    this->x = -this->x;
    this->y = -this->y;
    cout << endl << "- operator overloading negate object\t" << this->x << "\t" << this->y;
  }

  void operator = (point &x) {
    cout << endl << "= operator overloading\t" << x.x << "\t" << x.y;
    this->x = x.x;
    this->y = x.y;
  }
};

int main() {
  point x(1,2);
  point y(9,7);
  x = y; // = operator overloading
  x+y;   // + operator overloading.
  x-y;   // + operator overloading.
  point z = x; // copy constructor call.
  -x; // - unary operator.
  //z.printpoint();
  return 0;
}
// operator overloading basic exmaple ends here
