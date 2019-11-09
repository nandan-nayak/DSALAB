#include<stdio.h> 


void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  

int partition (int a[], int low, int high) 
{ 
    int pivot = a[high];    
    int i = (low - 1);  
    for (int j = low; j <= high- 1; j++) 
    { 
       
        if (a[j] < pivot) 
        { 
            i++;    
            swap(&a[i], &a[j]); 
        } 
    } 
    swap(&a[i + 1], &a[high]); 
    return (i + 1); 
} 
  

void quickSort(int a[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int p = partition(a, low, high); 
  
        quickSort(a, low, p - 1); 
        quickSort(a, p + 1, high); 
    } 
} 
  

void print(int a[], int n) 
{ 
    int i; 
    for (i=0; i < n; i++) 
        printf("%d ", a[i]); 
    printf("\n"); 
} 
  

void main() 
{ 
    int a[10]; 
    int n,i;

    printf("\nenter the size  ");
    scanf("%d",&n);

    printf("\nenter the contents ");
    
    for (i=0; i < n; i++) 
        scanf("%d",&a[i]); 

    printf("\nbefore sorting\n");
     print(a,n);

    quickSort(a, 0, n-1); 
    printf("\nafter sorting\n"); 
    print(a, n); 
    
} 
