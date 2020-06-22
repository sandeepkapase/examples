// [[file:~/github/prep/cpp/Questions.org::nullptr strongly typed example][nullptr strongly typed example]]
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

void f(int) { cout << endl << "int version";} //#1
void f(char *) { cout << endl << "char * version";} //#2
int main() {
  f(0); //which f is called?
  //f(NULL); // Ambigouts call
  f(nullptr); //unambiguous, calls #2
  return 0;
}
// nullptr strongly typed example ends here
