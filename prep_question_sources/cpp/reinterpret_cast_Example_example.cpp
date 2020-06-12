#include <iostream>
#include <unistd.h>






    using namespace std;
    #include <iostream>
    class A {};
    class B:public A {};
    class Other {};
    int main() {
      int *iptr = new int(65);
      // char *cptr = static_cast<char *>(iptr); // Error Here: completely different type
      char *cptr = reinterpret_cast<char *>(iptr);
      cout << "\nint val: " << *iptr;
      cout << "\nchar val: " << *cptr;
return 0;
    }
