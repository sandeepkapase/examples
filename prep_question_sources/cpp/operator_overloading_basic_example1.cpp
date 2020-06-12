using namespace std;
#include <iostream>
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
  //z.printpoint();
  return 0;
}
