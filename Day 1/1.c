#include <stdio.h>
#include <limits.h>

int main() {
    FILE *file;
    int n, i;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d", &n);
    if (n < 2) {
        printf("Need at least 2 elements.\n");
        return 1;
    }

    int arr[n];
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    int smallest = INT_MAX, second_smallest = INT_MAX;
    int largest = INT_MIN, second_largest = INT_MIN;

    for (i = 0; i < n; i++) {
      
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }

        
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    if (second_smallest == INT_MAX || second_largest == INT_MIN) {
        printf("Second smallest or second largest element not found (possibly due to duplicates).\n");
    } else {
        printf("Second Smallest Element: %d\n", second_smallest);
        printf("Second Largest Element: %d\n", second_largest);
    }

    return 0;
}
