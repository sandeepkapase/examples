#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
int capacity(int x, int y=3, int z=5) { return x*y*z ;}
int main() {
  cout << "\nCapacity: " << capacity(1);
  cout << "\nCapacity: " << capacity(9,2);
  cout << "\nCapacity: " << capacity(9,2,23);
  return 0;
}
