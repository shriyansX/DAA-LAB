#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int comparisons = 0;
int best_case_partitions = 0;
int worst_case_partitions = 0;

// Function to swap two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Last element as pivot
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    int pivot_index = i + 1;

    int left_size = pivot_index - low;
    int right_size = high - pivot_index;

    // Partition analysis
    if (left_size == 0 || right_size == 0)
        worst_case_partitions++;
    else if (abs(left_size - right_size) <= 1)
        best_case_partitions++;

    return pivot_index;
}

// QuickSort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
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

    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            sprintf(inFile, "inAsce.dat");
            sprintf(outFile, "outQuickAsce.dat");
            break;
        case 2:
            sprintf(inFile, "inDesc.dat");
            sprintf(outFile, "outQuickDesc.dat");
            break;
        case 3:
            sprintf(inFile, "inRand.dat");
            sprintf(outFile, "outQuickRand.dat");
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

    // Timing
    clock_t start, end;
    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();
    double elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1e9;

    printf("After Sorting: ");
    displayArray(arr, n);

    writeToFile(outFile, arr, n);

    printf("Number of Comparisons: %d\n", comparisons);

    // Determine scenario
    if (worst_case_partitions > best_case_partitions)
        printf("Scenario: Worst-case partitioning\n");
    else if (best_case_partitions > worst_case_partitions)
        printf("Scenario: Best-case partitioning\n");
    else
        printf("Scenario: Mixed-case partitioning\n");

    printf("Execution Time: %.0f nanoseconds\n", elapsed);

    return 0;
}
