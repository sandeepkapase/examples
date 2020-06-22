// [[file:~/github/prep/cpp/Questions.org::problem with enum][problem with enum]]
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>






using namespace std;
enum CarColor {Black, Blue, Red};
//enum BikeColor {Black, Blue, Red};  // Error :  conflicts with a previous dec
int main() {
  CarColor c = Blue;
  cout << "Color: " << c;
  return 0;
}
// problem with enum ends here
