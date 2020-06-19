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
  void fun(void) {}
};
class D1: public B {};
class D2: public B {};
class DD1: public D1, D2 {
public:
  DD1() { fun(); }
};
int main(int argc, char*argv[]) {
  DD1 D;
  return 0;
}
