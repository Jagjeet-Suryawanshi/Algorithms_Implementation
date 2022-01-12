
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define COUNT 10;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    printf("Enter left child of %d:\n", x);
    p->left = create();
    printf("Enter right child of %d:\n", x);
    p->right = create();
    return p;
}
//given data and NULL left and right pointers. */
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct node *node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    printf("%d ", node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    printf("%d ", node->data);

    /* then recur on left subtree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

int main()
{
    node *root;
    root = create();
    //printf("\nHeight of binary tree : %d" , height_of_binary_tree(root));
    printf("\nThe preorder traversal of binary tree is:\n");
    printPreorder(root);
    printf("\nThe postorder traversal of binary tree is :\n");
    printInorder(root);
    printf("\nThe inorder traversal of binary tree is :\n");
    printPostorder(root);
    //printf("Binary tree is");
    //print2D(root);
    return 0;
}