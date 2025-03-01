#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n = 1000; // Change for different sizes
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();

    printf("Bubble Sort took %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}

