#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
class point {
private:
  int x,y;
public:
  point(int x=1, int y=1): x(x), y(y) {}
  void printpoint(){ cout<< "\nX: " << x << " Y: " << y;}
  point operator -() { point p; p.x=-x; p.y=-y ; return p; }
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
