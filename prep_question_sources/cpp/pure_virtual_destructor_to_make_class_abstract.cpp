// [[file:~/github/prep/cpp/Questions.org::pure virtual destructor to make class abstract.][pure virtual destructor to make class abstract.]]
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

class base {public: virtual ~base() = 0;};
class derived: public base {}; // Note that in derived class destructor is not mendatory.
base::~base() {cout << "\nvirtual destructor";} // without this will get error "undefined reference to `base::~base()' "
int main() {
  //base b; // cannot declare variable. Error: ‘b’ to be of abstract type ‘base’
  derived d;
  return 0;
}
// pure virtual destructor to make class abstract. ends here
