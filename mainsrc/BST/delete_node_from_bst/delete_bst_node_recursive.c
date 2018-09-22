#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>

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

int main()
{
    Tree * root;
    int arr[1000], data;
    fillSequentialArray(arr,1000);
    srand(time(NULL));
    root = sortedArrayToBST(arr+(rand()%100), 0, (pow(2,4)-2));

#ifdef LIB_ASCII_BST
    print_ascii_tree(root);
#else
    printInorder(root);
#endif
    while(root != NULL) {
        printf("\nEnter node to delete: ");
        scanf("%d", &data);
        root = deleteNode(root, data);
#ifdef LIB_ASCII_BST
        print_ascii_tree(root);
#else
    printInorder(root);
#endif
    }
    return 0;
}
