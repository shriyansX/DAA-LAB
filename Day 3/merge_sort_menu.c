#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int comparisons = 0;

// Merge function
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// Merge Sort recursive function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to read data from file
int readFromFile(const char *filename, int arr[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    int n = 0;
    while (fscanf(fp, "%d", &arr[n]) != EOF && n < MAX)
        n++;
    fclose(fp);
    return n;
}

// Function to write data to file
void writeToFile(const char *filename, int arr[], int n) {
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d ", arr[i]);
    fclose(fp);
}

// Display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main program
int main() {
    int option;
    int arr[MAX], n;
    char inFile[20], outFile[20];

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            sprintf(inFile, "inAsce.dat");
            sprintf(outFile, "outMergeAsce.dat");
            break;
        case 2:
            sprintf(inFile, "inDesc.dat");
            sprintf(outFile, "outMergeDesc.dat");
            break;
        case 3:
            sprintf(inFile, "inRand.dat");
            sprintf(outFile, "outMergeRand.dat");
            break;
        default:
            printf("Exiting...\n");
            return 0;
    }

    n = readFromFile(inFile, arr);
    if (n <= 0) {
        printf("No data found in file or file error.\n");
        return 1;
    }

    printf("Before Sorting: ");
    displayArray(arr, n);

    // Start timing
    clock_t start, end;
    start = clock();

    mergeSort(arr, 0, n - 1);

    // End timing
    end = clock();
    double elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1e9; // nanoseconds

    printf("After Sorting: ");
    displayArray(arr, n);

    writeToFile(outFile, arr, n);

    printf("Number of Comparisons: %d\n", comparisons);
    printf("Execution Time: %.0f nanoseconds\n", elapsed);

    return 0;
}
