// [[file:~/github/prep/cpp/Questions.org::virtual function example][virtual function example]]
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

class base {
public:
  virtual void fun1() { cout << endl << "base fun1";}
};
class derived : public base {
public:
  void fun1() { cout << endl << "derived fun1";}
};
int main() {
  base *b;
  derived d;
  b = &d;
  // Note that if fun1 from derived is getting called because it is declared virtual.
  // Without virtual keyword fun1 from base class will gets called instead of derived class.
  b->fun1();
  return 0;
}
// virtual function example ends here
