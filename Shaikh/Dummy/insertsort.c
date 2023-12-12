// insertsort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap( int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp ;
}

int main()
{
    double s_time, f_time;
    
    int n, i, j, temp;
    scanf("%d",&n);
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        arr[i] = rand()%(n+100);
        printf("%d ",arr[i]);
    }
    
    s_time = clock();

    for ( i = 1; i < n; i++)
    {
        temp = arr[i];
        for ( j = i-1 ; arr[j] > temp && j >=0; j-- )
        {
            arr[j+1]=arr[j];

        }
        arr[j+1] = temp;
    }
    
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    f_time = clock();
    
    printf("\n%f",f_time-s_time);
    
}