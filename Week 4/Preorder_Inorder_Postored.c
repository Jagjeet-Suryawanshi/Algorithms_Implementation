//Binary tree implementation of Preorder, Inorder and Postorder

#include <stdio.h>
#include <stdlib.h>
#define COUNT 10;

typedef struct node{

    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p = NULL;
    int x = 0;

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

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void printPostorder(struct node *node) //Postorder
{
    if (node == NULL)
        return;

    printPostorder(node->left);

    printPostorder(node->right);

    printf("%d ", node->data);
}

void printInorder(struct node *node) //Inorder
{
    if (node == NULL)
        return;

    printInorder(node->left);

    printf("%d ", node->data);

    printInorder(node->right);
}

void printPreorder(struct node *node) //Preorder
{
    if (node == NULL)
        return;

    printf("%d ", node->data);

    printPreorder(node->left);

    printPreorder(node->right);
}

int main(){

    node *root = NULL;
    root = create();

    printf("\nThe preorder traversal of binary tree is:\n");
    printPreorder(root);

    printf("\nThe postorder traversal of binary tree is :\n");
    printInorder(root);

    printf("\nThe inorder traversal of binary tree is :\n");
    printPostorder(root);

    return 0;
}
