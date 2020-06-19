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
  B() { cout << endl << "B's def constructor";}
  B(int x) { cout << endl << "B's param constructor";}
  ~B() { cout << endl << "B's destructor";}
  void fun(void) {}
};
class D1: public B {
public:
  D1() { cout << endl << "D1's def constructor";}
  D1(int x):B(x) { cout << endl << "D1's param constructor";}
  ~D1() { cout << endl << "D1's destructor";}
  void fun(void) {}
};
class D2: public B {
public:
  D2() { cout << endl <<"D2's def constructor";}
  D2(int x):B(x) { cout << endl <<"D2's param constructor";}
  ~D2() { cout << endl <<"D2's destructor";}
  void fun(void) {}
};
class DD1: public D1, D2 {
public:
  DD1() { cout << endl << "DD1's def constructor";}
  DD1(int x):D1(x), D2(x) { cout << endl << "DD1's param constructor";}
  ~DD1() { cout << endl << "DD1's destructor";}
  void fun(void) {}
};
int main(int argc, char*argv[]) {
  DD1 D(1);
  return 0;
}
