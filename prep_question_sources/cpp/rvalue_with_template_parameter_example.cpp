// [[file:~/github/prep/cpp/Questions.org::rvalue with template example.][rvalue with template example.]]
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

template <typename T>
void func (const T &&ref) { // const is best practise and not mandatory.
  cout << "\nCall by lvalue reference " << ref;
}
void func (const int ref) { // const is best practise and not mandatory.
  cout << "\nCallX by lvalue reference " << ref;
}
int main() {
  int x = 0;
  func(x); // lvalue reference
  func(&x); // lvalue reference
  func(0); // rvalue reference
  func(move(x)); // lvalue reference
  func(static_cast<int&&>(x)); // lvalue reference
  return 0;
}
// rvalue with template example. ends here
