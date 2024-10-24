#include <stdio.h>

void selection_sort(int A[] , int n);

void selection_sort(int A[], int n)
{
    for (int i = 0;i < n-1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[minInd])
                minInd = j; 
        
        int temp = A[minInd];
        A[minInd] = A[i];
        A[i] = temp;
    }
}