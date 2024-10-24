#include <stdio.h>

void heap_sort(int A[] , int n);
void heapify(int A[], int n, int i);
void swap(int *a, int *b);

void heapsort(int A[], int n) {
    // Heapify Original Array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    // Heap Sort 
    for (int i = n - 1; i >= 0; i--){
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}