#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
struct S {
  void func() & {std::cout << "\nlvalue reference";}
  void func() && {std::cout << "\nrvalue reference";}
};
int main(int argc, char*argv[]) {
  S s1;
  s1.func();
  S().func();
  S();
  return 0;
}
