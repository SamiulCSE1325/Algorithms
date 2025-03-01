#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 1000;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();

    printf("Insertion Sort took %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}

