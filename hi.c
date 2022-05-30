#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

int A[10000];
int n, x, i, j, k;
int pivot, median;
int left, right;


void swap(int *a, int *b) {
   int tam = *a;
   *a = *b;
   *b = tam;
}


void FindMedian(int A[],int n, int k)
{
    int L,R,temp;
    L   =   0;
    R   =   n-1;
 
    while(L < R)
    {
        x   =   A[k];
        i   =   L;
        j   =   R;
        while(i < j)
        {
            while (A[i] < x) i++;
            while (A[j] > x) j--;
 
            if(i <= j)
            {
                temp    =   A[i];
                A[i]    =   A[j];
                A[j]    =   temp;
                j++;
                i--;
            }
        }
        if(j < k) L = i;
        if(k < i) R = j;
    }
}


void QuickSort(int A[], int left, int right) { 
pivot = median;
i = left; j = right;
do{
   while(A[i] < A[pivot]) i++;
   while(A[j] > A[pivot]) j--;
   if(i <= j) { 
      swap(&A[i], &A[j]);
      i++;
      j--;
   }
}
while(i <= j);
if(left < j) {
   QuickSort(A, left, j); }
if(i < right) {
   QuickSort(A, i, right); }
}

int main() {
   do {
   printf("HAY NHAP SO PHAN TU TRONG MANG A: \n");
   scanf("%d", &n);
   } while(n < 2 );
   for(int i = 0; i < n; i ++) {
      printf("NHAP A[%d]: \n", i); 
      scanf("%d",&A[i]); 
   }
   printf("MANG A:\n");
   for(int i = 0; i < n; i++) {
      printf(" %d ",A[i]);
      }
   FindMedian(A, n, n/2);
   median=A[n/2];
   printf("MEDIAN = %d \n", median);
   printf("\nMANG A SAU KHI SAP XEP: \n");
   QuickSort(A, 0, n);
   for(int i = 0; i < n; i++) {
      printf(" %d ",A[i]);
      }
return 0;
}