// [[file:~/github/prep/cpp/Questions.org::c++ inline_function_basic_example1 example.][c++ inline_function_basic_example1 example.]]
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
inline int add(int a, int b) {
  return a+b;
}
int main(int argc, char*argv[]) {
  cout << "Hello world!";
  int c = add(1,2);
  return 0;
}
// c++ inline_function_basic_example1 example. ends here
