/* Program to split a circular linked list into two halves */

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

/*Split Function */
void splitList(struct node *head, struct node **head1_ref, struct node **head2_ref)
{
  struct node *even_ptr = head;
  struct node *odd_ptr = head;

  if (head == NULL)
    return;

  /* If there are odd nodes in the circular list then  fast_ptr->link becomes head */
  while (odd_ptr->link != head && odd_ptr->link->link != head)
  {
    odd_ptr = odd_ptr->link->link;
    even_ptr = even_ptr->link;
  }

  /* If there are even elements in list then */
  if (odd_ptr->link->link == head)
    odd_ptr = odd_ptr->link;

  *head1_ref = head;

  /* Set the head pointer of second half */
  if (head->link != head)
    *head2_ref = even_ptr->link;

  odd_ptr->link = even_ptr->link; /*S_half circular*/

  even_ptr->link = head; /*F_half circular*/
}

void push(struct node **head_ref, int data)
{ /*Insert function*/
  struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
  struct node *temp = *head_ref;
  ptr1->data = data;
  ptr1->link = *head_ref;

  /* If linked list is not NULL then set the link of  
    last node */
  if (*head_ref != NULL)
  {
    while (temp->link != *head_ref)
      temp = temp->link;
    temp->link = ptr1;
  }
  else
    ptr1->link = ptr1; /*For the first node */

  *head_ref = ptr1;
}

/* Function to print nodes in a given Circular linked list */
void printList(struct node *head)
{
  struct node *temp = head;
  if (head != NULL)
  {
    printf("");
    do
    {
      printf(" %d", temp->data);
      temp = temp->link;
    } while (temp != head);
  }
}

int main()
{
  int list_size, i;

  /* Initialize lists as empty */
  struct node *head = NULL;
  struct node *head1 = NULL;
  struct node *head2 = NULL;

  /* Created linked list will be 30->11->7->20 */
  push(&head, 30);
  push(&head, 11);
  push(&head, 7);
  push(&head, 20);

  printf("Original Circular Linked List: ");
  printList(head);

  /* Split the list */
  splitList(head, &head1, &head2);

  printf("\nSplit Circular Linked List :");
  printf("\n");
  printList(head1);

  //second list
  printf("\n");
  printList(head2);

  getchar();
  return 0;
}
