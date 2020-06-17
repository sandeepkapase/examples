#include <stdio.h>
#include <unistd.h>
#include <pthread.h>






#include <string.h>
#include <ctype.h>
int main(int argc, char*argv[]) {
  char line[] = "This is next Level and Radar will catch it.";
  char *tok = strtok(line, " ");
  while(tok != NULL) {
    int len = strlen(tok);
    int found=1;
    for (int i=0, j=len-1; i < j ; i++,j--)
      if (toupper(tok[i]) != toupper(tok[j])) { found=0; break; }
    if (found) printf("\nPalindrome found: %s", tok);
    tok = strtok(NULL, " ");
  }
  return 0;
}
