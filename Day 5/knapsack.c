#include <stdio.h>

// Structure for an item
struct Item {
    int value;
    int weight;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value/weight ratio (descending order)
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)arr[j].value / arr[j].weight;
            double r2 = (double)arr[j + 1].value / arr[j + 1].weight;
            if (r1 < r2) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to solve Fractional Knapsack
double fractionalKnapsack(int W, struct Item arr[], int n) {
    sortItems(arr, n);

    double finalValue = 0.0; // Maximum value accumulated

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            // If item fits completely
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            // Take fraction of the item
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break; // Knapsack is full
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i].value);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i].weight);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    double result = fractionalKnapsack(W, arr, n);
    printf("Maximum value in knapsack = %.2f\n", result);

    return 0;
}
