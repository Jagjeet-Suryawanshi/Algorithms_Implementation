//AVL Tree implementation Preorder and Inorder

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
    int height;
} node;

node *insert(node *, int);   /*Function Prototypes*/
node *Delete(node *, int);
void preorder(node *);
void inorder(node *);
int height(node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int AVL(node *);

int main()
{
    node *root = NULL;
    int x = 0, n = 0, i = 0, op = 0;
    do
    {
        printf("\n1)Create: ");
        printf("\n2)Delete: ");
        printf("\n3)Preorder & inorder: ");
        printf("\n4)Quit:");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &op);

        switch (op){

        case 1:

            printf("\nEnter no. of elements: ");
            scanf("%d", &n);
            printf("\nEnter tree data: ");
            root = NULL;
            for (i = 0; i < n; i++)
            {
                scanf("%d", &x);
                root = insert(root, x);
            }
            break;

        case 2:
            printf("\nEnter a data:");
            scanf("%d", &x);
            root = Delete(root, x);
            break;

        case 3:
            printf("\nPreorder sequence:\n");
            preorder(root);
            printf("\n\nInorder sequence:\n");
            inorder(root);
            printf("\n");
            break;
        }
    } while (op != 5);
    return 0;
}

node *insert(node *T, int x) /*Insertion*/
{
    if (T == NULL)
    {
        T = (node *)malloc(sizeof(node));
        T->data = x;
        T->left = NULL;
        T->right = NULL;
    }
    else if (x > T->data) // insert in right subtree
    {
        T->right = insert(T->right, x);
        if (AVL(T) == -2)
            if (x > T->right->data)
                T = RR(T);
            else
                T = RL(T);
    }
    else if (x < T->data)
    {
        T->left = insert(T->left, x);
        if (AVL(T) == 2)
            if (x < T->left->data)
                T = LL(T);
            else
                T = LR(T);
    }
    T->height = height(T);
    return (T);
}

node *Delete(node *T, int x) /*Deletion*/
{
    node *p;
    if (T == NULL)
    {
        return NULL;
    }
    else if (x > T->data)
    {
        T->right = Delete(T->right, x);
        if (AVL(T) == 2)
            if (AVL(T->left) >= 0)
                T = LL(T);
            else
                T = LR(T);
    }
    else if (x < T->data)
    {
        T->left = Delete(T->left, x);
        if (AVL(T) == -2) 
            if (AVL(T->right) <= 0)
                T = RR(T);
            else
                T = RL(T);
    }
    else
    {
        if (T->right != NULL)
        {
            p = T->right;
            while (p->left != NULL)
                p = p->left;
            T->data = p->data;
            T->right = Delete(T->right, p->data);
            if (AVL(T) == 2)
                if (AVL(T->left) >= 0)
                    T = LL(T);
                else
                    T = LR(T);
        }
        else
            return (T->left);
    }
    T->height = height(T);
    return (T);
}

int height(node *T){

    int lh, rh;
    if (T == NULL)
        return (0);
    if (T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->height;
    if (T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->height;
    if (lh > rh)
        return (lh);
    return (rh);
}

node *rotateright(node *x){      

    node *y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = height(x);
    y->height = height(y);
    return (y);
}

node *rotateleft(node *x){       

    node *y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = height(x);
    y->height = height(y);
    return (y);
}

node *RR(node *T)                   /*Rotations*/
{
    T = rotateleft(T);
    return (T);
}

node *LL(node *T)
{
    T = rotateright(T);
    return (T);
}

node *LR(node *T)
{
    T->left = rotateleft(T->left);
    T = rotateright(T);
    return (T);
}

node *RL(node *T)
{
    T->right = rotateright(T->right);
    T = rotateleft(T);
    return (T);
}

int AVL(node *T)
{
    int lh, rh;
    if (T == NULL)
        return (0);

    if (T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->height;

    if (T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->height;

    return (lh - rh);
}

void preorder(node *T) /*Preorder*/
{
    if (T != NULL)
    {
        printf("%d ", T->data, AVL(T));
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(node *T) /*Inorder*/
{
    if (T != NULL)
    {
        inorder(T->left);
        printf("%d ", T->data, AVL(T));
        inorder(T->right);
    }
}
