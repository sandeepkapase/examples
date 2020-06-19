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
class A { public: A(int i) {} };
class B: public A { public: B(int i) {} };
class C: public A { public: C(int i) {} };
class D: public B, public C {  public: D(int x) {} };
int main()
{
  D d(1);
  return 0;
}
