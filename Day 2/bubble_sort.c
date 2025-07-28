#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10  // You can change this to any size you want

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE];

    // Seed random number generator
    srand(time(NULL));

    // Generate random numbers
    printf("Original Array:\n");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;  // Random numbers between 0 and 99
        printf("%d ", arr[i]);
    }

    // Sort the array using bubble sort
    bubbleSort(arr, SIZE);

    // Print the sorted array
    printf("\n\nSorted Array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
