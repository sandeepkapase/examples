// [[file:~/github/prep/cpp/Questions.org::c++ simple_constructor_execution_order_example1. (top to bottom)][c++ simple_constructor_execution_order_example1. (top to bottom)]]
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
struct base1:public base0 {
  base1() {cout << "base1 constructor\n"; }
};
struct derived: public base1 {
  derived() {cout << "derived constructor\n"; }
};
int main(int argc, char*argv[]) {
  derived d;
  return 0;
}
// c++ simple_constructor_execution_order_example1. (top to bottom) ends here
