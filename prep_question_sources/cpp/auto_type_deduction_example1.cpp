// [[file:~/github/prep/cpp/Questions.org::auto type example][auto type example]]
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
int main() {
  auto i = 0 ; // i is of type int as it is initialized with int value.
  auto c = '0' ; // i is of type char as it is initialized with char value.
  auto ll =11234556000000LL; // ll is of type long long as it is initialize with long long value.
  decltype(0) i1; // i1 is of type int
  decltype(0) i2{1}; // i1 is of type int
  decltype("string") i3{"string"}; // i1 is of type int
  cout << "\n" << i3;
  return 0;
}
// auto type example ends here
