// [[file:~/github/prep/cpp/Questions.org::c++ POD_default_vs_value_initialization_example1 example.][c++ POD_default_vs_value_initialization_example1 example.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
class test {
public:
  double x;
  float y;
  test() {cout << "\nTest constructor";}
} ;
int main(int argc, char*argv[]) {
  test t1;
  test t2 = test();
  cout << "\n x: " << t1.x;
  cout << "\n y: " << t1.y;
  cout << "\n x: " << t2.x;
  cout << "\n y: " << t2.y;
  return 0;
}
// c++ POD_default_vs_value_initialization_example1 example. ends here
