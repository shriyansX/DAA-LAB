#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[SIZE];

    srand(time(NULL));

    printf("Original Array:\n");
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, SIZE);

    printf("\n\nSorted Array:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
