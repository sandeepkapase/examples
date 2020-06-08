#include<stdio.h>
#include <stdint.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<limits.h>

#include <ll_helper/ll_helper.h>
#define SWAP(x,y) x=(LL *)((uintptr_t)x^(uintptr_t)y), y=(LL *)((uintptr_t)x^(uintptr_t)y), x=(LL *)((uintptr_t)x^(uintptr_t)y)
//#ifndef BST_HELPER
//#error my_function not implemented
//#endif

LL * reverse_LL(LL *head) {
  LL * prevNode = NULL;
  while (head != NULL) {
    SWAP(prevNode, head->next);
    SWAP(prevNode, head);
  }
  return prevNode;
}

int main()
{
  LL *head = NULL;
  srand(time(NULL));
  for (int i=0; i<10; i++)
    head = insert_at_beg(head, rand()%100);

  print_LL(head);
  head = reverse_LL(head);

  print_LL(head);
  return 0;
}
