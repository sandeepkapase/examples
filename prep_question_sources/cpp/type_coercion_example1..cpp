// [[file:~/github/prep/cpp/Questions.org::c++ type_coercion_example1.][c++ type_coercion_example1.]]
#include <assert.h>
#include <typeinfo>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
int main(int argc, char*argv[]) {
  auto i = 1.1f + 1.1; // Here we are using float with double hence result will promoted to higher type which id double.
  const type_info& ti1 = typeid(i);
  cout << "\nType of : " << ti1.name();
  cout << "\nsize of float: " << sizeof(1.1f);
  cout << "\nsize of double: " << sizeof(1.1);
  return 0;
}
// c++ type_coercion_example1. ends here
