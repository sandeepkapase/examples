#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
class Base final {};
class Derived : public Base {};

int main()
{
  Derived d;
  Base &b = d;
  return 0;
}
