#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
enum CarColor {Black, Blue, Red};
enum BikeColor {Black, Blue, Red};
int main() {
  CarColor c = Blue;
  cout << "Color: " << c;
  return 0;
}
