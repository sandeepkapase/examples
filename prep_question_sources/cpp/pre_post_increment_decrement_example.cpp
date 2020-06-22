// [[file:~/github/prep/cpp/Questions.org::pre-post increment operators.][pre-post increment operators.]]
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
  void printpoint() { cout<< "\nX: " << x << " Y: " << y;}
  point operator --() { --x; --y; return *this;}
  point operator ++() { ++x; ++y; return *this;}
  point operator --(int) { point p(x,y); x++; y++; return p;} // post
  point operator ++(int) { point p(x,y); x--; y--; return p;} // post
};
int main() {
  point p;
  p.printpoint();
  --p;
  p.printpoint();
  ++p;
  p.printpoint();
  point q = p++;
  p.printpoint();
  q.printpoint();
  q = p--;
  p.printpoint();
  q.printpoint();
  return 0;
}
// pre-post increment operators. ends here
