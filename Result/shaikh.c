// radixsort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int find_max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] >= max){
            max = arr[i];
        }
    }

    return max;
} 

void countSort(int arr[], int n, int pos)
{
    //int* count = (int* ) calloc(10, (10*nof(int)));
    int count[10] = {0};
    
    for(int i =0; i<n;i++)
    {
        count[(arr[i]/pos) % 10]++;
    }
    
    for(int i = 1; i<10; i++)
    {
        count[i]+= count[i-1];         // prefix summation
    }

    
    int output[n];
    for(int i = n-1 ; i>=0; i--)
    {
        output[--count[(arr[i]/pos) % 10]] = arr[i];
    }

    for(int i =0; i< n; i++)
    {
        arr[i] = output[i];
    }
}

void RadixSort(int arr[], int n)
{

    int max = find_max(arr, n);

    for(int pos = 1; max/pos > 0; pos*=10)
    {
        countSort(arr,n, pos);
    }

}

int main()
{
    srand(time(0));
    double s_time, e_time;
    int n;
    printf("Enter total number : ");
    scanf("%d", &n);
    int arr[n];    
    
    // int arr[] = {15,32,67,97,14,32,74,44,87,44,65,65};
    //int n = nof(arr)/nof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%n;
        printf("%d\n",arr[i]);
    }
    printf("\n");
    
    s_time = clock();

    RadixSort(arr,n);

    for(int i = 0; i< n; i++)
    {
        printf("%d \n", arr[i]);
    }

    printf("\n");
    e_time = clock();
    printf("%f\n",e_time-s_time);
    //printf("%f",(e_time-s_time)/CLOCKS_PER_SEC);

    return 0;
}