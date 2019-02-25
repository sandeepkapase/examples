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
int checkBST(Tree *node);
int checkBST_meta(Tree *node, int *currentMax);
int checkBST_FIX1(Tree *node, int *currentMax);
int checkBST_Wrap(Tree *node);
struct Tree * newNode(int data);
void printInorder(struct Tree* node);
#endif
