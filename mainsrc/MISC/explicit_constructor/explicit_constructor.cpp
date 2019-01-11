#include <bits/stdc++.h>
#include <boost/dynamic_bitset.hpp>
#include <queue>
#include <iostream>

using namespace std;

class base {
private:
  int a;
  int b;
public:
  explicit base(int a):a(a) {  }
  base(int a, int b):a(a), b(b) {  }
  int geta() {
    return a;
  }
};

int main (void) {
  base base_vara = 111; // can not call this
  base base_varb = {111, 222};
  cout << endl << "Value is : " << base_varb.geta();
  return 0;
}

