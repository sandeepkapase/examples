// [[file:~/github/prep/cpp/Questions.org::static_cast examples][static_cast examples]]
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
class base {};
class derived :public base {};
class Other {};
int main() {
  base *bptr;
  derived *dptr;
  Other *optr;
  derived d; base *b = &d;

  // This allow cast because B is inherited from A class.
  bptr = static_cast<base *>(dptr);
  dptr = static_cast<derived*>(bptr);
  // for dynamic_cast classed must be polymorphic. source type is not polymorphic
  //bptr = dynamic_cast<base *>(dptr);
  //dptr = dynamic_cast<derived*>(bptr);
  //bptr = dynamic_cast<B *>(aptr); // Error with dynamic cast
  // aptr = dynamic_cast<A *>(bptr); // Error with dynamic cast

  // Error Here: Other class is completely different class (no inheritance relationship)
  //bptr = static_cast<Other *>(aptr);
}
// static_cast examples ends here
