#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






#include <iostream>
#include <stdio.h>

class base {
private:
  const static unsigned int size = 8;
  //void (* funPtrArr [size])(){}; // FIX 2
  void (* funPtrArr [size])();

public:
  // base():funPtrArr({}){} // FIX 1
  // base()=default; // FIX 3
  base() {}

  void print() {
    for(auto i=0; i < base::size; i++) {
      printf("funPtrArr[%d] = %p\n", i, this->funPtrArr[i]);
    }
  }
};

int main() {
  base testObj = {};
  testObj.print();

  return 0;
}
