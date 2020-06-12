using namespace std;
#include <iostream>
  void f(int) { cout << endl << "int version";} //#1
  void f(char *) { cout << endl << "char * version";} //#2
int main() {
  f(0); //which f is called?
  //f(NULL); // Ambigouts call
  f(nullptr); //unambiguous, calls #2
  return 0;
}
