#include <stdio.h>

typedef struct {
    int item_id;
    float item_profit;
    float item_weight;
    float ratio;
} ITEM;

// Function to heapify
void heapify(ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].ratio > arr[largest].ratio)
        largest = left;
    if (right < n && arr[right].ratio > arr[largest].ratio)
        largest = right;

    if (largest != i) {
        ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Heap sort by ratio
void heapSort(ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].ratio = items[i].item_profit / items[i].item_weight;
    }

    int capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort using heap sort
    heapSort(items, n);

    float totalProfit = 0.0;
    float taken[n];
    for (int i = 0; i < n; i++) taken[i] = 0.0;

    int remaining = capacity;
    for (int i = 0; i < n; i++) {
        if (items[i].item_weight <= remaining) {
            taken[i] = 1.0;
            totalProfit += items[i].item_profit;
            remaining -= items[i].item_weight;
        } else {
            taken[i] = (float)remaining / items[i].item_weight;
            totalProfit += taken[i] * items[i].item_profit;
            break;
        }
    }

    printf("\nItem No profit Weight Amount to be taken\n");
    for (int i = 0; i < n; i++) {
        printf("%d %.6f %.6f %.6f\n", 
               items[i].item_id, 
               items[i].item_profit, 
               items[i].item_weight, 
               taken[i]);
    }

    printf("Maximum profit: %.6f\n", totalProfit);

    return 0;
}
