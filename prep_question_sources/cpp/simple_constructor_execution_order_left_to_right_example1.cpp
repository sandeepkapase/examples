// [[file:~/github/prep/cpp/Questions.org::c++ simple_constructor_execution_order_left_to_right_example1.][c++ simple_constructor_execution_order_left_to_right_example1.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
struct base0 {
  base0() {cout << "base0 constructor\n"; }
};
struct base1 {
  base1() {cout << "base1 constructor\n"; }
};
struct derived1: public base0, public base1 {
  derived1() {cout << "derived constructor\n"; }
};
struct derived2: public base1, public base0 {
  derived2() {cout << "derived constructor\n"; }
};
int main(int argc, char*argv[]) {
  derived1 d1;
  cout << "\n";
  derived2 d2;
  return 0;
}
// c++ simple_constructor_execution_order_left_to_right_example1. ends here
