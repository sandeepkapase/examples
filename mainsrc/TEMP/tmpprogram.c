#include <stdio.h>
#include <string.h>
#include <limits.h>

/* int main() { */
/*   char str[80]; */
/*   int x= INT_MAX; */
/*   int y= INT_MAX; */
/*   int z = x+y; */
/*   printf("\nEnd of program %d\n", z); */
/*   printf("\nEnd of program %d\n", z); */

/*   return (0); */
/* } */


int main(void) {
  printf("\nString :\n%s", &"This is my string"[0]);
}
