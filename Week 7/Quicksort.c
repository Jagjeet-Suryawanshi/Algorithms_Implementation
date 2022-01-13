/*Implementation of quicksort*/

#include <stdio.h>
#include <time.h>

void quick_sort(int[], int, int);
int partition(int[], int, int);

int main(){

    int ar[50] = {0}, n = 0, i = 0;
    clock_t t;

    printf("Enter Total number of elements want to sort : ");
    scanf("%d", &n);
    printf("\nEnter array elements: ");

    for (i = 0; i < n; i++)
        scanf("%d", &ar[i]);

    t = clock();
    quick_sort(ar, 0, n - 1);
    t = clock() - t;

    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\nquick_sort() took %f seconds to execute \n", time_taken);
    printf("\nArray after sorting: ");

    for (i = 0; i < n; i++)
        printf("%d ", ar[i]);
    return 0;
}

void quick_sort(int ar[], int l, int u){       /*Quick_sort function*/

    int mid = 0;
    if (l < u)
    {
        mid = partition(ar, l, u);
        quick_sort(ar, l, mid - 1);
        quick_sort(ar, mid + 1, u);
    }
}

int partition(int ar[], int l, int u){

    int v=0, i=0, j=0, temp=0;
    v = ar[l];
    i = l;
    j = u + 1;
    do
    {
        do
            i++;
        while (ar[i] < v && i <= u);
        do
            j--;
        while (v < ar[j]);
        if (i < j)
        {
            temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
        }
    } while (i < j);
    ar[l] = ar[j];
    ar[j] = v;
    return (j);
}
