#include <iostream>
#include <unistd.h>







using namespace std;
#include <iostream>
#include <vector>
int main() {
  vector<int> v = {1,2,3,4};
  vector<int>::iterator  vtr = v.begin();
  for (auto i = v.begin(); i != v.end(); i++) {
    v.pop_back();
    cout << *i << endl;
  }

  return 0;
}
