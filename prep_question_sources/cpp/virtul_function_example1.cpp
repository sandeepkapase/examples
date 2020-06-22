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
  void fun1() { cout << endl << "base fun1";}
  void fun2() { cout << endl << "base fun2";}
};
class derived : public base {
public: void fun1() { cout << endl << "derived fun1";}
};
int main() {
  derived d;
  base *b = &d;
  d.fun1();
  d.fun2();
  b->fun1();
  b->fun2();
  return 0;
}
// virtual function example ends here
