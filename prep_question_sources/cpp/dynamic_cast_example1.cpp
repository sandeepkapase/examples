// [[file:~/github/prep/cpp/Questions.org::dynamic cast example 1][dynamic cast example 1]]
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
  virtual void test() {}
};
class derived: public base {};

int main() {
  // upcasting : Derived to base pointer casting.
  // downcasting : base to derived pointer casting
  derived *d = new derived();
  base *b = dynamic_cast<base *>(d); // OK: all method from base are available from derived. UPCASTING
  if (b == nullptr)
    cout << "\nderived to base cast failure";

  base *b1 = new base();
  //derived *d1 = static_cast<derived *>(b1); // static cast will be cause runtime error.
  derived *d1 = dynamic_cast<derived *>(b1); // NOT OK; not all methods from derived are available in base.  DOWNCASTING.
  if (d1 == nullptr)
    cout << "\nbase to derived cast failure";
  return 0;
}
// dynamic cast example 1 ends here
