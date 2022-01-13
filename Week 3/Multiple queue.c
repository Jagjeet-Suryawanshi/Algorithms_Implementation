// implement efficiently multiple queues in a single array.

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int insq(int queue[MAX], int Qno, int rear[], int limit[], int *ele)
{
      if (rear[Qno] == limit[Qno])
            return (-1);
      else
      {
            rear[Qno]++;
            queue[rear[Qno]] = *ele;
            return (1);
      }
}
int delq(int queue[MAX], int Qno, int front[], int rear[], int *ele)
{
      if (front[Qno] == rear[Qno])
            return (-1);
      else
      {
            front[Qno]++;
            *ele = queue[front[Qno]];
            return (1);
      }
}
int main()
{
      int queue[MAX] = {0}, ele = 0;
      int bott[10] = {0}, limit[10] = {0}, f[10] = {0}, r[10] = {0};
      int i = 0, n = 0, Qno = 0, size = 0; 
      int sl = 0, reply = 0;

      printf("How many queues you want : ");
      scanf("%d", &n);

      size = MAX / n; /* size for each queue*/
      bott[0] = -1;

      for (i = 1; i < n; i++)

            bott[i] = bott[i - 1] + size;

      for (i = 0; i < n; i++)

            limit[i] = bott[i] + size;


      for (i = 0; i < n; i++)

            f[i] = r[i] = bott[i];

      printf("\n 1. Insert element");
      printf("\n 2. Delete element");
      printf("\n 3. Exit \n");
      while (1)
      {
            printf("Enter your selection: ");
            scanf("%d", &sl);

            switch (sl)
            {
            case 1: 

                  printf("\nEnter the queue number (0 to %d) : ", n - 1);
                  scanf("%d", &Qno);

                  printf("Element to be entered in queue number %d : ", Qno);
                  scanf("%d", &ele);
      
                  reply = insq(queue, Qno, r, limit, &ele);
                  if (reply == -1)
                        printf("Queue %d is full \n", Qno);
                  else
                        printf("%d is inserted in queue number %d.\n\n", ele, Qno);
                  break;

            case 2: 

                  printf("\nEnter queue number of which elements to delete (0 to %d) : ", n - 1);
                  scanf("%d", &Qno);

                  reply = delq(queue, Qno, f, r, &ele);
                  if (reply == -1)
                        printf("\nQueue %d is empty. \n", Qno);
                  else
                        printf("%d is deleted from queue number %d \n\n", ele, Qno);
                  break;

            case 3:

                  exit(0);
                  break;
            default:

                  printf("Invalid operation \n");
                  break;
            }
      }
      return 0;
}
