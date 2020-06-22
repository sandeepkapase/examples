#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
class testclass {
public:
  testclass() {cout << "\ntestclass constructor"; }
  ~testclass() {cout << "\ntestclass destructor"; }
};
int main(int argc, char*argv[]) {
  auto t = new (testclass[2]);
  delete t; // HERE is problem. We need delete array i.e. delete []t;
  return 0;
}
