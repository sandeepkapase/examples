// [[file:~/github/prep/cpp/Questions.org::dynamic cast use case exmaple2.][dynamic cast use case exmaple2.]]
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
class D1: public base { public: void printd1() { cout << "\nI am print d1";} };
class D2: public base { public: void printd2() { cout << "\nI am print d2";} };
class D3: public base { public: void printd3() { cout << "\nI am print d3";} };
class D4: public base { public: void printd4() { cout << "\nI am print d4";} };

void testfun(base *b) {
  if (dynamic_cast<D1*>(b) != nullptr) { dynamic_cast<D1*>(b)->printd1(); } else
    if (dynamic_cast<D2*>(b) != nullptr) { dynamic_cast<D2*>(b)->printd2(); } else
      if (dynamic_cast<D3*>(b) != nullptr) { dynamic_cast<D3*>(b)->printd3(); } else
        if (dynamic_cast<D4*>(b) != nullptr) { dynamic_cast<D4*>(b)->printd4(); }
}

int main() {
  base *b;
  srand(time(NULL));
  for (int i=0; i<10; i++) {
    switch (rand()%4) {
    case 0: testfun(new D1()); break;
    case 1: testfun(new D2()); break;
    case 2: testfun(new D3()); break;
    case 3: testfun(new D4()); break;
    }
  }
}
// dynamic cast use case exmaple2. ends here
