// [[file:~/github/prep/cpp/Questions.org::unary operator minus][unary operator minus]]
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
  void operator -() { cout << "\nMinus operator call."; x=-x; y=-y ; }
};
int main() {
  point p;
  p.printpoint();
  -p;
  p.printpoint();
  return 0;
}
// unary operator minus ends here
