#include <iostream>
#include <unistd.h>







using namespace std;
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
int main(int argc, char*argv[]) {
  vector <int> v(10);
  iota(begin(v), end(v), 0); //0 is the starting number
  for_each(v.begin(), v.end(), [] (auto &i) { cout << " " << i; }); cout << endl ;
  for_each(v.rbegin(), v.rend(), [] (auto &i) { cout << " " << i; }); cout << endl ;
  for_each(v.cbegin(), v.cend(), [] (auto &i) { cout << " " << i; }); cout << endl;
  for_each(v.crbegin(), v.crend(), [] (auto &i) { cout << " " << i; }); cout << endl;
  cout << "\nFirst element: " << *v.begin() << " | " << *begin(v) ;
  cout << "\nEnd element: " << *(v.end()-1) << " | " << *(end(v)-1);
  cout << "\nEnd element: " << *v.rbegin() ;
  cout << "\nFirst element: " << *v.rend() ;
  return 0;
}
