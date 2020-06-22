// [[file:~/github/prep/cpp/AnalyzeCode.org::c++ analyze_program_example2 example.][c++ analyze_program_example2 example.]]
#include <typeinfo>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <stdexcept>






  using namespace std;
  int main(int argc, char*argv[]) {
    char name[1024];
    size_t sz = sizeof(name);
    sz=0; --sz;
      cout << sz << endl;
exit(0);
    while(--sz >=0 ) {
      cout << sz << endl;
      //cout << name[sz];
    }
    return 0;
  }
// c++ analyze_program_example2 example. ends here
