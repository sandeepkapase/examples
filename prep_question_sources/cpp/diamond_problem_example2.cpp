#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <list>
#include <tuple>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>






using namespace std;
class B {
public:
  // void fun(void) {} // error: reference to ‘fun’ is ambiguous
};
class D1: public B {};
class D2: public B {};
class DD1: public D1, D2 {
public:
  DD1() { }
};
int main(int argc, char*argv[]) {
  // DD1 D; // Error: error: reference to ‘fun’ is ambiguous
  return 0;
}
