#include <stdio.h>

void merge(int A[], int beg, int mid, int end);
void merge_sort_rec(int A[], int beg, int end);
void merge_sort(int A[], int n);

void mergesort(int A[], int n){
    merge_sort_rec(A, 0, n - 1);
}

/*  Merge Sort Helper Functions */
void merge(int A[], int beg, int mid, int end){
    int i = beg, j = mid + 1, index = 0;
    int size = end - beg + 1;
    int temp[size];
    
    while (i <= mid && j <= end) {
        if (A[i] < A[j]) {
            temp[index] = A[i];
            i++;
        } else {
            temp[index] = A[j];
        }
        index++;
    }

    while (i <= mid) {
        temp[index] = A[i];
        i++;
        index++;
    }

    while (j <= end) {
        temp[index] = A[j];
        j++;
        index++;
    }

    for (int k = 0; k < size; k++) {
        A[beg + k] = temp[k];
    }
}

void merge_sort_rec(int A[], int beg, int end){
    int mid;
    if(beg < end){
        mid = (beg + end) / 2;
        merge_sort_rec(A, beg, mid);
        merge_sort_rec(A, mid + 1, end);
        merge(A, beg, mid, end);
    }
}
