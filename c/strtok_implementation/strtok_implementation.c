#include <stdio.h>
#include <string.h>

int isDelm(char c, const char *del) {
  while(*del != '\0') {
    if (*del == c)
      return 1;
    del++;
  }
  return 0;
}

char * my_strtok(char *srcBeg, const char *del) {
  static int curIndex = 0;
  static char * src = NULL;
  char * retPtr = NULL;

  if (srcBeg != NULL) {
    curIndex = 0;
    src = srcBeg;
  }

  retPtr = src + curIndex;
  while(src[curIndex] != '\0') {
    if (isDelm(src[curIndex], del))
      break;
    curIndex++;
  }

  while (src[curIndex] != '\0' &&  isDelm(src[curIndex], del)) {
    src[curIndex] = '\0';
    curIndex++;
  }

  return src+curIndex == retPtr ?  NULL :  retPtr;
}

int main() {
  char str[80];
  const char *s = "-i";
  char *token;

  sprintf(str, "%s", "This-is-basic-strtok-example");
  printf("\nString is: %s\n", str);
  token = strtok(str, s);
  while (token != NULL) {
    printf("TOKEN: %s\n", token);
    token = strtok(NULL, s);
  }

  sprintf(str, "%s", "This-is-basic-strtok-example");
  printf("\nString is: %s\n", str);
  token = my_strtok(str, s);
  while (token != NULL) {
    printf("TEKEN: %s\n", token);
    token = my_strtok(NULL, s);
  }

  printf("\nEnd of program\n");

  return (0);
}
