#include <iostream>
#include <unistd.h>






  using namespace std;
  #include <iostream>

  class base {
  public:
    virtual void test() {}
  };
  class derived: public base {};

  int main() {
// upcasting : Derived to base pointer casting.
// downcasting : base to derived pointer casting
    derived *d = new derived();
    base *b = dynamic_cast<base *>(d); // OK: all method from base are available from derived. UPCASTING
    if (b == nullptr)
        cout << "\nderived to base cast failure";

    base *b1 = new base();
    //derived *d1 = static_cast<derived *>(b1); // static cast will be cause runtime error.
    derived *d1 = dynamic_cast<derived *>(b1); // NOT OK; not all methods from derived are available in base.  DOWNCASTING.
    if (d1 == nullptr)
        cout << "\nbase to derived cast failure";
    return 0;
  }
