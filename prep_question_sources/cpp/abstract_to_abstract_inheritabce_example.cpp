// [[file:~/github/prep/cpp/Questions.org::c++ abstract_to_abstract_inheritabce_example.][c++ abstract_to_abstract_inheritabce_example.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
class base {public: virtual void somefun(void) = 0;};
class derived: public base {};

int main(int argc, char*argv[]) {
  // Can not create derived class instance because derived class also become abstract class as
  // it does not override any pure virtual functions from base class.
  // Note that we need to implement at least one pure virtual function and not just virtual function to make it non-abstract.

  // derived d; // Can not create derived instance
  cout << "Hello world!";
  return 0;
}
// c++ abstract_to_abstract_inheritabce_example. ends here
