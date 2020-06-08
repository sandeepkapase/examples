#include <bits/stdc++.h>
#include <boost/dynamic_bitset.hpp>
#include <queue>
#include <iostream>

using namespace std;

class testclass {
private:
  int b;
public:
  static int a;
  int y;
};

int testclass::a;

int main (void)
{
  testclass c1;
  c1.a = 111;
  cout << "This is output of stream" << c1.a ;
  return EXIT_SUCCESS;
}
