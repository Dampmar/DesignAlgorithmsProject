#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define SIZE 200000

int arr[SIZE];
const int size = SIZE;

typedef void (*SortFunction)(int[], int);

// Functions
void selection_sort(int A[], int n);
void merge_sort(int A[], int n);
void heap_sort(int A[], int n);

// Helper functions
void ArrayRandomNumbers();
void check_unsorted(int A[], int n);
double measureSortTime(SortFunction func, int arr[], int n);
void merge(int A[], int beg, int mid, int end);
void merge_sort_rec(int A[], int beg, int end);
void heapify(int A[], int n, int i);
void swap(int *a, int *b);

int main(void) {
    double exe_time;
    // Measuring time for Selection Sort 
    for (int i = 0; i < 3; i++) {
        printf("Generating random numbers in array.\n");
        ArrayRandomNumbers();
        printf("Executing algorithm.\n");
        exe_time = measureSortTime(selection_sort, arr, size);
        printf("Execution Time of Selection Sort (%d size): %.6lf s\n", size, exe_time);
    }

    // Measuring time for Merge Sort
    for (int i = 0; i < 3; i++) {
        printf("Generating random numbers in array.\n");
        ArrayRandomNumbers();
        printf("Executing algorithm.\n");
        exe_time = measureSortTime(merge_sort, arr, size);
        printf("Execution Time of Merge Sort (%d size): %.6lf s\n", size, exe_time);
    }

    // Measuring time for Heap Sort
    for (int i = 0; i < 3; i++) {
        printf("Generating random numbers in array.\n");
        ArrayRandomNumbers();
        printf("Executing algorithm.\n");
        exe_time = measureSortTime(heap_sort, arr, size);
        printf("Execution Time of Heap Sort (%d size): %.6lf s\n", size, exe_time);
    }

    return 0;
}

void ArrayRandomNumbers() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

double measureSortTime(SortFunction func, int arr[], int n) {
    clock_t start, end;
    start = clock();
    func(arr, n);
    end = clock();
    check_unsorted(arr, n);
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void check_unsorted(int A[], int n) {
    for (int i = 1; i < n; i++)
        if (A[i - 1] > A[i]) {
            printf("Unsorted.\n");
        }
}

void selection_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[minInd])
                minInd = j;
        swap(&A[minInd], &A[i]);
    }
}

void merge(int A[], int beg, int mid, int end) {
    int i = beg, j = mid + 1, index = 0;
    int size = end - beg + 1;
    int* temp = (int*)malloc(size * sizeof(int));  // Dynamically allocate temp array
    
    if (!temp) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    
    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            temp[index++] = A[i++];
        } else {
            temp[index++] = A[j++];
        }
    }
    
    while (i <= mid) {
        temp[index++] = A[i++];
    }
    
    while (j <= end) {
        temp[index++] = A[j++];
    }
    
    for (i = 0; i < size; i++) {
        A[beg + i] = temp[i];
    }
    
    free(temp);  // Free the allocated memory
}

void merge_sort_rec(int A[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        merge_sort_rec(A, beg, mid);
        merge_sort_rec(A, mid + 1, end);
        merge(A, beg, mid, end);
    }
}

void merge_sort(int A[], int n) {
    merge_sort_rec(A, 0, n - 1);
}

void heap_sort(int A[], int n) {
    // Heapify Original Array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    // Heap Sort
    for (int i = n - 1; i >= 0; i--) {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);
    }
}

/* Helper functions for heap sort */
void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && A[left] > A[largest])
        largest = left;
    if (right < n && A[right] > A[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
