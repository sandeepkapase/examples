// [[file:~/github/prep/cpp/Questions.org::default paramter example][default paramter example]]
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
int capacity(int x, int y=3, int z=5) { return x*y*z ;}
int main() {
  cout << "\nCapacity: " << capacity(1);
  cout << "\nCapacity: " << capacity(9,2);
  cout << "\nCapacity: " << capacity(9,2,23);
  return 0;
}
// default paramter example ends here
