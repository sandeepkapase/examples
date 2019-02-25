#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <bsthelper/bstHelper.h>



void printInorder(struct Tree* node)
{
  if (node == NULL)
     return;

  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}

// success : return 0
// failure : return -1
// Incorrect implementations:
// input:
//                  3
//             2        5
//           1   4        5

/*int checkBST(struct Tree* node)
{
  if (node != NULL) {
    if (node->left != NULL && node->data < node->left->data) {
      //printf("First case node data %d node left data %d\n", node->data, node->left->data);
      return -1;
    }
    if (node->right != NULL && node->data > node->right->data) {
      //printf("Second case node data %d node right data %d\n", node->data, node->right->data);
      return -1;
    }
    if (checkBST(node->left) == -1 || checkBST(node->right) == -1) {
      //printf("Third case\n");
      return -1;
    }
  }

    return 0;
    } */

int checkBST(struct Tree *root) {
  static int currentMax;
  currentMax = INT_MIN;
  return checkBST_meta(root, &currentMax); 
}

int checkBST_meta(struct Tree *node, int *currentMax) {
  if (node == NULL)
    return 0;

  if (checkBST_meta(node->left, currentMax) == -1)
    return -1;

  if (node->data < *currentMax)
    return -1;
  *currentMax = node->data;

  if (checkBST_meta(node->right, currentMax) == -1)
    return -1;

  return 0;
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
  
