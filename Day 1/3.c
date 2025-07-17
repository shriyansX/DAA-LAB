#include <stdio.h>

#define MAX 100

int main() {
    FILE *file;
    int arr[MAX], freq[MAX] = {0};
    int n, i, j;

    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    file = fopen("input1.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    printf("The content of the array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    int duplicateCount = 0;
    for (i = 0; i < n; i++) {
        if (freq[i] == 0) {
            int count = 1;
            for (j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = -1;  
                }
            }
            freq[i] = count;
            if (count > 1) {
                duplicateCount++;
            }
        }
    }

    printf("Total number of duplicate values = %d\n", duplicateCount);

    
    int maxFreq = 0, mostRepeating;
    for (i = 0; i < n; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostRepeating = arr[i];
        }
    }

    printf("The most repeating element in the array = %d\n", mostRepeating);

    return 0;
}
