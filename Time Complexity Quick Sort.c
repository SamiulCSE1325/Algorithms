#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) swap(&arr[++i], &arr[j]);
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 1000;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Quick Sort took %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}

