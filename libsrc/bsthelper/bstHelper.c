#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bsthelper/bstHelper.h>


void printInorder(struct Tree* node)
{
  if (node == NULL)
     return;

  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}


struct Tree * newNode(int data)
{
  struct Tree * node = (struct Tree*)malloc(sizeof(struct Tree));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

Tree * sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL; // same as (start+end)/2, avoids overflow.
    int mid = start + (end - start) / 2;
    Tree *node = newNode(arr[mid]);
    node->left = sortedArrayToBST(arr, start, mid-1);
    node->right = sortedArrayToBST(arr, mid+1, end);
    return node;
}
  
