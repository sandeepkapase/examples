// [[file:~/github/prep/cpp/Questions.org::c++ assert_example1.][c++ assert_example1.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






   using namespace std;
//# define NDEBUG // This will disable assertion
# include <assert.h>

int main()
{
    int x = 7;
    assert (x==5);
    return 0;
}
// c++ assert_example1. ends here
