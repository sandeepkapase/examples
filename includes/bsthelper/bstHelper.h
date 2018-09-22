#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef BST_HELPER
#define  BST_HELPER

typedef  struct  Tree
{
  struct Tree * left, * right;
  int data;
} Tree;

Tree * sortedArrayToBST(int [], int start, int end);
struct Tree * newNode(int data);
void printInorder(struct Tree* node);
#endif
