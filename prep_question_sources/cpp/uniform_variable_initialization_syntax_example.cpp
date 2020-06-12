using namespace std;
#include <iostream>
int main() {
  int a = int(); //default initialization
  int b = 5; // decaring and initializing
  int c(5); // using parenthesis
  int d{5}; // using braces
  struct S {
    int x;
    int y;
    S(int x, int y): x(0), y(0) {} // constructor member initialization.
  } ;
  // C++11 supported initialization
  //S s{0,0} // ===> equivalent of S s(0,0), c++11 only
  int *ptr = new int[3] {1,2,3}; // c++11 only
  struct X {
    int x[4];
    int y = 100; // c++11 only.
    X(): x{1,2,3,4} {} // constructor member initialization. // c++11 only
  } ;

  return 0;
}
