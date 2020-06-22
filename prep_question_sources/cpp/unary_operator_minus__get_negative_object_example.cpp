// [[file:~/github/prep/cpp/Questions.org::unary operator minus return negative object][unary operator minus return negative object]]
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
private:
  int x,y;
public:
  point(int x=1, int y=1): x(x), y(y) {}
  void printpoint(){ cout<< "\nX: " << x << " Y: " << y;}
  // point operator -() { point p; p.x=-x; p.y=-y ; return p; } // Use either this or friend function version.
  // This can be done with friend function. In friend function, unary operator takes one argument.
  friend point operator -(point &p);
};
point operator -(point &p) { point ret; ret.x=-p.x; ret.y=-p.y ; return ret; }
int main() {
  point p;
  p.printpoint();
  point q = -p;
  p.printpoint();
  q.printpoint();
  return 0;
}
// unary operator minus return negative object ends here
