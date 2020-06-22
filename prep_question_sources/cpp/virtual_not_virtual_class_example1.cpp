// [[file:~/github/prep/cpp/Questions.org::virtual and non virtual class basic difference _vptr][virtual and non virtual class basic difference _vptr]]
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

class NonVirtualClass {
public:
  void foo() {}
};

class VirtualClass {
public:
  virtual void foo() {}
};

int main() {
  cout << "Size of NonVirtualClass: " << sizeof(NonVirtualClass) << endl;
  cout << "Size of VirtualClass: " << sizeof(VirtualClass) << endl;
}
// virtual and non virtual class basic difference _vptr ends here
