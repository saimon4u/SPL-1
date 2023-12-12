// quicksort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp ;
}

int partition (int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1 ;
    for (int j = l; j < r; j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, r);
    return i+1;
    
}

void quicksort(int arr[], int l, int r )
{
    if(l<r)
    {
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi-1) ;
        quicksort(arr, pi+1, r) ;
    }
}

 int main()
 {
    double s_time, e_time;
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%n;
        //scanf("%d",&arr[i]);
    }

    s_time =  clock();
    
    quicksort(arr, 0, n-1);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    e_time =  clock();

    //printf("\n%f",(e_time-s_time));
    return 0;
 }