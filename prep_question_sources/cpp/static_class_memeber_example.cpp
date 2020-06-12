#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
class point {
private:
  int x,y;
  static int dataP;
public:
  static int dataG;
  static int getData() { return dataP; } // can be accessed by static class method
  int getDataobj() { return dataP; } // can be acessed by object method.
};
int point::dataG; // Note that this declaration is required.
int point::dataP; // Note that this declaration is required.
int main() {
  cout << "\nStatic class data: " << point::getData();
  cout << "\nStatic class data: " << point::dataG;
  point p;
  cout << "\nStatic class data: " << p.getDataobj();

  return 0;
}
