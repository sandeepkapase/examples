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
class Base
{
public:
  //virtual void myfun() final // Prevent implementing this function in derived class
  virtual void myfun() // append final to this function
  {
    cout << "myfun() in Base";
  }
};
class Derived : public Base
{
  void myfun() override {
    cout << "myfun() in Derived\n";
  }
};

int main()
{
  Derived d;
  Base &b = d;
  b.myfun();
  return 0;
}
