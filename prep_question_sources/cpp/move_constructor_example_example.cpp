// [[file:~/github/prep/cpp/Questions.org::move constructor example.][move constructor example.]]
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

class test {
private :
  string name;
public:
  void printname() { cout << "\nName is: " << name ;}
  test(string name): name(name) { cout << "\nParameterized constructor called";} // default constructor
  test(const test &t): name(t.name) { cout << "\nCopy constructor called";} // copy constructor
  void operator = (const test &t) { cout << "\n = operator this->name and t.name " << this->name << t.name ; this->name = t.name; }
  void operator = (const test &&t) { cout << "\n = operator move this->name and t.name " << this->name << t.name ; this->name = move(t.name); }
  test(const test &&t): name(move(t.name)) {cout << "\nmove constructor called";} // move constructor.
} ;
int main() {
  test t("sandeep"); // parameterized constructor
  test t2 = t ;      // copy constructor
  test t3 = move(t) ;      // copy constructor
  t.printname();
  test t4("one");
  test t5("two");
  t4 = t5;
  t4 = move(t5);
  return 0;
}
// move constructor example. ends here
