//singly linked list colour matching

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *word1, *word2, *word3;
    struct node *link;
};

struct node *Insert(struct node *temp) /*Insert Function*/
{
    struct node *n = NULL, *pos = NULL;
    n = temp;

    if (n == NULL)
    {
        pos = (struct node *)malloc(sizeof(struct node));
        pos->word1 = (char *)malloc(sizeof(char));
        printf("Please Enter the colours in the list :\n");
    
   /*             1. blue red green
                  2. green black yellow
                  3. yellow white orange
                  4. orange grey violet
                  5. violet brown blue
*/
        scanf("%s", pos->word1);

        pos->word2 = (char *)malloc(sizeof(char));
        scanf("%s", pos->word2);

        pos->word3 = (char *)malloc(sizeof(char));
        scanf("%s", pos->word3);

        pos->link = NULL;
        temp = pos;
        return temp;
    }

    while (n->link != NULL)
    {
        n = n->link;
    }

    pos = (struct node *)malloc(sizeof(struct node));
    pos->word1 = (char *)malloc(sizeof(char));
    scanf("%s", pos->word1);

    pos->word2 = (char *)malloc(sizeof(char));
    scanf("%s", pos->word2);

    pos->word3 = (char *)malloc(sizeof(char));
    scanf("%s", pos->word3);

    pos->link = NULL;
    n->link = pos;
    return temp;
}

int check(struct node *temp){  /*checking string Function*/

    struct node *n;

    n = temp;

    while (n != NULL)
    {
        if (n->link != NULL)
        {
            if (strcmp(n->word3, n->link->word1) != 0)
            {
                return 0;
            }

            n = n->link;
        }

        else
        {
            break;
        }
    }

    if (strcmp(n->word3, temp->word1) != 0)
    {
        printf("Entered here_1\n");
        return 0;
    }

    else
        return 1;
}

void Disp_secondstring(struct node *temp) /*Display only second string*/
{
    struct node *n;

    n = temp;

    printf("\nAll rows second string is \n");
    while (n != NULL)
    {
        printf("\t%s", n->word2);
        n = n->link;
        printf("\n");
    }
}

void Disp_Firststrings(struct node *temp){ /*Display First string*/

    struct node *s;
    s = temp;

    printf("\nFirst set after replacement\n");
    while (s != NULL)
    {
        printf("%s", s->word1);
        s = s->link;
        printf("\n");
    }
}

void display(struct node *temp) /*Display all elements*/
{
    struct node *n;
    int index = 1;

    n = temp;
    while (n != NULL)
    {
        printf("%d.%s\t%s\t%s\n", index, n->word1, n->word2, n->word3);
        n = n->link;
        index += 1;
    }
}
struct node *Replace_firstlast(struct node *temp){ /*Exchange_Function*/

    struct node *n, *temp_pos;
    char *cr;

    n = temp;
    temp_pos = temp;

    while (n->link != NULL)
    {
        n = n->link;
    }

    cr = (char *)malloc(sizeof(char));
    strcpy(cr, temp_pos->word1);
    strcpy(temp_pos->word1, "color");
    strcpy(n->word1, "color");

    return n;
}

void main() /*Main function*/
{
    struct node *temp = NULL, *last = NULL;
    int i = 0, valid = 0;
    temp = NULL;

    for (i = 0; i < 5; i++)
        temp = Insert(temp);

    valid = check(temp); //checking strings

    if (valid == 1)
        printf("\n");
    else
    {
        printf("\nEntered data is not in correct order.\n");
        return;
    }

    display(temp);
    Disp_secondstring(temp);

    int ch;
    printf("\n------------------------------------------\n");
    printf("\nEnter 1. Replace String\n");
    printf("Enter 2. quit ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:

        last = Replace_firstlast(temp);
        printf("\nThe list after replacement is\n");
        display(temp);

        if (strcmp(last->word3, temp->word1) != 0)
            printf("\nString not matching\n");
        Disp_Firststrings(temp);
        break;
    case 2:

        exit(0);
        break;

    default:
        printf("Invalid input");
        break;
    }
}
