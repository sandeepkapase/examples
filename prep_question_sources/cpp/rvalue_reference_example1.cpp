#include <iostream>
#include <unistd.h>







using namespace std;
#include <iostream>
int main() {
  int x;
  int &refx = x;
  // int &refi = 100; // This will give error as you can not create reference to rvalue.
  int &&refi = 100; // This is rvalue reference which allow us to create reference to rvalue.
  return 0;
}
