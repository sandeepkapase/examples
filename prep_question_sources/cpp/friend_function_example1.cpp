using namespace std;
#include <iostream>
class Vehicle {
private:
  int weight;
public:
  int getweight(void) {
    return weight;
  }
  // Declaration that setdiamention is friend of Vehicle and it should be allowed to access private memeber of Vehicle
  friend int setdiamention(Vehicle &,int);
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
