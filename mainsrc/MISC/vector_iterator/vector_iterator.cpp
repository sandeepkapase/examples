#include <bits/stdc++.h>
#include <boost/dynamic_bitset.hpp>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
  vector<int> v(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  vector<int>::iterator itr = v.begin();
  while (itr != v.end()) {
    cout << endl << "Element: " << *itr;
    itr++;
  }
}
