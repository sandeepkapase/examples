// [[file:~/github/prep/cpp/Questions.org::typeid operator in c+_][typeid operator in c+_]]
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
int main()
{
  int i = 5;
  float j = 1.0;
  char c = 'a';
  char d = 'b';

  // Get the type info using typeid operator
  const type_info& ti1 = typeid(i * j);
  const type_info& ti2 = typeid(i * c);
  const type_info& ti3 = typeid(c);
  const type_info& ti4 = typeid(d);

  if (ti3 == ti4)
    cout << "\n type of c and d are same: " << ti4.name() << endl ;
  // Print the types
  cout << "ti1 is of type "
       << ti1.name() << endl;

  cout << "ti2 is of type "
       << ti2.name() << endl;

  cout << "ti3 is of type "
       << ti3.name() << endl;

  return 0;
}
// typeid operator in c+_ ends here
