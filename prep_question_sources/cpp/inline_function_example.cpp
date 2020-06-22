// [[file:~/github/prep/cpp/Questions.org::inline function example][inline function example]]
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
inline int sum(int a, int b) {
  return a+b;
}
int main() {
  int z = sum(1, 2);
  cout << "Inline result:" << z;
  return 0;
}
// inline function example ends here
