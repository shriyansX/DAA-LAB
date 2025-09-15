#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char alphabet;
    int freq;
    struct node *left, *right;
} SYMBOL;

// Function to create a new node
SYMBOL* newNode(char alphabet, int freq) {
    SYMBOL* temp = (SYMBOL*)malloc(sizeof(SYMBOL));
    temp->alphabet = alphabet;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Swap two nodes
void swap(SYMBOL** a, SYMBOL** b) {
    SYMBOL* t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(SYMBOL* arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left]->freq < arr[smallest]->freq)
        smallest = left;
    if (right < n && arr[right]->freq < arr[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Extract min
SYMBOL* extractMin(SYMBOL* arr[], int* n) {
    SYMBOL* temp = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
    return temp;
}

// Insert node
void insertNode(SYMBOL* arr[], int* n, SYMBOL* node) {
    arr[*n] = node;
    int i = *n;
    (*n)++;

    while (i && arr[(i - 1) / 2]->freq > arr[i]->freq) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// In-order traversal
void inorder(SYMBOL* root) {
    if (root != NULL) {
        inorder(root->left);
        if (root->alphabet != '$')  // only print valid chars
            printf("%c ", root->alphabet);
        inorder(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    char alphabets[n];
    int freq[n];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++)
        scanf(" %c", &alphabets[i]);

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    SYMBOL* heap[100];
    int heapSize = 0;

    for (int i = 0; i < n; i++)
        insertNode(heap, &heapSize, newNode(alphabets[i], freq[i]));

    while (heapSize > 1) {
        SYMBOL* left = extractMin(heap, &heapSize);
        SYMBOL* right = extractMin(heap, &heapSize);

        SYMBOL* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertNode(heap, &heapSize, top);
    }

    SYMBOL* root = heap[0];
    printf("In-order traversal of the tree (Huffman): ");
    inorder(root);
    printf("\n");

    return 0;
}
