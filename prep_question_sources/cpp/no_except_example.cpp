// [[file:~/github/prep/cpp/Questions.org::noexcept operator/function example.][noexcept operator/function example.]]
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
//void foo() noexcept     // see the noexcept specifier
void foo() // see the noexcept specifier
{
  throw 42;
}
int main()
{
  /* In this try catch block, if noexcept is NOT set for function foo then compiler does not perform
     any optimzation and add handling for all scanario, expception handler code, stack winding/unwinding etc.
     But, it noexcept is set, compiler does optionmization and does not include any handling related to exception.
     Because of this, it foo throws exception, program get terminated instead of reaching to exception handler. */
  try
    {
      foo();
    }
  catch(...)
    {
      cerr<<"exception caught\n";
    }
  return 0;
}
// noexcept operator/function example. ends here
