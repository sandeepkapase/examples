// [[file:~/github/prep/cpp/Questions.org::friend function example.][friend function example.]]
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

class Vehicle {
private:
  int weight;
public:
  int getweight(void) {
    return weight;
  }
  // Declaration that setdiamention is friend of Vehicle and it should be allowed to access private memeber of Vehicle
  friend int setdiamention(Vehicle &, int);
} ;

int setdiamention(Vehicle &v, int w) {
  v.weight = w;
}
int main() {
  Vehicle v;
  setdiamention(v,1111);
  cout << "Vehicle weight:" << v.getweight();
  return 0;
}
// friend function example. ends here
