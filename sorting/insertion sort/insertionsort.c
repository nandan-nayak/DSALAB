#include <stdio.h> 
  

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
       
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
  

void print(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
    int a[10];  
    int n,i;
    
    printf("\n enter the size " );
    scanf("%d",&n);
   
    printf("\nenter the contents");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nbefore sorting\n");
    print(a,n);


    insertionSort(a, n); 
  

    printf("\nafter sorting\n");
  print(a, n); 
  
    return 0; 
} 
