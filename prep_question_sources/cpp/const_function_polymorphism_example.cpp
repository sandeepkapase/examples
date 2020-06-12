#include <iostream>
#include <unistd.h>






#include <iostream>
using namespace std;

void somefunc(char *ptr) {std::cout << "\nnono constant version call"; }
void somefunc(char const *ptr) {std::cout << "\nCONSTANT version call";}
void somefuncint(int &ptr) {std::cout << "\nnono constant reference version call"; }
void somefuncint(int const &ptr) {std::cout << "\nCONSTANT reference version call";}

int main() {
  std::cout << "Hello world!";
  char *ptr = "kapse";
  const char *ptr1 = "kapse";
  somefunc(ptr);
  somefunc(ptr1);

  int x = 11;
  int &y = x;
  const int &z = x;
  somefuncint(y);
  somefuncint(z);
  return 0;
}
