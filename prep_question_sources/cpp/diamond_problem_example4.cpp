using namespace std;
#include <iostream>
//class A { public: A()= default ; A(int i) { cout << "A's constructor" << "\n";} }; // FIX 1 : create default constructor.
class A { public: A(int i) { cout << "A's constructor" << "\n";} };
class B: virtual public A { public: B(int i):A(1) {cout << "B's constructor" << "\n";} };
class C: virtual public A { public: C(int i):A(1) {cout << "C's constructor" << "\n";} };
// class D: public B, public C {  public: D(int x):B(1), C(1) {cout << "D's constructor" << "\n";} }; // PROBLEM HERE
class D: public B, public C {  public: D(int x):A(1), B(1), C(1) {cout << "D's constructor" << "\n";} }; // FIX 2 : explicitely call available constructor.
int main()
{
  D d(1);
  return 0;
}
