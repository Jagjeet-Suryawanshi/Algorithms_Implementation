#include <stdio.h>
#include <stdlib.h>
#define v 4 /*Change vertex Number*/

void BFS(int Ar[v][v], int visited[], int start){      /*BFS*/

    int queue[v], rear = -1, i=0, j=0;
    int front = -1;
    for (i = 0; i < v; i++)
    visited[i] = 0;
    queue[++rear] = start;
    front++;
    visited[start] = 1;
    printf("BFS :- ");

    while (rear >= front){

        start = queue[front++];
        printf("%c ", start + 65); /*Number to Alphabet*/
        for (i = 0; i < v; i++)
        {
            if (Ar[start][i] && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int Ar[v][v], int visited[], int start){        /*DFS*/

    int max = v;
    int stack[v] = {0};
    int top = -1, i = 0, j = 0;

    for (i = 0; i < v; i++)
          visited[i] = 0;
    stack[++top] = start;
    visited[start] = 1;
    printf("\nDFS :- ");

    while (top != -1)
    {
        start = stack[top--];
        printf("%c ", start + 65);
        for (i = 0; i < v; i++)
        {
            if (Ar[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}
int main(){

    printf("\nIf user wants to increase or decrease vertex count should enter statically \n");
    printf("No. of vertices are %d\n", v);
    int ch = 0;
    int i = 0, j = 0, start = 0;

    int Ar[v][v] = {0};
    int visited[v] = {0};

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            printf("\nEnter the edge weight from vertex %d to %d ", i, j);
            scanf("%d", &Ar[i][j]);
        }
    }

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            printf("%d  ", Ar[i][j]);
        }
        printf("\n");
    }

    printf("\n1. For BFS:\n");
    printf("2. For DFS:\n");
    printf("3. For both\n");

    printf("\nEnter your choice ");
    scanf("%d", &ch);

    if (ch != 1 && ch != 2 && ch != 3){

        printf("Invalid input");
        printf("\n1. For BFS:\n");
        printf("2. For DFS:\n");
        printf("3. For both\n");

        printf("\nEnter your choice ");
        scanf("%d", &ch);
    }
    switch (ch){

    case 1:

        printf("Enter the starting node ");
        scanf("%d", &start);
        BFS(Ar, visited, start);
        break;

    case 2:

        printf("Enter the starting node ");
        scanf("%d", &start);
        DFS(Ar, visited, start);
        break;

    case 3:

        printf("Enter the starting node ");
        scanf("%d", &start);
        BFS(Ar, visited, start);
        DFS(Ar, visited, start);
        break;

    default:

        exit(0);
        break;
    }
    return 0;
}
