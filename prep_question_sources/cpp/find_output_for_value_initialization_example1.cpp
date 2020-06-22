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
  foo() = default;
  int a;
};

struct bar {
  bar();
  int b;
};

bar::bar() = default;

int main() {
  foo a{};
  bar b{};
  std::cout << a.a << ' ' << b.b;
}
