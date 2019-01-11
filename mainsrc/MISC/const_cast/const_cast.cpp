#include <bits/stdc++.h>
#include <boost/dynamic_bitset.hpp>
#include <queue>
#include <iostream>

using namespace std;

int main (void)
{
  int x = 11;
  const int &ref = x;
  const int *ptr = &x;

  cout << endl << x <<  endl << ref << endl << *ptr << endl;

  const_cast<int &>(ref) = 12;
  cout << endl << x <<  endl << ref << endl << *ptr << endl;
  
  *const_cast<int *>(ptr) = 13;
  cout << endl << x <<  endl << ref << endl << *ptr << endl;
  
  return EXIT_SUCCESS;
}
