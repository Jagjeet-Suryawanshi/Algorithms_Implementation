#include <stdio.h>
int digit, i;

void radix_Sort(int arr[10], int n, int digits)      /*Radix sort*/
{

    int i;

    int R_ar[n];

    while (digits > 0)
    {

        int index_ar[10] = {0};

        for (i = 0; i < n; i++)

            index_ar[(arr[i] / digits) % 10]++;

        for (i = 0; i < 10; i++)

            index_ar[i] += index_ar[i - 1];

        for (i = n - 1; i >= 0; i--)
        {

            R_ar[index_ar[(arr[i] / digits) % 10] - 1] = arr[i];

            index_ar[(arr[i] / digits) % 10]--;
        }

        for (i = 0; i < n; i++)
            arr[i] = R_ar[i];

        digits *= 10;
    }

        printf("\nAfter sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n, i, digits, x, largest;
    int ar[n];
    printf("\nEnter the number of elements want to sort : ");
    scanf("%d", &n);

    printf("\nEnter the number in the array ");
    for (i = 0; i < n; i++)
        scanf("%d", &ar[i]);

    largest = ar[0];
    for (i = 1; i < n; i++)         /*Maximum*/
    {
        if (ar[i] > largest)
        {
            largest = ar[i];
        }
    }

    printf("Largest = %d", largest);

    if (largest > 9 && largest < 100)
    {
        printf("\nTwo digit in largest number\n");
        digits = 2;
    }
    if (largest > 99 && largest < 999)
    {
        printf("\nThree digits in largest number\n");
        digits = 3;
    }
    if (largest < 10)
    {
        printf("\nOne digit in largest number\n");
        digits = 1;
    }
    if (largest > 999)
    {
        printf("\nFour digits in largest number\n");
        digits = 4;
    }

    radix_Sort(ar, n, digits);

    return 0;
}
