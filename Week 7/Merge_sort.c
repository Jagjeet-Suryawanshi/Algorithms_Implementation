
/*Implementation of Merge sort*/

#include <stdio.h>
#include <stdlib.h>

void merge_array(int arr[], int m1, int j1, int m2, int j2);
void mergesort(int arr[], int i, int j)
{
    int mid;
    if (i < j)
    {
        mid = (i + j) / 2;
        mergesort(arr, i, mid);
        mergesort(arr, mid + 1, j);
        merge_array(arr, i, mid, mid + 1, j);
    }
}
void merge_array(int arr[], int m1, int j1, int m2, int j2)
{
    int temp[50];
    int i, j, k;
    i = m1;
    j = m2;
    k = 0;
    while (i <= j1 && j <= j2)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= j1)
        temp[k++] = arr[i++];
    while (j <= j2)
        temp[k++] = arr[j++];
    for (i = m1, j = 0; i <= j2; i++, j++)
        arr[i] = temp[j];
}

int main()
{
    int arr[40], n, i;
    printf("Enter the number  of elements want to sort:");
    scanf("%d", &n);
    printf("Enter the elements to the array:");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergesort(arr, 0, n - 1);
    printf("\nSorted array is :");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
