//
//
//  Matrisin satırındaki elemanları diziye aktarıp sıralayan program
//
//

#include <stdio.h>
#include <stdlib.h>
#define N 3

void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void insertionSort(int arr[], int n) { 
   int i, key, j; 
   for (i = 1; i < n; i++) { 
       key = arr[i]; 
       j = i-1; 
       while (j >= 0 && arr[j] > key) { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
}

void selectionSort(int arr[], int n) { 
    int i, j, min_idx; 
  
    for (i = 0; i < n-1; i++) { 
        min_idx = i; 
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]); 
    } 
}

void bubbleSort(int arr[], int n) { 
   int i, j; 
    for (i = 0; i < n-1; i++) {  
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) { 
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int i = 0;
    int j = 0;
    int row_number = 0;
    int temp, min;
    int matris[N][N] = {{5, 3, 2}, {1, 2, 5}, {6, 1, 2}};
    int d[N];
    printf("Kacinci satir?");
    scanf("%d", &row_number);

    for(int i = 0; i < N; i++)
    {
        d[i] = matris[row_number-1][i];
    }
    
    insertionSort(d, N);
    selectionSort(d, N);
    bubbleSort(d, N);

    return 0;
}
