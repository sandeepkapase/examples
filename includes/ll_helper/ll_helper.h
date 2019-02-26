#include <stdio.h>

typedef struct Linked_List {
  int data;
  struct Linked_List *next;
}LL;


LL *insert_at_beg(LL *head, int data);
void print_LL(LL *node);
