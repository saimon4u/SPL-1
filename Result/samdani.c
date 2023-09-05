#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void binary_search(long long int arr[],int start,int end,long long int key){
    while(start<=end) {
        int mid = start+(end-start)/2;
        if (arr[mid] == key) {
            printf("Index:%d\n", mid);
            break;
        } else if (arr[mid] > key) end = mid - 1;
        else start = mid + 1;
    }
    if(start>end) printf("Not Found\n");
}

void sort(long long int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                long long int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main()
{


      long long int size,key;
//    scanf("%d",&size);
//    int arr[size];
//    for(int i=0;i<size;i++) scanf("%d",&arr[i]); //must be in sorted order
    int n=100000;
    long long int arr[n];
    for(int i=0;i<n;i++) arr[i]=rand();

    sort(arr,n);
    for(int i=0;i<n;i++) printf("%lld ",arr[i]);
    printf("\n");

    //scanf("%d",&key);
    key=arr[n/4];

    clock_t start_time, end_time;
    double execution_time;

    //start_time=(double)clock();

    binary_search(arr,0,n,key);

    end_time = (double)clock();

    execution_time = (((double)(end_time - start_time))/ CLOCKS_PER_SEC) ;

    printf("Execution time: %f ms\n", (1000.0*execution_time));

    return 0;
}
