// [[file:~/github/prep/cpp/Questions.org::override keyword example.][override keyword example.]]
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
  virtual void doExec(int64_t x) {cout<<"Doexec in base"; }
};
class derived: public base {
public:
  // void doExec(int64_t a) override {cout<<"Doexec in derived"; } // This is fix.
  void doExec(int64_t x) const {cout<<"Doexec in base"; } // This does not matches with version of doExec in base.
  void doExec(int a) {cout<<"Doexec in derived"; }
};

int main(void) {
  const derived d;
  base *b = (derived *)&d;
  b->doExec(0);
  return 0;
}
// override keyword example. ends here
