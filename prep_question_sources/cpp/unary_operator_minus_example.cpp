#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
class point {
private:
  int x,y;
public:
  point(int x=1, int y=1): x(x), y(y) {}
  void printpoint(){ cout<< "\nX: " << x << " Y: " << y;}
  void operator -() { cout << "\nMinus operator call."; x=-x; y=-y ; }
};
int main() {
  point p;
  p.printpoint();
  -p;
  p.printpoint();
  return 0;
}
