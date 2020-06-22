// [[file:~/github/prep/cpp/Questions.org::noexcept operator/function example.][noexcept operator/function example.]]
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
void foo() { throw std::runtime_error("oops"); }
void bar() {}
void tar() noexcept {}
struct S {};
int main() {
  /* In this example foo, bar show result of noexcept because there are not marked noexcept */
  /* function tar show true for noexcept because it explicitely marked with noexcept */
  std::cout << noexcept(foo()) << '\n'; // prints 0
  std::cout << noexcept(bar()) << '\n'; // prints 0
  std::cout << noexcept(tar()) << '\n'; // prints 0
  std::cout << noexcept(1 + 1) << '\n'; // prints 1
  std::cout << noexcept(S()) << '\n';   // prints 1
}
// noexcept operator/function example. ends here
