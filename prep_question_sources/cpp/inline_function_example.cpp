using namespace std;
#include <iostream>
inline int sum(int a, int b) {
  return a+b;
}
int main() {
  int z = sum(1, 2);
  cout << "Inline result:" << z;
  return 0;
}
