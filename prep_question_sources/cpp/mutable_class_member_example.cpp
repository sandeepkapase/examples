#include <iostream>
#include <unistd.h>






using namespace std;
#include <iostream>
class point {
private:
  int data;
  mutable int accessCount;
public:
  point(int data): data(data), accessCount(0) {}
  int getData () const { accessCount++; return data; }
};
int main() {
  point p(10);
  cout << "\nData: " << p.getData();
  cout << "\nData: " << p.getData();
  return 0;
}
