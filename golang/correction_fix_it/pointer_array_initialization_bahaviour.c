#include <stdio.h>

int main(void) {
  char * ptr = "Xrodata section data";
  char myarr[] = " ata from stack allocation";
  myarr[0] = 'D'; // SUCCESS
  printf("\n%s\n", myarr);
  ptr[0] = '.'; // Segfault tried to modify .rodata/text segment
  printf("\n%s\n", ptr);
  return 0;
}
