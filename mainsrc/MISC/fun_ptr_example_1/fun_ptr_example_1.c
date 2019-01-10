#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<fun_ptr_example_1.h>

/* Example for linker error in case of duplicate symbol.
   Defined function 'dupFunction' in two compilation unit
*/

int main()
{
  int x=5,y=7;
  printf("\nAddtion of %d and %d is %d", x, y, add(x,y));
  printf("\nMultiplication of %d and %d is %d",x, y, multiply(x,y));
  // For function 'dupFunction' we should get linker error (multiple definition of dupFunction)
  // 'dupFunction' is added to both compilation units i.e 'lib_a.c' and 'lib_b.c'
  printf("\nThis should lead to linker error %d", dupFunction());
  return 0;
}
