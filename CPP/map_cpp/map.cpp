#include <bits/stdc++.h>
#include <boost/dynamic_bitset.hpp>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
  map<int,string>mapA;
  mapA.insert(pair<int,string>(1, "one"));
  mapA.insert(pair<int,string>(2, "two"));
  mapA.insert(pair<int,string>(3, "three"));
  mapA.insert(pair<int,string>(4, "four"));
  mapA.insert(pair<int,string>(5, "five"));
  cout << endl << "list size: " << mapA.size() << endl;

  map<int,string>::iterator itr = mapA.begin();
  while(itr != mapA.end()) {
    cout << endl << itr->first << "\t" << itr->second;
    itr++;
  }

  return 0;
}
