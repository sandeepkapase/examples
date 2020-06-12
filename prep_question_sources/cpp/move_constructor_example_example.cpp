#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
class test {
private :
  string name;
public:
  void printname() { cout << "\nName is: " << name ;}
  test(string name): name(name) { cout << "\nParameterized constructor called";} // default constructor
  test(const test &t): name(t.name) { cout << "\nCopy constructor called";} // copy constructor
  test(const test &&t): name(move(t.name)) {cout << "\nmove constructor called";} // move constructor.
} ;
int main() {
  test t("sandeep"); // parameterized constructor
  test t2 = t ;      // copy constructor
  test t3 = move(t) ;      // copy constructor
  return 0;
}
