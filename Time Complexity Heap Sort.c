#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and heapify
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);  // Move current root to end
        heapify(arr, i, 0);  // Heapify reduced heap
    }
}

int main() {
    int n = 1000;  // Change for different input sizes
    int arr[n];

    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;  // Generate random numbers

    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();

    printf("Heap Sort took %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}
