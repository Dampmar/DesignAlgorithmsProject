#include <stdio.h>
#include <time.h>
#include <limits.h>
#include "SelectionSort.c"
#include "MergeSort.c"
#include "HeapSort.c"

const int size1 = 50000;
const int size2 = 100000;
const int size3 = 150000;
const int size4 = 200000;

static int arr_A[size1];
static int arr_B[size2];
static int arr_C[size3];
static int arr_D[size4];

typedef void (*SortFunction)(int[], int);

void ArrayRandomNumbers();
void check_unsorted(int A[], int n);
double measureSortTime(SortFunction func, int arr[], int n);

int main(void) {
    double exe_time;

    for (int i = 0; i < 3; i++) {
        printf("Generating random numbers.\n");
        ArrayRandomNumbers();
        exe_time = measureSortTime(selection_sort, arr_A, size1);
        printf("Execution Time of Selection Sort (%d): %.6lf\n", size1, exe_time);
        exe_time = measureSortTime(selection_sort, arr_B, size2);
        printf("Execution Time of Selection Sort (%d): %.6lf\n", size2, exe_time);
        exe_time = measureSortTime(selection_sort, arr_C, size3);
        printf("Execution Time of Selection Sort (%d): %.6lf\n", size3, exe_time);
        exe_time = measureSortTime(selection_sort, arr_D, size4);
        printf("Execution Time of Selection Sort (%d): %.6lf\n", size4, exe_time);
    }

    for (int i = 0; i < 3; i++) {
        printf("Generating random numbers.\n");
        ArrayRandomNumbers();
        exe_time = measureSortTime(mergesort, arr_A, size1);
        printf("Execution Time of Merge Sort (%d): %.6lf\n", size1, exe_time);
        exe_time = measureSortTime(mergesort, arr_B, size2);
        printf("Execution Time of Merge Sort (%d): %.6lf\n", size2, exe_time);
        exe_time = measureSortTime(mergesort, arr_C, size3);
        printf("Execution Time of Merge Sort (%d): %.6lf\n", size3, exe_time);
        exe_time = measureSortTime(mergesort, arr_D, size4);
        printf("Execution Time of Merge Sort (%d): %.6lf\n", size4, exe_time);
    }

    for (int i = 0; i < 3; i++) {
        printf("Generating random numbers.\n");
        ArrayRandomNumbers();
        exe_time = measureSortTime(heapsort, arr_A, size1);
        printf("Execution Time of Heap Sort (%d): %.6lf\n", size1, exe_time);
        exe_time = measureSortTime(heapsort, arr_B, size2);
        printf("Execution Time of Heap Sort (%d): %.6lf\n", size2, exe_time);
        exe_time = measureSortTime(heapsort, arr_C, size3);
        printf("Execution Time of Heap Sort (%d): %.6lf\n", size3, exe_time);
        exe_time = measureSortTime(heapsort, arr_D, size4);
        printf("Execution Time of Heap Sort (%d): %.6lf\n", size4, exe_time);
    }

    return 0;
}

void ArrayRandomNumbers() {
    srand(0);
    for (int i = 0; i < size1; i++) {
        arr_A[i] = rand();
    }
    for (int i = 0; i < size2; i++) {
        arr_B[i] = rand();
    }
    for (int i = 0; i < size3; i++) {
        arr_C[i] = rand();
    }
    for (int i = 0; i < size4; i++) {
        arr_D[i] = rand();
    }
}

double measureSortTime(SortFunction func, int arr[], int n){
    clock_t start, end;
    start = clock();
    func(arr, n);
    end = clock();
    check_unsorted(arr, n);
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

void check_unsorted(int A[], int n) {
    for (int i = 1; i < n; i++)
        if (A[i-1] > A[i]) {
            printf("Unsorted.\n");
        }
}