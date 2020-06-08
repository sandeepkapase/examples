#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<main.h>

/* Example for linker error in case of duplicate symbol.
   Defined function 'add' in two compilation unit
*/

int main()
{
  // should get multiple defition of 'add' from linker
  // as 'add' is defined in two compilation units lib_a.c and lib_b.c
  printf("\nOperation value: %d", add(10, 2));

  return 0;
}
