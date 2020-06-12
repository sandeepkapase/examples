#include <iostream>
#include <unistd.h>







using namespace std;
#include <iostream>
int main() {
    int i;
    const int a = 100; // integer constant
    //a = 200; // Error: Can not change constant.
    const int *b = &a; // pointer to integer constant
    // *b = 200; // Error: can not change value
   int * const c = &i;
   *c = 200 ; // Possible. Pointer is constant and not value.
   //c++;       // Error: Can not change pointer
   int const * const d = &a; // const pointer to const integer
    return 0;
}
