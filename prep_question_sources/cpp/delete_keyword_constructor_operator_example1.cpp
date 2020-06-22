// [[file:~/github/prep/cpp/Questions.org::delete keyword with constructor and overload operator.][delete keyword with constructor and overload operator.]]
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
public:
  //S(const S &ref) { cout << endl << "copy constructor called"; this->x = ref.x; this->y = ref.y ; }
  S(const S &ref) {} // Making this delete will prevent object creation
  // S(const S &ref) = delete; // This is FIX

  void operator = (S &ref) { cout << endl << "= overload called"; this->x = ref.x; this->y = ref.y ; } // making this delete will prevent assignment operation.
  // void operator = (S &ref) = delete; // This is FIX
  S(int x, int y): x(x), y(y) {}
};
int main() {
  S s(1,2);
  S t = s; // copy constructor call.
  t = s; // = to overload operator
  return 0;
}
// delete keyword with constructor and overload operator. ends here
