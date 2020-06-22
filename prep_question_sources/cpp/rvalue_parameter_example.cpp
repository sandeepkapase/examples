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

void func (const int &ref) { // const is best practise and not mandatory.
  cout << "\nCall by lvalue reference";
}
void func (int &&ref) {
  cout << "\nCall by rvalue reference";
}
void func (int *ref) {
  cout << "\nCall by rvalue reference";
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
