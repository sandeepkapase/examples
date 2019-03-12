#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define MAX_STR_LEN 100

typedef struct fam {
  int a;
  char str[];
}fam;

void printfam(fam *f) {
  printf("\nfam->a = %d", f->a);
  printf("\nfam->str = %s", f->str);
}

int main() {
  fam *f = malloc(sizeof(fam)+sizeof(char)*MAX_STR_LEN);
  f->a = 111;
  sprintf(f->str, "%s", "Very simple Strin");
  printfam(f);
  return 0;
}
