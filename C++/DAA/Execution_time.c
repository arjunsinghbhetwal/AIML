#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define HALF_SIZE (SIZE / 2)
#define ITERATIONS 100

// --- MERGE SORT IMPLEMENTATION ---
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// --- QUICK SORT IMPLEMENTATION ---
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// --- MAIN BENCHMARKING ENGINE ---
int main() {
    int full_arr[SIZE];
    int first_half[HALF_SIZE];
    int second_half[HALF_SIZE];

    double total_merge_time = 0.0;
    double total_quick_time = 0.0;

    srand(time(0));

    for (int iter = 0; iter < ITERATIONS; iter++) {
        // Step 1: Fill array with random numbers
        for (int i = 0; i < SIZE; i++) {
            full_arr[i] = rand() % 10000;
        }

        // Step 2: Split array into 2 halves
        for (int i = 0; i < HALF_SIZE; i++) {
            first_half[i] = full_arr[i];
            second_half[i] = full_arr[i + HALF_SIZE];
        }

        // Step 3: Measure Merge Sort on First Half
        clock_t start = clock();
        mergeSort(first_half, 0, HALF_SIZE - 1);
        clock_t end = clock();
        total_merge_time += ((double)(end - start)) / CLOCKS_PER_SEC;

        // Step 4: Measure Quick Sort on Second Half
        start = clock();
        quickSort(second_half, 0, HALF_SIZE - 1);
        end = clock();
        total_quick_time += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    // Step 5: Calculate Average Times (in milliseconds)
    double avg_merge = (total_merge_time / ITERATIONS) * 1000.0;
    double avg_quick = (total_quick_time / ITERATIONS) * 1000.0;

    printf("=== Benchmarking Results (%d Runs) ===\n", ITERATIONS);
    printf("Array Size Split: 2x %d elements\n\n", HALF_SIZE);
    printf("Average Merge Sort Time : %.5f ms\n", avg_merge);
    printf("Average Quick Sort Time : %.5f ms\n", avg_quick);

    return 0;
}