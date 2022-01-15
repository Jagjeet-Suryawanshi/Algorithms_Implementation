/*Implementation of stack using linked list*/

#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *next;
} * start;
int item, n;
void push(int);
void pop();
void exit();
void traverse();

void main()
{
    int choice;
    start = NULL;
    clrscr();
    while (1)
    {
        printf("1  push \n  ");
        printf("2  pop \n");
        printf("3 traverse \n");
        printf("4 exit");
        printf("Enter your choices");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            if (start == NULL)
            {
                printf("\n list created");
            }
            pop();
            break;

        case 3:
            if (start == NULL)
            {
                printf("\n No list created");
                break;
            }
            traverse();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("invalid input");
        }
    }
}
void push(int s)
{
    struct node *q, *t;
    q = (struct node *)malloc(sizeof(struct node));
    q->data = s;
    q->next = NULL;
    if (start = NULL)
    {
        start = q;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = q;
    }
void pop(){

        struct node *q;
        q = start;
        while (q->next->next != NULL)
        {
            q = q->next;
        }
        q->next = NULL;
        peintf("\n data popped");
    }
    
    void traverse()
    {
        struct node *q;
        q = start;
        while (q != NULL)
        {
            printf("\n data  %d", q->data);
            q = q->next;
        }
    }
}
