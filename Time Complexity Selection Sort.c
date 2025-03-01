#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int n = 1000;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    printf("Selection Sort took %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}

