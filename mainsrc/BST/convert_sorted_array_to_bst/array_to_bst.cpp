#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<limits.h>

#include <libasciibst/libasciibst.h>
#include <bsthelper/bstHelper.h>
#include <mischelper/miscHelper.h>
//#ifndef BST_HELPER
//#error my_function not implemented
//#endif


Tree * newNode(int data);

Tree * insertNode(Tree * node, int data)
{
    if (node == NULL) return newNode(data);

    if (data < node->data) node->left  = insertNode(node->left, data);
    else node->right = insertNode(node->right, data);
    return node;
}

Tree * inorderSuccessor(Tree *node) {
    if (node == NULL) return NULL;
    if (node->left != NULL) return inorderSuccessor(node->left);
    return node;
}

Tree * deleteNode(Tree * node, int data) {
    if (node == NULL)
        return NULL;

    if (data < node->data) node->left = deleteNode(node->left, data);
    else if (data > node->data) node->right = deleteNode(node->right, data);
    else {
        // no child
        if (node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL;
        } else if (node->left != NULL && node->right != NULL) {
            Tree *tmp = inorderSuccessor(node->right);
            node->data = tmp->data;
            node->right = deleteNode(node->right, tmp->data);
        } else { // one child
            Tree *tmp = node;
            node = (node->left == NULL) ? node->right: node->left;
            free(tmp);
        }
    }
    return node;
}

struct Tree * arrayToBST_meta(int *arr, int beg, int end) {
  struct Tree *node = (struct Tree *)malloc(sizeof(struct Tree));
  int mid = (beg+end)/2;

  if (node == NULL)
    return NULL;

  node->data = arr[mid];
  node->left = node->right = NULL;
  //printf("\nAdded %d start %d end %d\n", arr[mid], beg, end);
  //printf("\nstart end %d %d\n", beg,end);
  //sleep(1);
  if (beg == end) {
    return node;
  } else {
    if (beg <= mid-1)
      node->left = arrayToBST_meta(arr, beg, mid-1);
    if (mid+1 <= end)
      node->right = arrayToBST_meta(arr, mid+1, end);
    return node;
  }
}


struct Tree * arrayToBST(int *arr, int size) {
  return arrayToBST_meta(arr, 0, size-1);
}

int main()
{
  Tree * root;
  int arr[1000];
  //int arr[] = {10,20,40,30,45,50,55};
  //int arr[] = {10,20,25,30,45,50,55}; // replace 40 by 25 to correct tree
  fillSequentialArray(arr,1000);
  srand(time(NULL));
  //root = sortedArrayToBST(arr+(rand()%100), 0, (pow(2,5)-2));
  //root = arrayToBST(arr+(rand()%100), (pow(2,4)-2));
  //int numNodes =  (pow(2,4)-2)+1;
  //printf("\nNodes: %d\n", numNodes);
  root = arrayToBST(arr+(rand()%100), 9);
  //root = arrayToBST(arr, (sizeof(arr)/sizeof(int))-1);
  print_ascii_tree(root);
  return 0;
  //  printf("\n%d", checkBST(root));
  if (checkBST(root) == -1)
    printf("\nTree is not BST\n");
  else
    printf("\nTree is BST\n");
  
  /*  if (checkBST_Wrap(root) != 0)
      printf("\nTree is not BST\n");
      else
      printf("\nTree is BST\n");*/
  return 0;
}
