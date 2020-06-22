// [[file:~/github/prep/cpp/Questions.org::c++ multiple_multilevel_virtual_inhiritance_constructor_execution_order_example1.][c++ multiple_multilevel_virtual_inhiritance_constructor_execution_order_example1.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
struct A1 {
  A1() { std::cout << "A1, "; }
};

struct A2 {
  A2() { std::cout << "A2, "; }
};

struct AA1 : virtual A1,  A2 {
  AA1() { std::cout << "AA1, "; }
};

struct AA2 : A1, virtual A2 {
  AA2(){ std::cout << "AA2, "; }
};

struct B : AA1, virtual AA2 {
  B() { std::cout << "B "; }
};

int main() {
  B b;
}
// c++ multiple_multilevel_virtual_inhiritance_constructor_execution_order_example1. ends here
