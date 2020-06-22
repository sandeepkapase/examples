// [[file:~/github/prep/cpp/Questions.org::constructor delegation example][constructor delegation example]]
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

class Foo {
public:
  Foo(char x, int y) {cout << "\nTwo parameter constructor";}
  Foo(int y) : Foo('a', y) { cout << "\nOne param constructor.";} // Foo(int) delegates to Foo(char,int)
};

int main() {
  Foo f(1);
  return 0;
}
// constructor delegation example ends here
