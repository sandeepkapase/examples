#include <stdlib.h>
#include <ll_helper/ll_helper.h>

LL *insert_at_beg(LL *head, int data) {
  LL *node = (LL *)malloc(sizeof(LL));
  if (node == NULL)
    return NULL;

  node->data = data;
  node->next = head;
  return node;
}

void print_LL(LL *node) {
  printf("\nLL Data:\n");
  while (node != NULL) {
    printf("%d\t", node->data);
    node = node->next;
  }
  printf("\n");
}

