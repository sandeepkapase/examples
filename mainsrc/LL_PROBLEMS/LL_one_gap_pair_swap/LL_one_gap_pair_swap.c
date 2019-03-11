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

LL * reverse_pair_gap_LL(LL *head) {
  if (head == NULL || head->next == NULL || head->next->next == NULL)
    return head;
  LL *retHead = head->next->next;
  LL *prev = head;
  LL *curr = head->next->next;
  LL *lPnode = NULL; // last pair node
  int ctr = 1;

  while (prev != NULL && curr != NULL) {
    printf("\nCtr: %d", ctr++);

    if (lPnode != NULL) {
      lPnode->next = curr;
      printf("\nprev: %d current: %d lnode: %d\n", prev->data, curr->data, lPnode->data);
    } else {
      printf("\nprev: %d current: %d lnode: %s\n", prev->data, curr->data, "nil");
    }

    SWAP(prev->next, curr->next);
    curr->next->next = prev;
    lPnode = prev;
    prev = prev->next;
    
    printf("Loop LL:");
    print_LL(retHead);

    if (prev == NULL)
      break;
    if (prev->next == NULL)
      break;
    if (prev->next->next == NULL)
      break;
    curr = prev->next->next;
  }
  return retHead;
}

int main()
{
  //int arr[] = {82,93,56,51,88,95};
  int arr[] = {95,88,51,56,93,82};
  
  LL *head = NULL;
  srand(time(NULL));
  for (int i=0; i<6; i++)
    head = insert_at_beg(head, arr[i]);
    //head = insert_at_beg(head, rand()%100);

  print_LL(head);
  head = reverse_pair_gap_LL(head);

  //print_LL(head);
  return 0;
}
