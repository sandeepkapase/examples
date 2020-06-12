#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
class Base
{
public:
  virtual void myfun() final // Prevent implementing this function in derived class
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
