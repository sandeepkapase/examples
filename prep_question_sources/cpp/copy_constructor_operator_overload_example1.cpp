// [[file:~/github/prep/cpp/Questions.org::copy constructor and operator overloading example.][copy constructor and operator overloading example.]]
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

class S {
private:
  int x,y;
public: // THis is FIX. Make constructor and = operator public
  // This will restrict object initialization with another object. (private copy constructor.)
  S(S &ref) { cout << endl << "copy constructor called"; this->x = ref.x; this->y = ref.y ; }
  // This will restrict object assignemtn with another object. (private = operator overload)
  void operator = (S &ref) { cout << endl << "= overload called"; this->x = ref.x; this->y = ref.y ; }
public:
  S(int x, int y): x(x), y(y) {}
};
int main() {
  S s(1,2);
  S t = s; // copy constructor call.
  t = s; // = to overload operator
  return 0;
}
// copy constructor and operator overloading example. ends here
