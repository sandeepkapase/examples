#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
#include <iostream>

struct foo {
  //foo() = default; // compiler generated default constructor won't work for const object
  foo() {} // FIX: user defined default constructor.
  int a;
};

int main() {
  const foo b;
}
